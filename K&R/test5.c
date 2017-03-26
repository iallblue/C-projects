#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IN 1    /*在单词内*/
#define OUT 0   /*在单词外*/

void getCharTest()
{
    char c;

    c = getchar();
    while (c != EOF)
    {
        putchar(c);
        c = getchar();
    }
}

void getCol()
{
    char c;
    int num = 0;
    while ((c = getchar()) != EOF)
    {
        if (c == '\n')
            num++;
    }
    printf("the numline is:%d\n",num);
}
void getCharNum()
{
    char c;

    int nl,nc,nw,state ;
    nl = nc = nw = 0;
    state = OUT;
    while ((c = getchar()) != EOF)
    {
        nc++;
        //putchar(c);
        if (c == '\n')
            nl++;
        if (c == ' ' || c == '\t' || c == '\n')
        {
            state = OUT;
            //printf("hello1\n");
        }
        else if (state == OUT) //说明输入的字符是属于单词的
        {
            //printf("hello\n");
            state = IN;
            ++nw;
        }
    }
    printf("nc=%d nw=%d nl=%d",nc,nw,nl);
}
int main()
{
    //printf("Hello world!\n");
    //getCharNum();
    char *str;
    str = "hello";
    printf("%s", str+1);
    char str1[6] = "hello";
    char str2[] = "hello";
    //printf("%d", strlen(str2));
    //printf("str1=%s sizeof(str1)=%d str2=%s size=%d \n len1=%d len2=%d",str1,sizeof(str1),str2,sizeof(str2),strlen(str1),strlen(str2));
    //printf("%s len1=%d len2=%d", str1, strlen(str1), strlen(str2));

    return 0;
}
