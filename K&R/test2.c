#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000

int getline(char line[],int maxline);
void copy(char to[], char from[]);

//用extern 获得全局变量
char test[] = "this is my life";

int main()
{
//    extern char test[];
//    printf("this is test extern :%s\n", test);
//    return 0;n

    int len;
    int max;
    char line[MAXLINE];//当前输入行
    char longest[MAXLINE];//保存的最长行

    max = 0;
    printf("please input lines(ctrl+z will be end) : \n");
    while ((len = getline(line, MAXLINE)) > 0)
    {
            //获得当前行是否大于后来的行
            if (len > max) {
                max = len;
                copy(longest, line);
            }
    }

    //若存在这样的行
    if (max > 0)
    {
        printf("the longest line is : %s",longest);
    }

//    char from[] = "hello";
//    char to[100];
//    copy(to,from);
//    printf("%s", to);
    return 0;
}

int getline(char s[], int lim)
{
    int i = 0;
    char c;

    //因为要读取一行，所以读到换行符 就要停止！
    for (i; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
    {
        s[i] = c;
    }
    //存储换行符
    if (c == '\n')
    {
        s[i] = '\n';
        ++i;//游标增加
    }
    s[i] = '\0';//存储结束符号
    return i;
}

void copy(char to[], char from[])
{
    int i;
    i = 0;
//    while (from[i] != '\0')
//    {
//        to[i] = from[i];
//        i++;
//    }
    //这种方法会将from[i]中的\0 复制到数组中
    while ((to[i] = from[i]) != '\0')
        i++;
}


