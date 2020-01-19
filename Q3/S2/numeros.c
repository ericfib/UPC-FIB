#include<unistd.h>
#include<stdio.h>
#include<string.h>

int esNumero(char *str)
{
    int i = 0;
    if (str[i] == '-') ++str;
    for(; str[i] != '\0'; ++i){
      if (str[i] < '0' || str[i] > '9') return 0;
    }
    return (i > 0) && (i <= 8);
}


int main (int argc, char *argv[]) {
  for(int k = 1; k < argc; k++){
    if (esNumero(argv[k])){
      write(1, "Es numero\n", 10);
    }else{
      write(1, "No es numero\n", 13);
    }
  }
}
