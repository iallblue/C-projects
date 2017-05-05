#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct BNode{
    int data;
    struct BNode *lchild, *rchild;
}BNode, *Bitree;

/*  先序递归创建二叉树   */
int create_Bitree(Bitree &t)
{
    int data;
    cin >> data;

    if (data == 0)  t = NULL;   /*  递归生成树的结束  */
    else
    {
        if ((t = (Bitree)malloc(sizeof(BNode))))
        {
            t->data = data;
            create_Bitree(t->lchild);
            create_Bitree(t->rchild);
        }
    }
    return 1;
}


/**
 *  访问二叉树第k层节点
 *
 *  递归访问：将问题转换为求解以 根节点的叶子节点的第 k-1 层的节点
 *  从而不断递归访问。
 *  递归结束条件，则是 k - 1退化到0即可
 */
void printNodeAtLevel(BNode *root, int level)
{
    if (root == NULL || level < 0)  /*  参数的合法检查 */
    {
        return ;
    }

    if (level == 0) /*  退化为根节点  */
    {
        cout << root->data << " ";
    }

    /*  递归求解子问题 */
    printNodeAtLevel(root->lchild, level-1);
    printNodeAtLevel(root->rchild,level-1);
}

int main()
{
    cout << "先序遍历序列创建二叉树(0:表示空节点):" << endl;
    Bitree t;
    int res;

    res = create_Bitree(t);
    if (res)
    {
        printNodeAtLevel(t, 2);
    } else {
        cout << "创建二叉树失败！" << endl;
    }
    return 0;
}
