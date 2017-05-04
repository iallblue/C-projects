#include <iostream>
#include <stack>
using namespace std;
/**
 *  中序遍历 - 非递归(三步走)
 *  1.从根节点开始，依次左孩子进栈(根节点最先进栈)
 *  2.左孩子走到尽头,访问栈顶,开始出栈
 *  3.栈顶右孩子进栈,重复上面过程
 */
typedef struct BitNode{
    struct BitNode *lchild, *rchild;
    int data;
}BitNode, *BiTree;

void InOrder(BiTree T)
{
    BiTree p = T;
    stack<BiTree>s;

    while (!s.empty() || p)  /*   栈非空 或者 树非空*/
    {
        if (p)      /*  节点存在 进栈*/
        {
            s.push(p->lchild);
            p = p->lchild;
        } else {    /*  节点走到尽头，开始出栈，访问右孩子节点*/
            p = s.top();
            s.pop();/*  出栈  */
            cout << p->data << endl;
            p = p->rchild;  /*  开始转向右子树 */
        }
    }
}

int main()
{

    return 0;
}
