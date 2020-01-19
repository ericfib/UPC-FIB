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
	for (int k = 0; k < argc; k++) {
		char buffer[69];
		int pid;
				if ((pid=fork())<0){
					sprintf(buffer, "Ha fallado el fork del proceso: %d\n", getpid());
					error_y_exit(buffer,1);
				}

				else if (pid == 0)
				{
					sprintf(buffer, "%d %s Son\n",getpid(), argv[k]);
					write(1, buffer, strlen(buffer));
				}
				else
				{
					sprintf(buffer, "%d Padre\n",getpid());
					write(1, buffer, strlen(buffer));
				}
	}
	while (waitpid(-1, NULL, 0) > 0);
	char c;
	read(1,&c,sizeof(char));
}
