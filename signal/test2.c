#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <errno.h>

void sigint_handler(int sig)
{
	printf("caught signal\n");
	exit(0);
}

int main()
{
	/*
	if (signal(SIGINT, sigint_handler) == SIG_ERR)
	{
	//	fprintf(strerr,"error\n");
	}
	*/

	//pause();
	//×èÈûĞÅºÅ
	sigset_t mask, pre_mask;
	
	sigemptyset(&mask);
	sigaddset(&mask, SIGINT);
	
	//Ìí¼Ó×èÈûĞÅºÅ
	sigprocmask(SIG_BLOCK, &mask, &pre_mask);
	
	sleep(10);
	sigprocmask(SIG_SETMASK, &pre_mask, NULL);
	return 0;
}
