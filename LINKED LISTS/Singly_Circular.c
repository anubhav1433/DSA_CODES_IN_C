#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
};

typedef struct node NODE;

struct cllist
{
    NODE *tail;
};

typedef struct cllist CLLIST;

void init(CLLIST *p, CLLIST *q, CLLIST *r) // initialization
{
    p->tail = NULL;
    q->tail = NULL;
    r->tail = NULL;
}

NODE *getnode(int ele) // creation of dynamic memory
{
    NODE *temp;
    temp = (NODE *)malloc(sizeof(NODE));
    temp->data = ele;
    temp->link = NULL;
    return temp;
}

void insert(CLLIST *p,int ele)
{
    NODE *temp=getnode(ele);
    if((p->tail)==NULL)
    {
        temp->link=temp;
        p->tail=temp;
    }
    else{
        temp->link=p->tail->link;
        p->tail->link=temp;
    }
}

void insertr(CLLIST *p,int ele)
{
    NODE *temp=getnode(ele);
    if((p->tail)==NULL)
    {
        temp->link=temp;
        p->tail=temp;
    }
    else{
        temp->link=p->tail->link;
        p->tail->link=temp;
        p->tail=temp;
    }
}

void insertpos(CLLIST *p,int pos,int ele)
{
    NODE *temp=getnode(ele);
    NODE *cur=p->tail;
    int i=0;
    while(cur->link!=p->tail && i<pos)
    {
        cur=cur->link;
        i++;
    }
    temp->link=cur->link;
    cur->link=temp;
}

void delete(CLLIST *p)
{
    NODE *temp=p->tail->link;
    p->tail->link=p->tail->link->link;
    temp->link=NULL;
    free(temp);
}



void deleter(CLLIST *p)
{
    NODE *cur=p->tail->link,*temp;
    if(p->tail==NULL)
    {
        printf("list empty");
    }
    else if(cur==cur->link)
    {
        temp=p->tail;
        free(temp);
        p->tail=NULL;
    }
    while(cur->link!=p->tail)
    {
        cur=cur->link;
    }
    cur->link=p->tail->link;
    free(p->tail);
    p->tail=cur;
}

void deletepos(CLLIST *p,int pos)
{
    NODE *temp,*cur=p->tail;
    int i=0;
    while(cur->link!=p->tail && i<pos)
    {
        cur=cur->link;
        i++;
    }
    temp=cur->link;
    cur->link=cur->link->link;
    temp->link=NULL;
    free(temp);
}

void display(CLLIST *p)
{
    if(p->tail==NULL)
    {
        printf("EMPTY LIST");
        return;
    }
    NODE *cur=(p->tail)->link;
    while(cur->link!=(p->tail)->link)
    {
       printf("\t%d",cur->data); 
       cur=cur->link;
    }
    printf("\t%d",cur->data);
}

int main()
{
    CLLIST l1,l2,l3;
    init(&l1,&l2,&l3);
    insert(&l1,200);
     insert(&l1,100);
     insert(&l1,300);
     insertr(&l1,400);
     insertpos(&l1,2,500);   
     //delete(&l1);
    //deleter(&l1); 
    //deletepos(&l1,2);  
    
    display(&l1);
}