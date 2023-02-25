#include <stdio.h>
#include <stdlib.h>
#define maxsize 7

// binary search tree using array
// insert
// inorder
// delete

// parent:i
// left:2*i+1
// right:2i+2

// delete case 1 left
// right subtree
// left subtree
// both left and right

int tree[maxsize];

void insert(int ele)
{
    int p = 0;
    if (tree[p] == -1)
    {
        tree[0] = ele;
    }
    else
    {
        while (tree[p] != -1)
        {
            if (ele < tree[p])
            {
                p = 2 * p + 1;
            }
            else
            {
                p = 2 * p + 2;
            }
        }
        if (p >= maxsize)
        {
            printf("it is overflow");
        }
        else
        {
            tree[p] = ele;
        }
    }
}

void inorder(int p)
{

    if (tree[p] != -1 && p < maxsize)
    {
        inorder(2 * p + 1);
        printf("%d\n", tree[p]);
        inorder(2 * p + 2);
    }
}

void display()
{
    for (int i = 0; i < maxsize; i++)
    {
        printf("%d\n", tree[i]);
    }
}

void init()
{
    for (int i = 0; i < maxsize; i++)
    {
        tree[i] = -1;
    }
}

int search(int key)
{
    int p = 0;
    while (tree[p] != -1)
    {
        if (key < tree[p])
        {
            p = 2 * p + 1;
        }
        else if (key > tree[p])
        {
            p = 2 * p + 2;
        }
        else if (key == tree[p])
        {
            printf("the key position is %d", p);
            return 1;
        }
    }
    return 0;
}

int main()
{
    init();

    insert(30);
    insert(40);
    insert(20);
    display();
    int x = search(40);
    if (x == 0)
    {
        printf("the key is not found ");
    }
    return x;
}