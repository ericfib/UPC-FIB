#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>

#define REGION_SIZE		4096



void funcion_segmentation (int signal)
{
	perror("escribiste donde no tocaba weon conchetumadre");
	exit(0);
}

int *p;

int main(int argc, char *argv[])
{
	struct sigaction sa;
	sigset_t mask;

	sa.sa_handler = &funcion_segmentation;
	sa.sa_flags = SA_RESTART;
	sigaction(SIGSEGV, &sa, NULL);


	char buff[256];

	sprintf( buff, "Addresses:\n");
	write(1, buff, strlen(buff));
	sprintf( buff, "\tp: %p\n", &p);
	write(1, buff, strlen(buff));

	*p = 5;

	sprintf( buff, "\tp Address: %p, p value: %p, *p: %d\n", &p, p, *p);
	write(1, buff, strlen(buff));

	exit(0);

}
