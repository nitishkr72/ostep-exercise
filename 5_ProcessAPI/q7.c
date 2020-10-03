#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
	pid_t pid;
	pid = fork();
	if(pid==-1){
		printf("error_occured\n");
	} else if(pid==0){
		//close(STDOUT_FILENO);
		printf("hey fd0 closes\n");
		char * args[2];
		args[0] = "ls";
		args[1] = NULL;
		execvp(args[0], args);
	} else {
		printf("hey unique\n");
	}

	return 0;
}
