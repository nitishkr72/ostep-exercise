#include <stdio.h>
#include <stdlib.h>

#define MEM_SIZE 1024*1024

int main(int argc, char ** argv) {
	if (argc <= 1)
		exit(0);
	int mem_val = atoi(argv[1]);
	char *memUsage;
	memUsage = (char *)malloc(sizeof(char)*mem_val*MEM_SIZE);
	for(int i=0;i<mem_val*MEM_SIZE;i++)
		memUsage[i] = '0';
	//while(2);

	return 0;
}
