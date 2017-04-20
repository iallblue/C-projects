#include <iostream>

using namespace std;
void get_next(string str, int next[])
{
    int i,j;

    i = 0;//串指针(索引)
    j = -1;//默认的值next值
    next[0] = -1;//初始的next值

    while (i < str.length())
    {
        //next值走到尽头 || 查找到和对应位的值相同
        if (j == -1 || str[i] == str[j])
        {
            i++;
            j++;
            next[i] = j;
        }
        else
            j = next[j];//获得对应位的next值
    }
}
//普通的查找函数:下标从0开始
int comm_index(string S, string T)
{
    int i,j;

    i = j = 0;
    while (i < S.length() && j < T.length())
    {
        if (S[i] == T[j])
        {
            i++;
            j++;
            //cout << "i=" << i << " j=" << j << endl;
        }
        else
        {
            //指针回溯
            i = i - j + 1;
            j = 0;
        }
    }
    //cout << "i=" << i << " j=" << j << endl;
    if (j >= T.length()) return i - T.length();
    else return -1;
}

int kmp(string S, string T, int next[], int pos)
{
    //从S(主串中)的pos个字符后 起开始查找第一次T串出现的位置
    //T[]非空 1 <= pos <= strlen(S)
    int i,j;
    i = pos - 1;
    j = 0;
    int s_len = S.length(), t_len = T.length();
    while (i < s_len && j < t_len)
    {
        //注：当j=-1时,此时说明子串中已经比较到尽头了，需要i 和 j同时向前增加 j -> 0 此时的i已经比较过了需要向前滑动
        if (S[i] == T[j] || j == -1)
        {
            i++;
            j++;
        }
        else
        {
            //i不在回溯
            j = next[j];
        }
        //if (j == -1) cout << "hello" << endl;
        cout << "i=" << i << endl;
    }
    if (j >= t_len)
    {
        return i - T.length();
    }
    else return -1;

}

int main()
{
    string str = "abcabaaabaabcac";
    string fin = "abaabcac";
    int i,n = fin.length();
    int next[n];
    int pos;

    get_next(fin, next);
    for (i = 0; i < n; i++)
    {
        cout << next[i];
    }
    cout <<endl;

    //pos = comm_index(str, fin);
    pos = kmp(str, fin, next, 1);
    cout << "find : " << pos << endl;

    return 0;
}
