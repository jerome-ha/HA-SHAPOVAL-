#include "functions.h"

// first session we didn't program the shell but did each question as a write and we programmed function fortune and date.
// Program works for Q1 to Q6, Prep code was made for Q7 to Q9.


int main(){
	write(STDOUT_FILENO, Message, strlen(Message)); // Q1
	PROMPT1 // Q1 for the first "enseash %"
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
			
		char* fileStdInQ7=strstr(chain, "<");	// Detect "<" for Q7
    		char* fileStdOutQ7=strstr(chain, ">");	// Detect ">" for Q7
    		char* pipeRedirectionQ8=strstr(chain, "|");	// Detect "|" for Q8
    		char* backgroundExecQ9=strstr(chain, "&");	// Detect "&" for Q9
		
		if (strncmp(chain,"exit",4)==0){
			write(STDOUT_FILENO, "Bye bye...\n", strlen("Bye bye...\n"));
			exit(EXIT_SUCCESS);
		} // simple loop for Q3

		
		pid=fork();
		
		if (pid!=0){
			struct timespec tp0, tp1;	//for Q5
			clock_gettime(CLOCK_REALTIME, &tp0);
			wait(&status);
			clock_gettime(CLOCK_REALTIME, &tp1);
			long duration = (tp1.tv_nsec - tp0.tv_nsec)/1000000;	//for Q5
			if (WIFEXITED(status)) {	//for Q4 exit
				sprintf(buf_exit, "enseash [exit:%d|%d ms] %% ",  WEXITSTATUS(status),duration);	//for Q4, Q5
				write(STDOUT_FILENO, buf_exit, strlen(buf_exit));
			} else if  (WIFSIGNALED(status)) {	//for Q4 signal
				sprintf(buf_exit, "enseash [sign:%d|%d ms] %% ",  WTERMSIG(status),duration);		//for Q4, Q5
				write(STDOUT_FILENO, buf_exit, strlen(buf_exit));
			} else	{
				PROMPT1 }
		}
		else {
			execlp(chain,chain,(char*) NULL);
			exit(EXIT_FAILURE);}
		} // This answers Q2, Q6 implicitely.
	return 0;
		
	}
			
		
