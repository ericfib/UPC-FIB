#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>


int main(int argc, char *argv[]){

  char c;

  int fifo = open("pipa", O_RDONLY);

  if (fifo == -1){
      perror("amodjepifowfo");
      exit(0);
  }else{
    int ret = read(fifo, &c, sizeof(char));

    while(ret > 0){
      write (1, &c, sizeof(char));
    }
  }

}
