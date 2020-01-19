#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>



int main(int argc, char *argv[]) {

  char c;

  int fifo =  open("pipa", O_WRONLY);

  if (fifo == -1) {
    perror("error creando pipe");
    exit(0);
  }else{
    int ret = read(0, &c, sizeof(char));

    while(ret > 0) {

      write(fifo, &c, sizeof(char));
    }
  }

}
