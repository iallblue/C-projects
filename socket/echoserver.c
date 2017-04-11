#include "sockethelp.c"
#include <signal.h>

/********************************************************************
 *
 *
 *	socket相关的辅助函数，可以直接使得客户端连接上，或者服务端开启监听
 * 
 *
 ********************************************************************/



//注意当双发建立连接后，客户端是通过clientfd进行和服务端通信的，服务端是通过connfd和客户端通信的
void dothing(int connfd)
{
	size_t n;
	char buf[MAXLINE];
	char send_buf[MAXLINE];
	my_rio_t rio; //类似于文件描述符

	//(已连接)文件描述符和rio 绑定，便于读取信息
	my_rio_readinitb(&rio, connfd);


	//此时的设计为当客户端发送消息后就给客户端回复一条消息
	//读取客户端发来的信息(此时已经将connfd的读取转换为 对rio的读取，这样读更加强壮)
	
	
	while ((n = my_rio_readlineb(&rio,buf, MAXLINE )) != 0)
	{
		printf("server received %d bytes \n", n);
		//清空缓冲区
		sprintf(send_buf,"you send: %s", buf);
		//给客户端发送信息
		my_writen(connfd, send_buf,strlen(send_buf));
		//my_writen(connfd, buf, count);
		
	}
	
	//int i = 0;

	/**
	while (1)
	{
		//当客户端连接上服务端时，就输出信息
		//printf("i am sleep\n");
		//字符数组的赋值操作
		sprintf(send_buf, "\nbye ~~~~");
		my_writen(connfd, send_buf, strlen(send_buf));
		//	sleep(1);
		//	i++;
		//	exit(0);
		//sleep(3);
	}	
	*/
}

/*
//包含有错误处理的accept()
int Accept(int listenfd, struct sockaddr *addr, socklen_t *addrlen)
{
	int rc;
	char *err = "unix_error";
	if ((rc = accept(listenfd, addr, addrlen)) < 0)
	{
		fprintf(stderr, "%s : %s\n", err, strerror(errno));
		exit(0);
	}
	return rc;
}
*/

//信号处理程序
void sigchld_handler(int sig)
{

	//回收多个僵死的子进程
	while (waitpid(-1, 0, WNOHANG) > 0)
		;
	return;
}

int main()
{	
	int clientfd,listenfd,connfd; //connfd 是连接描述符
	char *hostname, *port, client_port[MAXLINE], client_hostname[MAXLINE];	

	//服务端需要的参数
	socklen_t clientlen; //客户端套接字长度
	struct sockaddr_storage clientaddr;//没有声明为sockaddr_in 因为sockaddr_storage是一个更加通用的套接字结构
		
	
	//hostname = "www.baidu.com";
	//更好的处理是将port转换为数字，字符串容易出现bug
	port = "8088";
	//客户端使用的clientfd
	//clientfd = open_clientfd(hostname, port);

	//----------------- 测试服务器 ---------------
	//监听描述符
	listenfd = Open_listenfd(port);

	//----------------------------------------------
	//	更改为多进程
	//----------------------------------------------
	
	//信号处理程序
	signal(SIGCHLD, sigchld_handler);	

	while (1)
	{
		clientlen = sizeof(struct sockaddr_storage); 
		//------------------------------ 注意struct sockaddr * ---------------------------
		//connfd = accept(listenfd, (struct sockaddr *)&clientaddr, &clientlen);
		
		//显示监听提示信息
		printf("Listen port: %s \n",port);

		//包含有错误处理的函数(可用80端口测试)
		connfd = Accept(listenfd, (struct sockaddr *)&clientaddr, &clientlen);
		//printf("%d", connfd);
		//exit(1);

		if (fork() == 0)
		{
			//子进程关闭监听描述符
			close(listenfd);
			//获得客户端连接的套接字信息
			//int res = getnameinfo((struct sockaddr *) &clientaddr, clientlen, client_hostname, MAXLINE, client_port, MAXLINE, 0);
			//服务端显示连接信息
			//printf("getnameinfo_id :%d client: %s, port: %s connected \n",res, client_hostname, client_port);			
		
			
			//服务端处理逻辑
			dothing(connfd);
			close(connfd);
			exit(0);
		}
		
			close(connfd);//避免内存泄露
		
	}
	//printf("clientfd :%d\n", listenfd);
	return 0;

}