#include<stdio.h>
#include<stdlib.h>

struct dequeue{
    struct node *front;
    struct node *rear;
};
struct node{
    int data;
    struct node *prev,*next;
};

typedef struct dequeue dq;


void qinsert_front(int x,struct dequeue *dq){
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=x;
    temp->next=temp->prev=NULL;
    if(dq->front==NULL)
    {
        dq->front=dq->rear=temp;
    }
    else{
        temp->next=dq->front;
        dq->front->prev=temp;
        dq->front=temp;
    }
}

void insert_tail(int x,struct dequeue *dq)
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=x;
    temp->next=NULL;
    if(dq->front==NULL)
    {
        dq->front=dq->rear=temp;
    }
    else{
        dq->rear->next=temp;
        temp->prev=dq->rear;
        dq->rear=temp;
    }
}


int qdel_front(struct dequeue *dq)
{
    struct node *temp;
    int x;
    if(dq->front==NULL)
        return -1;
    temp=dq->front;
    x=temp->data;
    if(dq->front==dq->rear)
    {
        dq->front=dq->rear=NULL;
    }
    else{
        dq->front=dq->front->next;
        dq->front->prev=NULL;
    }
    free(temp);
    return x;
}

int qdel_rear(struct dequeue *dq)
{
    struct node *temp;
    int x;
    if(dq->front==NULL)
        return -1;
    temp=dq->rear;
    x=temp->data;
    if(dq->front==dq->rear)
    {
        dq->front=dq->rear=NULL;
    }
    else{
        dq->rear=dq->rear->prev;
        dq->rear->next=NULL;
    }
    free(temp);
    return x;
}

int main(){
    dq d;
    d.front=d.rear=NULL;
    int n=1,ch;
    while(n){
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("enter choice\n");
        scanf("%d",&ch);
        switch(ch){
            
            case 1:
            printf("enter the element\n");
            scanf("%d",&ele);
            enqueue(ele,l);
            break;
            
            case 2:
            dequeue(l);
            break;

            case 3:
            display(l);break;

            case 4:
            n=0;break;
        }
    }
}