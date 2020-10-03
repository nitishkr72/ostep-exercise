#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>
int main() {
	int x = 100;
	printf("ADDRESS:: x: %p\n", &x);
	pid_t pid;
	pid = fork();
	if(pid==-1){
		printf("new process not created");
	}else if(pid==0){
		printf("CHILD:: PID_VALUE: %d\n", getpid());
		x++;
		printf("in CHILD::incrementing x:: %d address:: %p\n", x, &x);
	} else {
		printf("PARENT:: PID_VALUE: %d, child_pid: %d\n", getpid(), pid);
		x = x-1;
		printf("in PARENT::decrementing x:: %d address:: %p\n", x, &x);
	}

	printf("x = %d", x);
	return 0;
}
