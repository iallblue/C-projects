#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 *  选择排序
 *  复杂度：o(n^2)
 *  不稳定 2 2 1; 经过一趟排序后 第一个2会去1后面
 */

int main()
{
    int i,j,n,min,t;
    vector<int> arr;

    while (cin >> i)
    {
        arr.push_back(i);
    }

    n = arr.size();
    for (i = 0; i < n-1; i++)   //只需要n-1趟即可
    {
        min = i;
        for (j = i+1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }

        t = arr[min];
        arr[min] = arr[i];
        arr[i] = t;
    }

    for (i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}
