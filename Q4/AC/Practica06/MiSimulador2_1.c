#include "CacheSim.h"

/* Posa aqui les teves estructures de dades globals
 * per mantenir la informacio necesaria de la cache
 * */

typedef struct {
	int bloc;
	int dirty;
} cache;

cache Cache[128];

int acierto;
int fallo;

/* La rutina init_cache es cridada pel programa principal per
 * inicialitzar la cache.
 * La cache es inicialitzada al comen�ar cada un dels tests.
 * */
void init_cache ()
{
	/* Escriu aqui el teu codi */
	for (int i = 0; i < 128; i++) {
		Cache[i].bloc = -1;
		Cache[i].dirty = 0;
	}

	acierto = 0;
	fallo = 0;
}

/* La rutina reference es cridada per cada referencia a simular */
void reference (unsigned int address, unsigned int LE)
{
	unsigned int byte;
	unsigned int bloque_m;
	unsigned int linea_mc;
	unsigned int tag;
	unsigned int miss;
	unsigned int lec_mp;
	unsigned int mida_lec_mp;
	unsigned int esc_mp;
	unsigned int mida_esc_mp;
	unsigned int replacement;
	unsigned int tag_out;

	/* Escriu aqui el teu codi */

	byte = address%32;
	bloque_m = address/32;
	linea_mc = bloque_m%128;
	tag = bloque_m/128;
	tag_out = -1;

	lec_mp = 0;
	mida_esc_mp = 0;
	mida_lec_mp = 0;
	esc_mp = 0;

	miss = 0;
	replacement = 0;

	if (!LE) {
		//LECTURA
		if (Cache[linea_mc].bloc == -1) { //NO REPLACEMENT
			miss = 1;
			replacement = 0;
			tag_out = -1;
			Cache[linea_mc].bloc = tag;
			lec_mp = 1;
			mida_lec_mp = 32;
			esc_mp = 0;
			mida_esc_mp = 0;
			fallo++;
		}
		else if (Cache[linea_mc].bloc != -1 && Cache[linea_mc].bloc != tag) { //REPLACEMENT
			miss = 1;
			replacement = 1;
			lec_mp = 1;
			mida_lec_mp = 32;

			if (Cache[linea_mc].dirty == 1) {
				esc_mp = 1;
				mida_esc_mp = 32;
				Cache[linea_mc].dirty = 0;
			} else {
				esc_mp = 0;
				mida_esc_mp = 0;
			}
			tag_out = Cache[linea_mc].bloc;
			Cache[linea_mc].bloc = tag;
			fallo++;
		}
		else{
			miss = 0;
			replacement = 0;
			lec_mp = 0;
			esc_mp = 0;
			mida_esc_mp = 0;
			mida_lec_mp = 0;
			acierto++;
		}
	}else{
		//ESCRITURA
		if (Cache[linea_mc].bloc == -1) { //REPLACEMENT
			miss = 1;
			replacement = 0;
			tag_out = -1;
			Cache[linea_mc].bloc = tag;
			lec_mp = 1;
			mida_lec_mp = 32;
			esc_mp = 0;
			mida_esc_mp = 0;
			Cache[linea_mc].dirty = 1;
			fallo++;
		}
		else{
			if (Cache[linea_mc].bloc != tag) { //NO REPLACEMENT
				miss = 1;
				replacement = 1;
				lec_mp = 1;
				mida_lec_mp = 32;

				if (Cache[linea_mc].dirty == 1) {
					esc_mp = 1;
					mida_esc_mp = 32;
				} else {
					esc_mp = 0;
					mida_esc_mp = 0;
				}
				tag_out = Cache[linea_mc].bloc;
				Cache[linea_mc].bloc = tag;
				Cache[linea_mc].dirty = 1;
				fallo++;
			}
			else{
				miss = 0;
				replacement = 0;
				lec_mp = 0;
				esc_mp = 0;
				mida_esc_mp = 0;
				mida_lec_mp = 0;
				Cache[linea_mc].dirty = 1;
				acierto++;
			}

		}
	}

	/* La funcio test_and_print escriu el resultat de la teva simulacio
	 * per pantalla (si s'escau) i comproba si hi ha algun error
	 * per la referencia actual
	 * */
	test_and_print (address, LE, byte, bloque_m, linea_mc, tag,
			miss, lec_mp, mida_lec_mp, esc_mp, mida_esc_mp,
			replacement, tag_out);
}

/* La rutina final es cridada al final de la simulacio */
void final ()
{
 	/* Escriu aqui el teu codi */
	printf("he hecho %d aciertos", acierto);
	printf("he hecho %d fallos", fallo);

}
