#include <iostream>

using namespace std;
/**
 *  归并排序
 *
 *  借助辅助数组，将两个有序表 归并成一个有序表。
 *
 *  分治法：递归：归并
 *  复杂度o(nlogn) 每一趟归并的复杂度是o(n),共需o(logn)趟
 */
//int arr_b[]

/*  归并过程  */
void merge(int arr[], int low, int mid, int high,int n)
{
    /*  表A[]的两端,A[low...mid]和A[mid+1...high]两个有序表合并*/
    /*  辅助数组    */
    int arr2[n];
    int i,j,k;

    /*  将arr数组元素复制到辅助数组中    */
    for (i = low; i <= high; i++)
    {
        arr2[i] = arr[i];
    }

    //两个序列比较然后排序到原数组中
    for (i = low,j = low,k = mid+1;j <= mid && k <= high; i++)
    {
        if (arr2[j] < arr2[k])
        {
            arr[i] = arr2[j++];
        } else {
            arr[i] = arr2[k++];
        }
    }

    //将剩余元素直接复制到数组中
    while (j <= mid) /* 第一个序列未比较完毕   */
        arr[i++] = arr2[j++];
    while (k <= high) /* 第二个序列未比较完毕   */
        arr[i++] = arr2[k++];

    /*  上面只有一个while()会被执行   */
}

//递归过程
 void mergeSort(int arr[], int low, int high, int n)
 {
     /* 递归条件 */
     if (low < high)
     {
        /*  划分子序列 */
        int mid = (low + high)/2;
        mergeSort(arr, low, mid, n);
        mergeSort(arr, mid+1, high, n);

        /*  merge   */
        merge(arr, low, mid, high, n);
     }
     //递归结束
 }

int main()
{
    int i,arr[10];
    cout << "输入10个数:" << endl;

    for (i = 0; i < 10; i++)
    {
        cin >>  arr[i];
    }
    mergeSort(arr, 0, 9, 10);
    cout << "归并排序后:" << endl;

    for (i = 0; i < 10; i++)
    {
        cout << arr[i] << endl;
    }
    return 0;
}
