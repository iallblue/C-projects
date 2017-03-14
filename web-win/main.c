#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>
#include <process.h>

#define BUF_SIZE 2048
#define BUF_SMALL 100

//#pargma comment(lib, "ws2_32")

unsigned WINAPI RequestHandler(void* arg);
char* ContentType(char* file);
void SendData(SOCKET sock, char * ct, char * filename);
void SendErrorMSG(SOCKET sock);
void ErrorHandling(char *message);

//int main(int argc,char ** argv)
int main()
{
    WSADATA wsaData;
    SOCKET hServSock, hClntSock;
    SOCKADDR_IN servAdr, cltAdr;

    HANDLE hThread;
    DWORD dwThreadID;
    int cltAdrSize;

    /*
    if (argc != 2)
    {
        printf("error: %s <port>", argv[0]);
        exit(1);
    }
    */

    if (WSAStartup(MAKEWORD(2,2), &wsaData) != 0)
    {
        ErrorHandling("WSAStartup() error!");
    }

    hServSock = socket(PF_INET, SOCK_STREAM, 0);
    //开辟内存区域
    memset(&servAdr, 0, sizeof(servAdr));
    servAdr.sin_family = AF_INET;
    servAdr.sin_addr.s_addr = htonl(INADDR_ANY);
    servAdr.sin_port = htons(9190);

    if (bind(hServSock, (SOCKADDR *) &servAdr, sizeof(servAdr)) == SOCKET_ERROR)
        ErrorHandling("bind() error");
    if (listen(hServSock, 5) == SOCKET_ERROR)
        ErrorHandling("listen() error");

    /**
     * 请求和响应
     */
    while(1) {
        cltAdrSize = sizeof(cltAdr);
       // printf("%d",servAdr.sin_port);
        hClntSock = accept(hServSock, (SOCKADDR*)&cltAdr, &cltAdrSize);
        printf("Connection Request : %s:%d\n",
               inet_ntoa(cltAdr.sin_addr), ntohs(cltAdr.sin_port));
               hThread = (HANDLE)_beginthreadex(NULL, 0, RequestHandler, (void*)hClntSock, 0, (unsigned *)&dwThreadID);
        printf("hello");

    }
    closesocket(hServSock);
    WSACleanup();
    //printf("Hello world!\n");
    return 0;
}

unsigned WINAPI RequestHandler(void *arg)
{
    SOCKET hClntSock = (SOCKET)arg;
    char buf[BUF_SIZE];
    char method[BUF_SMALL];
    char ct[BUF_SMALL];
    char filename[BUF_SMALL];

    recv(hClntSock, buf, BUF_SIZE, 0);
    if (strstr(buf, "HTTP/") == NULL)  //查看是否为HTTP发起的请求
    {

        SendErrorMSG(hClntSock);
        closesocket(hClntSock);
        return 1;
    }

    strcpy(method, strtok(buf, " /"));
    if (strcmp(method, "GET"))
        SendErrorMSG(hClntSock);

    strcpy(filename, strtok(NULL, " /"));
    strcpy(ct, ContentType(filename)); //查看文件类型
    SendData(hClntSock, ct, filename);
    return 0;
}

void SendData(SOCKET sock, char* ct, char * filename)
{
    //HTTP 报文
    char protocol[] = "HTTP/1.0 200 OK \r\n";//协议
    char servName[] = "Server:my web server\r\n";
    char cntLen[] = "Content-length:2048\r\n";
    char cntType[BUF_SMALL];
    char buf[BUF_SIZE];
    FILE * sendFile;

    sprintf(cntType, "Content-type:%s\r\n\r\n", ct);
    if ((sendFile = fopen(filename, "r")) == NULL)
    {
        SendErrorMSG(sock);
        return;
    }

    //发送头信息
    send(sock, protocol,strlen(protocol),0);
    send(sock, servName, strlen(servName),0);
    send(sock, cntLen, strlen(cntLen), 0);
    send(sock,cntType, strlen(cntType), 0);

    //发送数据
    while(fgets(buf,BUF_SIZE, sendFile)!= NULL)
        send(sock, buf, strlen(buf), 0);

    closesocket(sock); // http响应后端看
}
void SendErrorMSG(SOCKET sock)
{
    char protocol[] = "HTTP/1.0 400 Bad Request \r\n";//协议
    char servName[] = "Server:my web server\r\n";
    char cntLen[] = "Content-length:2048\r\n";
    char cntType[] = "Content-type:text\html\r\n\r\n";
    char content[] = "<html><head><title>MY-WEB</title></head><font size=+5><br>find ERROR!</font></html>";

    char buf[BUF_SIZE];
    FILE * sendFile;

    send(sock, protocol,strlen(protocol),0);
    send(sock, servName, strlen(servName),0);
    send(sock, cntLen, strlen(cntLen), 0);
    send(sock,cntType, strlen(cntType), 0);
    send(sock, content, strlen(content), 0);
    closesocket(sock);

}

char * ContentType(char * file)
{
    char extension[BUF_SMALL];
    char filename[BUF_SMALL];
    strcpy(filename, file);
    strtok(filename, ".");
    strcpy(extension, strtok(NULL, "."));
    if (!strcmp(extension, "html") || !strcmp(extension, "htm"))
    {
        return  "text\html";
    } else {
        return "text\plain";
    }
}

void ErrorHandling (char * message)
{
    fputs(message, stderr);
    fputs('\n', stderr);
    exit(1);
}
/*若要成功运行需要在 project -> build options -> debug -> link setting other 添加 -lws2_32
*/
