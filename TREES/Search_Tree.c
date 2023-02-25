#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *llink, *rlink;
} NODE;

struct root
{
    NODE *root;
};
typedef struct root TREE;

NODE *getnode(int ele) // creation of dynamic memory
{
    NODE *temp;
    temp = (NODE *)malloc(sizeof(NODE));
    temp->data = ele;
    temp->llink = NULL;
    temp->rlink = NULL;
    return temp;
}

void init(TREE *p)
{
    p->root = NULL;
}

void create_tree(TREE *p, int ele)
{
    NODE *temp, *cur, *prev;
    temp = getnode(ele);
    if (p->root == NULL)
    {
        p->root = temp;
    }
    else
    {
        cur = p->root;
        prev = NULL;
        while (cur != NULL)
        {
            if (ele < cur->data)
            {
                prev = cur;
                cur = cur->llink;
            }
            else
            {
                prev = cur;
                cur = cur->rlink;
            }
        }
        if (ele < prev->data)
            prev->llink = temp;
        else
            prev->rlink = temp;
    }
}

void inorder(NODE *root)                //left to right
{
    if(root!=NULL)
    {
        inorder(root->llink);
        printf("%d\n",root->data);
        inorder(root->rlink);
    }
}

int main()
{
    NODE *root=NULL;
    TREE t;
    init(&t);
    create_tree(&t, 10);
    create_tree(&t, 50);
    create_tree(&t, 30);
    create_tree(&t, 40);
    create_tree(&t, 20);
    inorder(root);
}