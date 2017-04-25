#include <iostream>

/**
 *  堆排序
 *  复杂度o(nlogn) n-1趟 没趟需要logn的复杂度调整,树高
 *  不稳定
 */
using namespace std;

/*  调整  */
void adjust(int arr[], int k, int len)
{
    int i,tmp;

    for (i = 2 * k; i <= len; i*=2)
    {
        //存在左右孩子元素，选出需要和双亲交换的节点
        if (i < len && arr[i] < arr[i+1])
            i++;

        //和双亲节点比较
        if (arr[k] < arr[i])
        {
            /*  交换  */
            tmp = arr[i];
            arr[i] = arr[k];
            arr[k] = tmp;
            /*  向下筛选  */
            k = i;
        }
        else    return;
    }
}

/*  建堆(arr[0] 不存放实际元素)  len = 实际长度-1 */
void build_heap(int arr[], int len)
{
    int i;

    /* 调整-从n/2开始 */
    for (i = len/2; i > 0; i--)
    {
        adjust(arr, i, len);
    }
}

/*
 *  堆排序：将堆的顶部元素取下,放到堆的最后面,
 *  将剩余元素重新调整成堆即可,调整交换,即可完成排序
 */
void HeapSort(int arr[], int len)
{
    int i,tmp;

    /*  初始化建堆   */
    build_heap(arr, len);
    for (i = len; i > 1; i--)//n-1趟
    {
        /*  堆顶和堆尾交换   */
        tmp = arr[i];
        arr[i] = arr[1];
        arr[1] = tmp;

        /*  重新调整    */
        adjust(arr,1,i-1);  //只需要调整堆顶即可
    }
}



int main()
{
    int i,n;/*  长度  */
    int arr[9];
    cout << "输入8个元素：" << endl;

    for (i = 1; i <= 8; i++)
    {
        cin >> arr[i];
    }

    cout << "堆排序后："<< endl;
    HeapSort(arr,8);
    for (i = 1; i <= 8; i++)
    {
        cout << arr[i] << endl;;
    }
    return 0;
}
