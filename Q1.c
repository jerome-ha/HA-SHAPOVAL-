#include "functions.h"

int main(){
	write(STDOUT_FILENO, Message, strlen(Message));
	write(STDOUT_FILENO, PROMPT, strlen(PROMPT));
	return 0;}
