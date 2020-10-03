#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>

int main() {
	int status;
	struct timeval gettime;
	status = gettimeofday(&gettime, NULL);
	time_t t = gettime.tv_sec;
	printf("%ld, status: %d\n", t, status);

	return 0;
}
