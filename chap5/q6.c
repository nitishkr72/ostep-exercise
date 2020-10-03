#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
	pid_t pid;
	pid = fork();
	if(pid==-1){
		printf("error\n");
	} else if(pid==0){
		int status;
		status = waitpid(-1, NULL, 0);
		if(status==0)
			printf("my_child_process_properly_terminated\n");
		else
			printf("error_occured\n");
		//printf("status:: %d\n", status);
	} else {
		printf("in parent::\n");
	}
	return 0;
}
