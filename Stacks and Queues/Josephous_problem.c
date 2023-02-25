//using double pointer

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};
typedef struct node NODE;

void insertr(NODE **tail, int ele)
{
    NODE *temp;
    temp = (struct node *)malloc(sizeof(NODE));
    temp->data = ele;
    temp->link = NULL;
    if (*tail == NULL)
    {
        temp->link = temp;
        *tail = temp;
    }
    else
    {
        temp->link = (*tail)->link;
        (*tail)->link = temp;
        (*tail) = temp;
    }
}

int surviour(NODE **tail, int pos,int start)
{
    NODE *cur, *prev = NULL;
    cur = (*tail)->link;
    for(int i=1;i<start;i++)
    {
        cur=cur->link;
    }
    
    while (cur->link != cur)
    {
        for (int i = 0; i < pos - 1; i++)
        {
            prev = cur;
            cur = cur->link;
        }
        prev->link = cur->link;
        printf("the deleted element is %d\n", cur->data);
        free(cur);
        cur = prev->link;
    }
    *tail = cur;
    return (cur->data);
}

int main()
{
    struct node *tail = NULL;
    int x,n;
    insertr(&tail, 1);
    insertr(&tail, 2);
    insertr(&tail, 3);
    insertr(&tail, 4);
    insertr(&tail, 5);
    printf("enter start element");
    scanf("%d",&n);
    x = surviour(&tail, 3,n);
    printf("surviour is %d", x);
}