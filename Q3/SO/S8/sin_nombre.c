#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main(int arcg, char * arvg[])
{
	int chan[2];
	int p = pipe(chan);       //  padre ->  3 ======== 4  -> hijo -> cat

	int pid = fork();
	if (pid == 0)
	{
		dup2(chan[0], 0);
		close(chan[0]);
		close(chan[1]);
		execlp("cat", "cat", NULL);
	}
	else if (pid > 0)
	{
		char texto[30];
		sprintf(texto, "hola amigo jaja\n");
		int wrt = write(chan[1], texto, strlen(texto));

		close(chan[1]);
		waitpid(-1, 0, 0);
		printf("it's over\n");
	}
}
