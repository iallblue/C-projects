#include <iostream>

using namespace std;

/*  全排列算法 */
void swap(char *c1, char *c2)
{
    char t;
    t = *c1;
    *c1 = *c2;
    *c2 = t;
}

/**
 *  递归输出序列的全排列
 */
 void per(char arr[], int n, int index)
 {
     //走到尽头
    if (index >= n)
    {
        for (int i = 0; i < n; ++i)
        {
            //始终是一个arr数组,不过每次的递归都要交换元素
            cout << arr[i];
        }
        cout << endl;
    }

    //递归过程
    for (int i = index;i < n; ++i)
    {
        swap(arr[i], arr[index]);

        per(arr, n, index+1);

        swap(arr[i], arr[index]);
    }
 }

int main()
{
    //cout << "Hello world!" << endl;
    char str[100] = "abc";

    per(str, 3, 0);

    return 0;
}
