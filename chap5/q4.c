#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>

int main() {
	pid_t pid;
	pid = fork();

	if(pid==-1){
		perror("process_not_created\n");
	} else if(pid==0) {
		char * myargs[3];
		myargs[0] = "/bin";
		myargs[1] = "ls";
		myargs[2] = NULL;

		execv(myargs[0], myargs);
	} else {
		int status;
		status = waitpid(-1, NULL, 0);
		if(status==0){
			printf("child_process_terminated_properly\n");
		} else {
			printf("terminated_error");
		}
	}
}
