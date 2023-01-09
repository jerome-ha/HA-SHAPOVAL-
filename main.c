#include "functions.h"



int main(){
	write(STDOUT_FILENO, Message, strlen(Message));
	PROMPT1
	char buf[SIZE];
	char buf_exit[SIZE_exit];
	int waiting=1;
	int count;
	while(waiting){
		int pid, status;

		int length=read(STDIN_FILENO, buf, SIZE);
		char* chain=malloc(length*sizeof(char));
		int i=0;
		for (i=0; i<length-1;i++){
			chain[i]=buf[i];
			}
		if (strncmp(chain,"exit",4)==0){
			write(STDOUT_FILENO, "Bye bye...\n", strlen("Bye bye...\n"));
			exit(EXIT_SUCCESS);}
		pid=fork();
		
		if (pid!=0){
			struct timespec tp0, tp1;
			clock_gettime(CLOCK_REALTIME, &tp0);
			wait(&status);
			clock_gettime(CLOCK_REALTIME, &tp1);
			long duration = (tp1.tv_nsec - tp0.tv_nsec)/1000000;
			if (WIFEXITED(status)) {
				sprintf(buf_exit, "enseash [exit:%d|%d ms] %% ",  WEXITSTATUS(status),duration);
				write(STDOUT_FILENO, buf_exit, strlen(buf_exit));
			} else if  (WIFSIGNALED(status)) {
				sprintf(buf_exit, "enseash [sign:%d|%d ms] %% ",  WTERMSIG(status),duration);
				write(STDOUT_FILENO, buf_exit, strlen(buf_exit));
			} else	{
				PROMPT1 }
		}
		else {
			execlp(chain,chain,(char*) NULL);
			exit(EXIT_FAILURE);}
		}
	return 0;
		
	}
			
		
