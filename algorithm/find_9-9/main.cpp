#include <iostream>
#include <math.h>
using namespace std;

int judgeTheSame(int num)
{
    int i = 0,j,flag = 0;
    int arr[9];

    /*  取出num的每一位数  */
    while (num)
    {
        arr[i++] = num%10;
        num /= 10;
    }

    for (i = 0; i < 9; i++)
    {
        for (j = i+1; j < 9; j++)
        {
            if (arr[i] == arr[j] || arr[i] == 0)
            {
                flag = 1;
                return 1;
            }
        }
    }

    return 0;
}

/**
 *  找到符合条件的九位数
 *  1.这个9位数的
 */
int main()
{
    int num = 123456789;
    int i,j,k,a,flag = 0;

    i = 0;

    for (i = 123456789; i <= 200000000; i++)
    {
        flag = 0;
        if (!judgeTheSame(i))
        {
            //cout << i << endl;
            k = 8;
            j = 1;
            while (k >= 0)
            {
                a = pow(10,k--);
                if ((num / a) % j != 0) /*  发现不能整除第n位*/
                {
                    flag = 1;
                    break;
                }
                j++;
            }

            if (!flag)  cout << i << endl;
        }
    }

    return 0;
}
