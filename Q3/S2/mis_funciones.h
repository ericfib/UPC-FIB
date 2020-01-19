#ifndef MIS_FUNCIONES_H
#define MIS_FUNCIONES_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>



int esNumero (char *c);
//pre: cierto
//post: devuelve 1 si el parametro es un numero y tiene 8 cifras como mucho

int mi_atoi(char *s);
//pre: cierto
//post: devuelve s transformado a integer

int char2int (char c);
//pre: '0'<= c <= '9'
//post: transforma c en integer


#endif
