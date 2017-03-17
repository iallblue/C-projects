#include "csapp.h"

void echo (int connfd);
int main(int argc,char **argv) {
	
	int listenfd,connfd;
	socklen_t clientlen;
	struct sockaddr_storage clientaddr;
	char client_hostname[MAXLINE],client_port[MAXLINE];
	
	if (argc != 2) {
		printf("error!!!\n ");
		exit(0);
	}
	
	listenfd = Open_listenfd(atoi(argv[1]));
	while (1) {
		clientlen = sizeof(struct sockaddr_storage);
		connfd = Accept(listenfd,(SA *)&clientaddr,&clientlen);
		getnameinfo((SA *)&clientaddr,clientlen,client_hostname,MAXLINE,client_port,MAXLINE,0);
		printf("Connect to11 (%s %s)\n",client_hostname,client_port);
		echo(connfd);
		Close(connfd);
	}
	exit(0);
}

void echo (int connfd) {
	size_t n;
	char buf[MAXLINE];
	char myword[100] = "i come from the big earth\n";
	char tmp[100] = "-from server response:";
	rio_t rio;

	Rio_readinitb(&rio,connfd);
	while ((n = Rio_readlineb(&rio,buf,MAXLINE)) != 0) {
		printf("server received %d bytes\n",(int)n);
		//合并两个数组
		//buf[1] = 'A';
		//strcpy(buf,tmp);
		//Rio_writen(connfd,buf,n);
		Rio_writen(connfd,myword,100);
	}
}
