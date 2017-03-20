#include "csapp.h"
void myhandler() {
}



void mysleep(int secs) {
	int les = sleep(secs);
	
	printf("slept for %d of %d secs\n",secs,secs-les);
}


int main(int argc,char **argv) {
	int secs = atoi(argv[1]);//÷–∂œ ±º‰
	//int les = mysleep(secs);
	if (signal(SIGINT,myhandler) == SIG_ERR)	unix_error("signal error");
	mysleep(secs);
}
