#include "csapp.h"
#define MAXARGS 128

void eval(char *cmdline);
int parseline(char *buf,char **argv);
int builtin_command(char **argv);

int main() {
	char cmdline[MAXLINE];

	while (1) {
		//读命令
		printf("> ");
		Fgets(cmdline,MAXLINE,stdin);//从输入文件中获取输入
		if (feof(stdin)) {//输出结束
			exit(0);	
		}
		
		eval(cmdline);	//计算命令行
	}
}

//执行cmdline
void eval(char *cmdline) {
	char *argv[MAXARGS];
	char buf[MAXLINE];
	int bg;
	pid_t pid;

	strcpy(buf,cmdline);
	bg = parseline(buf,argv);
	if (argv[0] == NULL) {
		return;
	}
	
	if (!builtin_command(argv)) {
		if ((pid = Fork()) == 0) {
			//子进程去执行命令行
			if (execve(argv[0],argv,environ) < 0) {
				printf("%s :Command not found.\n",argv[0]);
				exit(0);
			}
		}
			
		//父进程
		if ( !bg ) {
			//如果不是后台进程
			int status;	
			if (waitpid(pid,&status,0) < 0) {
				//未捕获到子进程
				unix_error("waitfg:waitpid error");
			} 
		} else {
			printf("%d %s",pid,cmdline);
		}
	}
	return;
}

//如果第一个参数中是否是一个内置的shell命令
//默认内建命令是quit 
int builtin_command(char **argv) {
	if (!strcmp(argv[0],"quit")) exit(0);
	//后台进程
	if (!strcmp(argv[0],"&")) return 1;
	return 0;

}

int parseline(char *buf,char **argv) {
	char *delim;
	int argc;
	int bg;
	
	buf[strlen(buf) -1] = ' ';//将\n替换成' ' 
	while (*buf && *buf == ' ') buf++;
	
	argc = 0;
	while ((delim = strchr(buf,' '))) {
		argv[argc++] = buf;
		*delim = '\0';
		buf = delim + 1;
		while (*buf && *buf == ' ' ) buf++;

	} 
	
	argv[argc] = NULL;
	
	if (argc == 0) return 1;
	
	if ( (bg = (*argv[argc-1] == '&')) != 0) argv[--argc] = NULL;

	return bg;
}
