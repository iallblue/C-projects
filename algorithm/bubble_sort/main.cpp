#include <iostream>

using namespace std;

/**
 *
 *  冒泡排序
 */

void bubble_sort(int arr[], int n)   /* n - 数组长度,数组名作为指针传递时,无法捕获到数组长度 */
{
    int i,j,t;
    int flag;

    for (i = 0; i < n-1; i++)
    {
        flag = 1;
        for (j = n-1; j > i; j--)
        {
            //只有比前一个小才发生交换
            if (arr[j] < arr[j-1])
            {
                t = arr[j-1];
                arr[j-1] = arr[j];
                arr[j] = t;
                flag = 0;//没趟没有发送交换排序，则说明已经有序，不需要继续比较排序了
            }
        }

        //减少排序次数
        if (flag) return;
    }

}

int main()
{
    int i,arr[5];

    for (i = 0; i < 5; i++)
    {
        cin >> arr[i];
    }
    bubble_sort(arr,5);
    for (i = 0; i < 5; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}
