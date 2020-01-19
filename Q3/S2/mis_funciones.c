#include "mis_funciones.h"

int esNumero(char *str)
{
	  if (str){
			int i = 0;
	    if (str[i] == '-') ++str;
	    for(; str[i] != '\0'; ++i){
	      if (str[i] < '0' || str[i] > '9') return 0;
	    }
	    return (i > 0) && (i <= 8);
		}
		return 0;
}


int mi_atoi(char *s)
{
	int res = 0, sign = 1;
	while (*s == '-' || *s == '+') {
		if (*s == '-') sign = 0;
		s++;
	}

	while (*s == '\n' || *s == ' ' || *s == '\t' || *s == '\r' ||
		*s == '\v' || *s == '\f'){
		++s;
	}
	while (*s >= '0' && *s <= '9'){
		res *= 10;
		res = (sign ? res + char2int(*s) : res - char2int(*s));
		s++;
	}
	return res;
}


int char2int(char c)
{
	return (c - '0');
}
