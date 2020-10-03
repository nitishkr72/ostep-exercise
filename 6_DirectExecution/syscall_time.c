#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/time.h>
#include <stdlib.h>

int main() {
	pid_t pid;
	struct timeval gettime;
	gettimeofday(&gettime, NULL);
	
	time_t s1, s2;
	suseconds_t us1, us2;

	s1 = gettime.tv_sec;
	us1 = gettime.tv_usec;

	pid = fork();

	s2 = gettime.tv_sec;
	us2 = gettime.tv_usec;

	if(pid<0) exit(1);
	else if(pid==0) exit(0);
	else {
		printf("start:sec %ld, microsec %ld\n", s1, us2);
		printf("last:sec %ld, microsec %ld\n", s2, us2);
	}

	exit(0);
}
