#include "functions.h"

int main(){
	scanf("%s", &command);
	if command=="fortune"{
		write(STDOUT_FILENO, Message1, strlen(Message1));
	}
	else {
		write(STDOUT_FILENO, Message2, strlen(Message2));
	}
	write(STDOUT_FILENO, PROMPT, strlen(PROMPT));
}
	
	
