#include<stdio.h>
#include<stdlib.h>
#define stacksize 100

struct stack{
    int top;
    int items[stacksize];
};

typedef struct stack s;
void init(s *p)
{
    p->top=-1;
}

void push(s *p,int x)
{
    if(p->top==stacksize-1)
    {
        printf("stackn is full");
        return;
    }
    else{
        ++(p->top);
        p->items[p->top]=x;
    }
}

int pop(s *p)
{
    int x;
    if(p->top==-1)
    {
        printf("stack empty");
        return -1;
    }
    else{
        x=p->items[p->top];
        (p->top)--;
        return x;
    }
}

void display(s *p)
{
    if(p->top==-1)
    {
        printf("empty stACK");
        return;
    }
    else{
        for(int i=p->top;i>=0;i--)
        {
            printf("%d \t",p->items[i]);
        }
    }
}



int main()
{
    s stk;


    init(&stk);
    push(&stk,10);
    push(&stk,15);
    push(&stk,20);
    push(&stk,30);
    pop(&stk); 
    display(&stk);
}