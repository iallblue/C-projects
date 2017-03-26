#include <stdio.h>
#include <stdlib.h>

int strlen(char str[])
{
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
}

int atoi1(char s[])
{
    int i = 0;
    int n = 0;
    for (i; '0' <= s[i] && s[i] <= '9'; i++)
    {
        //相对于字符 0 的偏移 也就是可以认为是这个数 但不是这个数的ascii
        n = n * 10 + (s[i] - '0');
        //234 =
        //0 * 10 + 2 = 2
        //2 * 10 + 3 = 23
        //23 * 10 + 4 = 234
    }
    return n;
}

//int lower(char str[])
//{
//    int i;
//    while (str[i] >= 'A' && str[i] <= 'Z')
//    {
//        str[i] = str[i] - ('A' - 'a');
//    }
//}

//从字符串中去除指定字符c
void squeeze(char str[],char c)
{
    int i = 0, j = 0;
    //借助双指针
    while (str[i] != '\0')
    {
        if (str[i] != c)
        {
           str[j] = str[i];
           j++;
        }
        i++;
    }
    str[j] = '\0';
}

//合并两个字符串
void strcat1(char str1[], char str2[])
{
    int i = 0,j = 0;
    while (str1[i] != '\0')
        i++;
//    while (str2[j] != '\0')
//    {
//        str1[i++] = str2[j++];
//    }

    while ((str1[i++] = str2[j++]) != '\0') ;
    //str1[i] = '\0';
}

int bitcount(unsigned x)
{
        int count = 0;
        for (count; x != 0; x >>= 1)
        {
            if (x & 01)
                count++;
        }
        return count;
}

void reverse(char str[])
{
    int i = 0,j = strlen(str)-1;
    char t;
    for (i,j; i < j ;i++,j--)
    {
        //首尾交换
        t = str[i];
        str[i] = str[j];
        str[j] = t;
    }
}

//跳过w尾部空格
void trim(char str[])
{
    int i;
    for ( i = strlen(str)-1; i > 0; i--)
    {
        if (str[i] != '\n' && str[i] != ' ' && str[i] != '\t')
            break;
    }
    str[++i] = '\0';

}

int main()
{
    char str[100] = "hello";

    char str2[] = "234";
    //squeeze(str,'l');
    strcat1(str,str2);
    printf("len:%s\n", str);
//    int x = 11;
//    printf("%d\n",bitcount(x));
    char str3[] = "hello";
    char str4[] = "123";
     printf("len:%s\n", str);
    int m = 100;
//    strcat1(str3,str4);
//    reverse(str3);
    printf("len:%s\n", str);
    reverse(str);
    printf("reverse:%s\n",str);
    char str5[] = "abc   ";
    trim(str5);
    printf("%s,%d",str5,strlen(str5));
    return 0;
}
