#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

void error_y_exit(char *msg, int exit_status)
{
	perror(msg);
	exit(exit_status);
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
	}
	else
	{
		sprintf(buffer, "%d Padre\n",getpid());
		write(1, buffer, strlen(buffer));
	}
	while(1) ++i;
}
