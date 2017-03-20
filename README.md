### web 服务器

*** 

* 主要是参考关于网络编程书上的实例，不是原创

* 接触了好几个关于web服务器的实现的，发现虽然代码不一样，但是底层所用的知识却是相同的

> 基本原理

*	web服务器 主要是通过C语言中的`socket`相关函数，建立通讯的，然后web服务器代替客户端去请求服务端的资源，从而实现双发的交流
*	目前大多数是采用多线程模式，一个线程负责监听连接，监听到连接时，则在创建一个线程去提供服务。
*	监听线程始终负责监听，不断有客户请求，则不断去创建子线程来提供服务。

*	可以查看具体相关的`TCP/IP`网络应用编程书籍，系统学习，在`csapp`上有具体相关的精简例子和原理分析。


### echoClient and echoServer

*** 

*	client and Server	


###	signal
***

*	机制
	*	进程之间是通过内核更新进程的上下文来传输信号的，收到信号后会有特定的信号处理程序或者默认的行为进行响应信号。
*	发送信号(基于`进程组`)
	*	用`/bin/kill`发送信号
	*	用`键盘输入` - eg:`ctrl+c`
	*	用`kill()` - 调用kill函数发送给其他进程和他们自己
	*	用`alarm()` - 定闹钟
	
*	接受信号
	*	信号（正在处理的 + 未处理的）
	*	信号是不排队的，同一种类型的信号只会在`待处理信号`中出现一次 
	*	`signal()` - 接受信号
*	阻塞和解除阻塞信号
	*	`sigprocmask(int how, const sigset \*set, sigset_t \*oldset)` - how定义行为，然后处理信号(阻塞set)

*	编写信号处理程序
	*	`异步处理`
	*	避免因为`信号不排队`造成的有些信号没有得到处理，导致进程成为`僵尸进程` - 会引起内存资源被过度消耗的问题
	*	`volatite sig_atomic_t t` - 定义了一组原子操作的类型 