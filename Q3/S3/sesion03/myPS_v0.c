#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

void error_y_exit(char *msg, int exit_status)
{
	perror(msg);
	exit(exit_status);
}

void muta_a_PS (char *username)
{
	execlp("ps", "ps", "-u", (char*) NULL);
	error_y_exit("Ha fallado la mutación al ps", 1);
}

int main(int argc,char *argv[])
{
	char buffer[69];
	int pid;
	int i =0;

	if ((pid=fork())<0) error_y_exit("Error en fork",1);

	else if (pid == 0)
	{
		sprintf(buffer, "%d %s Son\n",getpid(), argv[1]);
		write(1, buffer, strlen(buffer));

		muta_a_PS(argv[1]);
	}
	else
	{
		sprintf(buffer, "%d Padre\n",getpid());
		write(1, buffer, strlen(buffer));
	}
	while(1) ++i;
}
