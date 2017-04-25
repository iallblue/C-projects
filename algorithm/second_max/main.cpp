#include <iostream>
#include <vector>
using namespace std;

int main()
{
    /*   第二大元素 */
    vector<int> arr;
    int i,j,tmp,max1,max2;

    while (cin >> i)
    {
        arr.push_back(i);
    }

    if (arr.size() < 2) return 1;

    arr[0] > arr[1] ? max1 = arr[0], max2 = arr[1] : max1 = arr[1], max2 = arr[0];
    for (i = 2; i < arr.size(); i++)
    {
        if (arr[i] > max2)
        {
            max2 = arr[i];
           // cout << "max2====" << max2 << endl;
        }

        if (max2 > max1)   /* 发现更大的 */
        {
            tmp = max2;
            max2 = max1;
            max1 = tmp;
        }
    }

    cout << "max2 = " << max2 << endl;

    return 0;
}
