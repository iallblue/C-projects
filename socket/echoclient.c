#include "sockethelp.c"

/******
 *
 *	客户端设置好 要连接的主机地址 和 服务端口
 *
 *****/

int main(int argc, char **argv)
{
	//定义变量
	int clientfd;
	char *hostname, *port;
	char send_buf[MAXLINE],receive_buf[MAXLINE];
	my_rio_t rio;
	
	if (argc != 3)
	{
		fprintf(stderr, "%s : arguments error\n",argv[0]);
		exit(0);
	}

	hostname = argv[1];
	port = argv[2];
	//利用预先定义的方法，创建clientfd(函数正常返回时，说明连接已经建立成功)
	//---------------------应该用带有错误处理的函数，需要完善----------
	clientfd = Open_clientfd(hostname, port);
	//	printf("clientfd is %d", clientfd);
	//	exit(0);
	//将clietnd 和rio绑定 初始化
	my_rio_readinitb(&rio, clientfd);

	//读取输出的信息
	while (fgets(send_buf, MAXLINE, stdin) != NULL)
	{
		//信息写入到clientfd，发送给服务端的过程
		my_writen(clientfd,send_buf, strlen(send_buf));
		
		//读取服务端发来的消息(读取到receive_buf中)
		my_rio_readlineb(&rio, receive_buf, MAXLINE);
		
		//将收到的信息输出出来
		fputs(receive_buf, stdout);
	}
	
	close(clientfd);
	return 0;
}