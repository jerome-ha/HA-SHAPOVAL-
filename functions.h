#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h>



#define Message "Welcome to ENSEA Tiny Shell.\n Pour quitter, tapez 'exit'.\n"
#define PROMPT1 {write(STDOUT_FILENO, "enseash % ", strlen("enseash % "));}
#define Message1 "[Today is what happened to yesterday.] \n"
#define Message2 "ERROR.\n"
#define SIZE 4096
#define SIZE_exit 1024
