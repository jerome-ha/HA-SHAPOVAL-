#include "functions.h"

int main(){
	write(STDOUT_FILENO, Message, strlen(Message));
	write(STDOUT_FILENO, PROMPT, strlen(PROMPT));
	
	char test[128];
	
	time_t rawtime ;
	struct tm * timeinfo;
	time(&rawtime);
	timeinfo = localtime (&rawtime);
	
	while(1){
		read(STDIN_FILENO,test,128);
		if (strcmp(test,"fortune")==10){
			write(STDOUT_FILENO, Message1, strlen(Message1));
		}
		else if (strcmp(test,"date")==10){
			write(STDOUT_FILENO, asctime(timeinfo), strlen(asctime(timeinfo)));
		}
			
		else if (strcmp(test,"exit")==10){
			write(STDOUT_FILENO, "Bye bye...\n", strlen("Bye bye...\n"));
			break;
		}
		write(STDOUT_FILENO, PROMPT, strlen(PROMPT));
	}
	
	return 0;}
