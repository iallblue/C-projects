#include <iostream>
#include <stdlib.h>

using namespace std;

/*
 *  链表反转
 */
typedef struct LNode
{
    int data;
    LNode *next;
}LNode, *Link;

/* 头插法创建单链表(逆序) */
Link create_Link(Link &l)
{
    //头结点 - 初始化
    l = (LNode *)malloc(sizeof(LNode));
    l->next = NULL;
    LNode *p;
    int i;

    while (cin >> i)
    {
        p =  (LNode *)malloc(sizeof(LNode));
        p->data = i;
        p->next = l->next;

        l->next = p;
    }
    return l;
}
//利用头结点重新插入 直接逆置表
Link reverse(Link &l)
{
    LNode *p,*tmp;

    p = l->next;
    l->next = NULL;//为了让新的尾节点的指针域为空
    //头插
    while (p)
    {
        tmp = p->next;
        p->next = l->next;
        l->next = p; //头结点指向 新的"生成节点的"
        p = tmp;//指向下一个节点
    }
    return l;
}

void foreach_Link(Link &l)
{
    l = l->next;
    while (l)
    {
        cout << l->data << endl;
        l = l->next;
    }

}

int main()
{
    Link l;
    l = create_Link(l);
    cout << "遍历节点:" << endl;
    l = reverse(l);
    cout << "逆序后遍历节点:" << endl;
    foreach_Link(l);
    return 0;
}
