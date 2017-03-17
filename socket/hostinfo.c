#include "csapp.h"

int main(int argc,char **argv) {
	struct addrinfo *p,*listp,hints;
	char buf[MAXLINE];
	int rc,flags;
	
	if (argc != 2) {
		printf("errore!!!!!!\n");
		exit(0);
	}
	
	memset(&hints,0,sizeof(struct addrinfo));//内存空间的初始化
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	
	if ((rc = getaddrinfo(argv[1],NULL,&hints,&listp)) != 0) {
		printf("error2222\n");
		exit(1);
	}
	
	flags = NI_NUMERICHOST;
	for (p = listp;p; p = p->ai_next) {
		getnameinfo(p->ai_addr,p->ai_addrlen,buf,MAXLINE,NULL,0,flags);
		printf("%s\n",buf);
	}
	
	//释放内存
	freeaddrinfo(listp);
	exit(0);
}
