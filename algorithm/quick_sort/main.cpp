#include <iostream>
#include <vector>
/**
 *
 *  快速排序
 */

using namespace std;

//快速排序返回 每次确定一个元素的位置
int get_prior(int arr[], int low, int high)
{
    int i,j,t;

    i = low;
    j = high;
    t = arr[low]; /* 基点 */
    while (i < j) /* 只有low < high 才会比较 */
    {
        while (i < j && arr[j] >= t) j--;
        arr[i] = arr[j];

        while (i < j && arr[i] <= t) i++;
        arr[j] = arr[i];
    }
    arr[i] = t;
    return i;
}

void quick_sort(int arr[], int low, int high)
{
    int prior;
    if (low < high) /* 递归结束条件 */
    {
        prior = get_prior(arr,low, high);

        quick_sort(arr, low, prior-1);

        quick_sort(arr, prior+1, high);
    }
}

int main()
{
    int i,n;
    vector<int> vec;

    while (cin >> i)
    {
        vec.push_back(i);
    }

    n = vec.size();

    int arr[n];
    for (i = 0; i < n; i++)
    {
        arr[i] = vec[i];
    }
    vec.clear();
    quick_sort(arr, 0, n-1);
    for (i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}
