#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <string.h>
using namespace std;

/**
 *  三角形面积公式
 *
 *  海伦公式
 *
 */


/*  字符串转为数字 */
int stoi1(string str)
{
    char buf[100];
    strcpy(buf, str.c_str());
    return atoi(buf);
}

/*  是否能够构成三角形   */
int isTri(int a, int b, int c)
{
    if ((a+b) > c && (a+c) > b && (b+c) > a && (a-b) < c && (a-c) < b && (b-c) < a)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    int n,i,j,k,sum;
    double a,b,c,p,s,max = 0;
    int x1,y1,z1,x2,y2,z2;
    char tmp[100];
    //string str1 = "hello", str2 = "hello";


    while (cin >> n)
    {
        sum = 4 * n;
        string *arr = new string[sum];

        for (i = 0; i < sum; i++)
        {
            cin >> arr[i];
        }


        for (i = 0; i < sum; i += 4)
        {
            for (j = i + 4; j < sum; j += 4)
            {
                for (k = j + 4; k < sum; k += 4)
                {
                    if ((arr[i] == arr[j] && arr[j] == arr[k]) || (arr[i] != arr[j] && arr[j] != arr[k] && arr[i] != arr[k]))
                    {

                        a = sqrt(pow(stoi1(arr[i+1]) - stoi1(arr[j+1]),2)+pow(stoi1(arr[i+2]) - stoi1(arr[j+2]),2)+pow(stoi1(arr[i+3]) - stoi1(arr[j+3]),2));
                        b = sqrt(pow(stoi1(arr[i+1]) - stoi1(arr[k+1]),2)+pow(stoi1(arr[i+2]) - stoi1(arr[k+2]),2)+pow(stoi1(arr[i+3]) - stoi1(arr[k+3]),2));
                        c = sqrt(pow(stoi1(arr[j+1]) - stoi1(arr[k+1]),2)+pow(stoi1(arr[j+2]) - stoi1(arr[k+2]),2)+pow(stoi1(arr[j+3]) -stoi1(arr[k+3]),2));
                        //p = (a+b+c)/2;

                        //构成三角形
                        if (isTri(a,b,c))
                        {
                            p = (a+b+c)/2;
                            s = sqrt(p*(p-a)*(p-b)*(p-c));
                        }
                        if (s > max)
                        {
                            max = s;
                        }
                    }
                }
            }
        }

       printf("%.5f", max);

    }
}
