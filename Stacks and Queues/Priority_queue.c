//USING ARRAY

#include <stdio.h>
#include <stdlib.h>

struct pq
{
    int data;
    int pty;
};
typedef struct pq PQ;

void pqinsert(PQ *pq, int ele, int pty, int *c)
{
    PQ item;
    item.data = ele;
    item.pty = pty;
    int j = (*c) - 1;
    while (j >= 0 && pq[j].pty > item.pty)
    {
        pq[j + 1] = pq[j];
        j--;
    }
    pq[j + 1] = item;
    (*c)++;
}

PQ pqdelete(PQ *pq, int *c)
{
    PQ item;
    if (*c == 0) // empty queue
    {
        item.data = 0;
        item.pty = -1;
        return item;
    }
    item = pq[0];
    for (int i = 1; i < (*c) - 1; i++)
    {
        pq[i - 1] = pq[i];
    }
    (*c)--;
    return item;
}

int main()
{
    PQ pq[10], x;
    int ch = 0, ele, pty, c = 0;
    while (ch < 3)
    {
        printf("enter element and priority");
        scanf("%d %d", &ele, &pty);
        pqinsert(pq, ele, pty, &c);
        ch++;
    }
    for (int i = 0; i < 3; i++)
    {
        printf("%d\t", pq[i]);
    }
    x = pqdelete(pq, &c);
    if (x.pty == -1)
        printf("queue empty");
    else
        printf("\ndeleted element is %d with pty %d", x.data, x.pty);
}



//USING LINIKED LIST


// #include<stdio.h>
// #include<stdlib.h>
// struct queue
// {
//     int data,priority;
//     struct queue *next;
// };
// struct queue *front=NULL;
// void insert()
// {
//     struct queue *temp,*q;
//     temp=(struct queue *)malloc(sizeof(struct queue));
//     printf("enter data and priority\n");
//     scanf("%d %d",&(temp->data),&(temp->priority));
//     if(front==NULL || temp->priority<front->priority)//Insert at the beginning
//     {
//     temp->next=front;
//     front=temp;
//     }
//     else
//     {
//     q=front;
//     while(q->next!=NULL && q->next->priority<=temp->priority)//to find the position
//     {
//     q=q->next;
//     }
//     temp->next=q->next;
//     q->next=temp;
//     }
// }
// void delete()
// {
//     struct queue *temp;
//     if(front==NULL)
//     {
//     printf("QUEUE is empty\n");
//     return;
//     }
//     else
//     {
//     temp=front;
//     front=front->next;
//     printf("Deleted Data:%d\n",temp->data);
//     free(temp);
//     }
// }
// void display()
// {
//     struct queue *temp;
//     if(front==NULL)
//     {
//     printf("QUEUE is empty\n");
//     return;
//     }
//     else
//     {
//     printf("QUEUE Data\n");
//     temp=front;
//     do
//     {
//     printf("%d\t",temp->data);
//     temp=temp->next;
//     }
//     while(temp!=NULL);
//     printf("\n");
//     }
// }
// int  main()
// {
//     int option;
//     while(1)
//     {
//         printf("1.Insert\n");
//         printf("2.Delete\n");
//         printf("3.Display\n");
//         printf("4.Exit\n");
//         scanf("%d",&option);
//         switch(option)
//         {
//         case 1:insert();
//             break;
//         case 2:delete();
//             break;
//         case 3:display();
//             break;
//         case 4:return 0;
//         default:printf("INVALID");
//         }
//     }
// }
