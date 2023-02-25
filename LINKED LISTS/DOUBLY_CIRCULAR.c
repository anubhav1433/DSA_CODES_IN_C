#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *llink;
    struct node *rlink;
};
typedef struct node NODE;

struct dclist{
    NODE *tail;
};
typedef struct dclist DCLIST;

void init(DCLIST *p)
{
    p->tail=NULL;
}

NODE *getnode(int ele) // creation of dynamic memory
{
    NODE *temp;
    temp = (NODE *)malloc(sizeof(NODE));
    temp->data = ele;
    temp->llink = NULL;
    temp->rlink=NULL;
    return temp;
}

void insert(DCLIST *p,int ele)
{
    NODE *temp=getnode(ele);
    if((p->tail)==NULL)
    {
        temp->rlink=temp;
        temp->llink=temp;
        p->tail=temp;
    }
    else{
    p->tail->rlink->llink=temp;
    temp->rlink=p->tail->rlink;
    temp->llink=p->tail;
    p->tail->rlink=temp;}
}

void insertr(DCLIST *p,int ele)
{
    NODE *temp=getnode(ele);
    if((p->tail)==NULL)
    {
        temp->rlink=temp;
        temp->llink=temp;
        p->tail=temp;
    }
    else{
        temp->rlink=p->tail->rlink;
        temp->llink=p->tail;
        p->tail->rlink->llink=temp;
        p->tail->rlink=temp;
        p->tail=temp;
    }
}

void insertpos(DCLIST *p,int ele,int pos)
{
    NODE *temp=getnode(ele),*cur=p->tail;
    int i=0;
    while(cur!=p->tail->llink && i<pos)
    {
        cur=cur->rlink;
        i++;
    }
    temp->rlink=cur->rlink;
    temp->llink=cur;
    cur->rlink->llink=temp;
    cur->rlink=temp;
}

void delete(DCLIST *p)
{
    NODE *temp=p->tail->rlink;
    p->tail->rlink=temp->rlink;
    temp->rlink->llink=p->tail;
    temp->llink=NULL;
    temp->rlink=NULL;
    free(temp);
}

void deleter(DCLIST *p)
{
    NODE *cur=p->tail->rlink,*temp;
    if(p->tail==NULL)
    {
        printf("list empty");
    }
    else if(cur==cur->rlink)
    {
        temp=p->tail;
        free(temp);
        p->tail=NULL;
    }
    while(cur->rlink!=p->tail->rlink)
    {
        cur=cur->rlink;
    }
    p->tail=cur->llink;
    p->tail->rlink=cur->rlink;
    cur->rlink->llink=p->tail;
    cur->llink=NULL;
    cur->rlink=NULL;
    free(cur);
}

void deletepos(DCLIST *p,int pos)
{
    NODE *cur=p->tail->rlink;
    NODE *next=cur->rlink;
    int i=0;
    while(cur!=p->tail && i<pos)
    {
        cur=cur->rlink;
        next=next->rlink;
        i++;
    }
    cur->llink->rlink=next;
    next->llink=cur->llink;
    if(cur==p->tail)
        p->tail=cur->llink;
    cur->llink=NULL;
    cur->rlink=NULL;
    free(cur);
}
void display(DCLIST *p)
{
    if(p->tail==NULL)
    {
        printf("EMPTY LIST");
        return;
    }
     NODE *cur=(p->tail)->rlink;
    while(cur->rlink!=(p->tail)->rlink)
    {
       printf("\t%d",cur->data); 
       cur=cur->rlink;
    }
    printf("\t%d",cur->data);
}

int main(){
        DCLIST l1;
        init(&l1);
        insert(&l1,100);
        insert(&l1,200);
        insertr(&l1,300);
        insertr(&l1,500);
        insertpos(&l1,400,2);
        // delete(&l1);
        // deleter(&l1);                 
        //deletepos(&l1,2);
        display(&l1);
}