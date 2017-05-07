#include <iostream>
#include <string.h>

using namespace std;
/**
 *  空格替换
 */

 void replace(char *str, int length)
 {
    int i,j,num = 0;
    int len = length, len2;
    char  arr[len + 1];
    strcpy(arr, str);
    for (i = 0; i < len; i++)
    {
        if (' ' == arr[i])
        {
            num++;  /*  统计空格个数  */
        }
    }

    len2 = len + 2 * num;
    char rep[len2+1];    /*  留出替换后字符所需的空间 */

    for (i = 0,j = 0; i < len && j < len2; i++)
    {
        if (arr[i] != ' ')
        {
            rep[j++] = arr[i];
        }   else {
            rep[j] = '%';
            rep[++j] = '2';
            rep[++j] = '0';
            j++;
        }
    }
    rep[j] = '\0';
    cout << rep << endl;

 }


void my_replace(char *str, int length)
{
    /*  合法性验证   */
    if (str == NULL || length <= 0)
        return ;

    int space,i;

    space = 0;
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ' ')
            space++;
    }
    int len = i + 2 * space;
    //i = length;
    while (i >= 0)
    {
        if (str[i] != ' ' )
        {
            str[len--] = str[i--];
        } else {
            str[len--] = '0';
            str[len--] = '2';
            str[len--] = '%';
            i--;
        }
    }

    cout << str << endl;
}

int main()
{

    string str;
    int len, len2;

    getline(cin,str);

    len = str.length();
    // cout << "len=" << len << endl;
    char arr[len];
    // char arr2[len] = "hello worl";
    strcpy(arr, str.c_str());


    my_replace(arr, len);
    return 0;
}
