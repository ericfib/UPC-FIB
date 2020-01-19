all: listaParametros numeros suma

listaParametros: listaParametros.c
	gcc -o  listaParametros listaParametros.c

numeros: numeros.c
	gcc -o numeros numeros.c

suma: suma.o mis_funciones.o
	gcc -o suma suma.o mis_funciones.o

suma.o: suma.c
	gcc -c suma.c

mis_funciones.o: mis_funciones.c mis_funciones.h
	gcc -c mis_funciones.c -I .

clean:
	rm *.o
	rm -f suma numeros listaParametros
