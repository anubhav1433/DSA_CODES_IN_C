#include<stdio.h>
#include<stdlib.h>
#define maxsize 5
struct cqueue
{
    int items[maxsize];
    int front,rear;
};
typedef struct cqueue CQUEUE;
void cinsert(CQUEUE *p,int ele)
{
    if((p->rear+1)%maxsize==p->front)
    {
        printf("queue is full\n");
        return;
    }
    p->rear=(p->rear+1)%maxsize;
    p->items[p->rear]=ele;
    if(p->front==-1)
    {
        p->front=0;

    }

}
int cdelete(CQUEUE *p)
{
    int x;
    if(p->front==-1)
    {
        printf("queue is empty");
        return -1;
    }
    x=p->items[p->front];
    if(p->front==p->rear)
    {
        p->front=p->rear=-1;
    }
    else{
        p->front=(p->front+1)%maxsize;
    }
    return x;
}
void display(CQUEUE *p)
{
    int i,j;
    i=p->front;
    j=p->rear;
   while(i!=j)
   {
    printf("%d\n",p->items[i]);
    i=(i+1)%maxsize;
   }
   printf("%d\n",p->items[i]);
}
int main()
{
    CQUEUE q;
    int x;
    q.rear=-1;
    q.front=-1;
    cinsert(&q,12);
    cinsert(&q,13);
    cinsert(&q,14);
    cinsert(&q,15);
    // cinsert(&q,16);
    // cinsert(&q,17);
    //cdelete(&q);
    cdelete(&q);
    display(&q);

}