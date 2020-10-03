#include <stdio.h>
#include <wait.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
	pid_t pid;
	pid = fork();
	if(pid==-1){
		printf("file_not_open\n");
	} else if(pid==0){
		printf("hello\n");
	} else {
		int status;
		status = waitpid(-1, NULL, 0);
		if(status==0){
			printf("child_process_terminated_properly\n");
		} else {
			printf("child_process_terminated_error\n");
		}
		printf("goodbye\n");
	}
	return 0;
}
