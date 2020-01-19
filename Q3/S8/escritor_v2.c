#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>



int main(int argc, char *argv[]) {

  char c;
  char buff[256];

  int fifo =  open("pipa", O_WRONLY | O_NONBLOCK);

  while (fifo == -1 && error == ENXIO){
    sprintf(buff, "waiting for reader\n");
    write(1,buff, strlen(buff));
    sleep(2);
  }

  sprintf(buff, "Reader found!\n");
	write(1, buff, strlen(buff));

  int ret = read(0, &c, sizeof(char));

  while(ret > 0) {

  write(fifo, &c, sizeof(char));
    }
  }

}
