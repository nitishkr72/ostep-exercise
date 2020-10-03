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
		status = wait(NULL);
		printf("status:: %d\n", status);
	} else {
		printf("in parent::\n");
	}
	return 0;
}
