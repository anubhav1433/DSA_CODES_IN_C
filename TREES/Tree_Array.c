#include <stdio.h>
#define treesize 7
int tree[treesize];

void insert(int ele)
{
    int p = 0;
    if (tree[p] == -1)
    {
        tree[p] = ele;
    }
    else
    {
        while (tree[p] != -1 && p < treesize)
        {
            if (ele < tree[p])
                p = 2 * p + 1;
            else
                p = 2 * p + 2;
        }
        if (p > treesize)
            printf("\ninvalid iinsert");
        else
            tree[p] = ele;
    }
}

void display()
{
    for (int i = 0; i < treesize; i++)
    {
        printf("\n%d", tree[i]);
    }
}

void inorder(int p)
{
    if(tree[p]!=-1 && p<treesize)
    {
        inorder(2*p+1);
        printf("\n%d",tree[p]);
        inorder(2*p+2);
    }
}



int main()
{
    for (int i = 0; i < treesize; i++)
    {
        tree[i] = -1;
    }
    insert(100);
    insert(150);
    insert(50);
    insert(60);
    //display();
    inorder(0);
}