#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <signal.h>
#include <unistd.h>

//#include "csapp.h"
//#include "csapp.c"

void handler1(int sig)
{
	int olderrno = errno;
	
	if ((waitpid(-1, NULL, 0)) < 0)
		printf("wait error");
	fprintf("handler repeated child \n");
	sleep(1);
	errno = olderrno;
	
}

void handler2(int sig)
{
	int olderrno = errno;
	
	while ((waitpid(-1, NULL, 0)) < 0)
		printf("wait error");
	printf("handler repeated child \n");
	sleep(1);
	errno = olderrno;
	
}


int main()
{
	if (signal(SIGCHLD, handler1) == SIG_ERR)
		fprintf(stderr, "find error");
	int i = 1,n;
	char buf[100];
	for (i; i < 3; i++) {
		if (fork() == 0) {// child
			printf("hello from child %d\n", (int)getpid());
			exit(0);
		}	
	}	
	
	if ((n = read(STDIN_FILENO, buf, sizeof(buf)))<0)
		fprintf(stderr, "read");

	printf("parent processing input");
	while (1)  ;
	exit(0);
}
