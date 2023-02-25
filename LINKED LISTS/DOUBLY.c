#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *llink;
    struct node *rlink;
};

typedef struct node NODE;

struct dlist
{
    NODE *head;
};

typedef struct dlist DLIST;

void init(DLIST *p) // initialization
{
    p->head = NULL;
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

void insert(DLIST *p,int ele)
{
   NODE *temp;
   temp=getnode(ele);
   if(p->head==NULL)
   {
        p->head=temp;
   }
   else
   {
        p->head->llink=temp;
        temp->rlink=p->head;
        p->head=temp;
   }
}

void insertr(DLIST *p,int ele)
{
    NODE *temp;
    temp=getnode(ele);
    if(p->head==NULL)
    {
        insert(p,ele);
    }
    else
    {
        NODE *cur=p->head;
        while(cur->rlink!=NULL)
        {
            cur=cur->rlink;
        }
        cur->rlink=temp;
        temp->llink=cur;
    }
}

void insertpos(DLIST *p,int pos,int ele)
{
    NODE *temp=getnode(ele);
    if(p->head==NULL)
    {
        p->head=temp;
    }
    else{
        NODE *cur=p->head;
        NODE *prev=NULL;
        int i=0;
        while(cur->rlink!=NULL && i<pos)
        {
            cur=cur->rlink;
            prev=cur->llink;
            i++;
        }
        prev->rlink=temp;
        temp->rlink=cur;
        temp->llink=prev;
        cur->llink=temp;
    }
}

void delete(DLIST *p)
{
    NODE *temp;
    if(p->head==NULL)
    {
        printf("EMPTY LIST");
        return;
    }
    else if((p->head)->rlink==NULL)
    {
        free(p->head);
        p->head=NULL;
    }
    else
    {
        temp=p->head;
        (p->head)->rlink->llink=NULL;
        p->head=(p->head)->rlink;
        free(temp);
    }
}

void deleter(DLIST *p)
{
    NODE *temp;
    if(p->head==NULL)
    {
        printf("empty list\n");
        return;
    }
    else if((p->head)->rlink==NULL)
    {
        free(p->head);
        p->head=NULL;
    }
    else
    {
        NODE *cur=p->head;
        while(cur->rlink!=NULL)
        {
            cur=cur->rlink;
        }
        cur->llink->rlink=NULL;
        free(cur);
    }
}

void deletepos(DLIST *p,int pos)              
{
    NODE *cur=p->head,*prev=NULL,*next=cur->rlink;
    int i=0;
    while(cur->rlink!=NULL && i<pos)
    {
        cur=cur->rlink;
        prev=cur->llink;
        next=cur->rlink;
        i++;
    }
    prev->rlink=next;
    cur->rlink=NULL;
    next->llink=prev;
    cur->llink=NULL;
    free(cur);
}


void display(DLIST *p)
{
    NODE *cur=p->head;
    if(cur==NULL)
    {printf("LIST IS EMPTY NOW\n");}
    while(cur!=NULL)
    {
        printf("\t%d",cur->data);
        cur=cur->rlink;
    }
}

void delalt(DLIST *p)                                  //deleting alternate node
{
    NODE *cur=p->head,*next=cur->rlink,*temp;
    next->llink=NULL;
    cur->rlink=NULL;
    free(cur);
    p->head=next;
    cur=p->head;
    next=cur->rlink;
    while(next!=NULL && next->rlink!=NULL)
    {
        temp=next;
        cur->rlink=temp->rlink;
        temp->rlink->llink=cur;
        temp->llink=NULL;
        temp->rlink=NULL;
        free(temp);

       cur=cur->rlink;
       next=cur->rlink;

    }


    if(next->rlink==NULL )
        {
            free(next);
            cur->rlink=NULL;
        }
}        
       
        
    


int main()
{
    DLIST l1;   
    init(&l1);
    insert(&l1, 10);
    insert(&l1, 12);
    insert(&l1, 15);
    //insertr(&l1, 150);
    insertpos(&l1, 2, 100);
  //  delalt(&l1);
    // search(&l1,110);
    // sort(&l1);
    // length(&l1);
    // delete(&l1);
    // deleter(&l1);
    //deletepos(&l1,1);
    // rev(&l1);
    display(&l1);
    // destroy(&l1);
}