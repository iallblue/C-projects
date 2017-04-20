#include <iostream>

using namespace std;

void insert_sort(int arr[], int n)
{
    int i,j,t;

    for (i = 1; i < n; i++)
    {
        if (arr[i] < arr[i-1])
        {
            //取出待插入元素
            t = arr[i];
            //倒着比较，寻找插入位置(比arr[i]大的向后移动留出空位)
            for (j = i-1; j >= 0; j--)
            {
                if (arr[j] >= t)
                {
                    arr[j+1] = arr[j];//后移
                }
                else
                {
                    //找到待插入位置
                    break;
                }
            }
            arr[j+1] = t;
        }
    }
}

void simple_insert(int arr[], int n)
{
    int i,j,t;

    for (i = 1; i < n; i++)
    {
        if (arr[i] < arr[i-1])
        {
            //取出待插入元素
            t = arr[i];
            //倒着比较，寻找插入位置(比arr[i]大的向后移动留出空位)
            for (j = i-1; arr[j] >= t && j >= 0; j--)
            {
                arr[j+1] = arr[j];
            }
            arr[j+1] = t;
        }
    }
}

int main()
{
    int arr[] = {3,1,4,6,2,7,5}, i;
    int len = sizeof(arr)/sizeof(arr[0]);
    simple_insert(arr, len);

    for (i = 0; i < len; i++)
    {
        cout << arr[i] << endl;
    }
    return 0;
}
