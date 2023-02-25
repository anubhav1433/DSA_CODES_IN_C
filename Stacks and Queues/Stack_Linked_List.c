#include<stdio.h>
#include<stdlib.h>
#define stksize 100

struct stack{
    int data;
    struct stack *link;
};

typedef struct stack NODE;

struct stlist{
    NODE *top;
};
typedef struct stlist STLIST; 

void init(STLIST *p)
{
    p->top=NULL;
}

NODE *getnode(int ele) // creation of dynamic memory
{
    NODE *temp;
    temp = (NODE *)malloc(sizeof(NODE));
    temp->data = ele;
    temp->link = NULL;
    return temp;
}

void push(STLIST *p,int ele)
{
    NODE *temp;
    temp=getnode(ele);
    if (p->top == NULL)
    {
        p->top = temp;
    }
    else
    {
        temp->link = p->top;
        p->top = temp;
    }
}

int pop (STLIST *p) // delete from first
{
    if(p->top==NULL)
    {
        printf("empty stack");
        return -1;
    }
    else{
    NODE *temp;int x;
    temp = p->top;
    x=p->top->data;
    p->top = p->top->link;
    free(temp);
    return x;
    }
}

void display(STLIST *p)
{
    if(p->top==NULL)
    {
        printf("stack empty");
    }
    else if(p->top->link==NULL)
    {
        printf("\t%d",p->top->data);
    }
    else{
    NODE *ptr=p->top;
    while(ptr->link!=NULL)
    {
        printf("\t%d",ptr->data);               //segmentation fault
        ptr=ptr->link;
    }
    }
}

int main()
{
    STLIST stk;
    push(&stk,10);
    push(&stk,20);
    push(&stk,40);
    pop(&stk);
    display(&stk);
}