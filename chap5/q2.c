#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int sz;
	int fd = open("input.txt", O_WRONLY | O_CREAT);
	if(fd==-1){
		printf("ERROR::file_not_open\n");
	} else {
		pid_t pid;
		pid = fork();
		if(pid==-1){
			printf("ERROR::process_not_crested\n");
		} else if(pid==0){
			printf("CHILD:: PID: %d\n", getpid());
			sz = write(fd, "written by child process\n", strlen("written by child process\n"));
		} else {
			printf("PARENT:: PID: %d, CHILD.PID: %d", getpid(), pid);
			sz = write(fd, "written by parent process\n", strlen("written by parent process\n"));
		}
	}
	close(fd);
}
