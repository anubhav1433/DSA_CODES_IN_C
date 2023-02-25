//USING LINKED LIST

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* link;
}NODE;

typedef struct way{

    NODE *front,*rear;
}queue;

queue* createqueue(){
    queue* temp=(queue*)malloc(sizeof(queue));
    if (temp!=NULL){
        temp->front=temp->rear=NULL;}
    return temp;}

NODE* createnode(int ele){
    NODE* temp=(NODE*)malloc(sizeof(NODE));
    if (temp!=NULL){
        temp->data=ele;temp->link=NULL;
    }
    return temp;}

void enqueue(int ele,queue* head){
    NODE* temp=createnode(ele);
    if (head->front==NULL && head->rear==NULL){
        head->front=head->rear=temp;
        return;}
    head->rear->link=temp;
    head->rear=temp;}

void display(queue *head){
    if (head->front==NULL && head->rear ==NULL){
        printf("underflow\n");return;}
    NODE *cur=head->front;
    while (cur!=NULL){
        printf("%d\t",cur->data);
        cur=cur->link;}
    printf("\n");
    return;}

void dequeue(queue *head){
    if (head->front==NULL && head->rear==NULL){
        printf("underflow\n");}
    if (head->front->link==NULL){
        free(head->front->link);
        head->front=head->rear=NULL;return;
    }
    NODE* cur=head->front->link;
    free(head->front);
    head->front=cur;
    return;
}

int main(){
    queue *l=createqueue();int ch,ele,x,n=1;
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




//USING ARRAY

// #include <stdio.h>
// #include <stdlib.h>
// #define maxsize 5
// struct Queue
// {
//     int item[maxsize];
//     int f;
//     int r;
// };
// int isFull(struct Queue *q)
// {
//     if (q->r == maxsize - 1)
//     {
//         return 1;
//     }
//     return 0;
// }
// int isEmpty(struct Queue *q)
// {
//     if (q->r == q->f)
//     {
//         return 1;
//     }

//     return 0;
// }
// void enqueue(struct Queue *q, int val)
// {
//     if (isFull(q))
//     {
//         printf("Queue is Full\n");
//     }
//     else if (q->f == -1 && q->r == -1)
//     {
//         q->f = q->r = 0;
//         q->item[q->r] = val;
//     }
//     else
//     {
//         q->r++;
//         q->item[q->r] = val;
//     }
// }
// int dequeue(struct Queue *q)
// {
//     int a = -1;
//     if (isEmpty(q))
//     {
//         printf("Queue is Empty\n");
//     }
//     else if (q->f == q->r) // only one element in queue
//     {
//         a = q->item[q->f];
//         q->f = q->r = -1;
//     }
//     else
//     {
//         a = q->item[q->f];
//         q->f++;
//     }
//     return a;
// }
// int peep(struct Queue *p)
// {
//     int x;
//     x = p->item[p->f];
//     return x;
// }

// void display(struct Queue *q)
// {
//     if (q->f == -1 && q->r == -1)
//         printf("Queue is Empty\n");
//     else
//     {
//         int x = q->f;
//         while (x <= q->r)
//         {
//             printf("%d\t", q->item[x]);
//             x++;
//         }
//         printf("\n");
//     }
// }
// int main()
// {
//     struct Queue q;
//     q.f = q.r = -1;
//     enqueue(&q, 1);
//     enqueue(&q, 4);
//     display(&q);
//     printf("Dequeuing element %d\n", dequeue(&q));
//     enqueue(&q, 18);
//     enqueue(&q, 45);
//     enqueue(&q, 56);
//     display(&q);
//     printf("Dequeuing element %d\n", dequeue(&q));
//     printf("peep element is %d", peep(&q));
//     enqueue(&q, 96);
//     display(&q);
//     return 0;
// }
