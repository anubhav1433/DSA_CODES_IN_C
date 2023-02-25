#include<stdio.h>
#include<stdlib.h>
#define tab_size 10

struct node
{
    int path_id;
    int qty;
    struct node *link;
};
typedef struct node parts;
struct ht{
    parts *head;
};
typedef struct ht hash_table;

void insert(hash_table *ht,int part_id,int qty)
{
    int ind;
    parts *p;
    p=(parts *)malloc(sizeof(parts));
    p->path_id=part_id;
    p->qty=qty;
    p->link=NULL;
    ind=part_id%tab_size;
    p->link=ht[ind].head;
    ht[ind].head=p;
}
int search(hash_table *ht,int pard_id)
{
    int ind;
    parts *p;
    ind=pard_id%tab_size;
    p=ht[ind].head;
    while(p->path_id!=pard_id && p->link!=NULL)
        p=p->link;
    if(p->path_id==pard_id)
    {
        printf("part found");
        printf("part_id=%d and qty=%d",p->path_id,p->qty);
        return 1;
    }
    else{
        return 0;
    }
}
void display(hash_table *ht)
{
    for(int i=0;i<tab_size;i++)
    {
        printf("\n%d",i);
        for(parts *p=ht[i].head;p!=NULL;p=p->link)
        {
            printf("part_id=%5d and qty=%5d",p->path_id,p->qty);
        }
    } 
}
int delete(hash_table *ht,int pard_id)
{
    int ind;
    parts *p,*prev=NULL,*cur;
    ind=pard_id%tab_size;
    cur=ht[ind].head;
    if(cur->path_id==pard_id)
    {
        free(cur);
        ht[ind].head=NULL;
    }
    else{
        while(cur->link!=NULL && cur->path_id!=pard_id)
        {
            prev=cur;
            cur=cur->link;
        }
        if(cur->path_id==pard_id)
        {
            printf("Part id is found");
            printf("Part with part_id=%d is deleted",pard_id);
            prev->link=cur->link;
            free(cur);
            return 1;
        }
        else{
            return 0;
        }
    }
}

int main()
{
    int ch,qty,part_id,succ;
    hash_table ht[10];
    for(int i=0;i<=tab_size;i++)
        ht[i].head=NULL;
    do{
        printf("Enter the choice: 1:insert\n 2:display\n 3:search\n 4:delete\n 5:exit");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("Enter the part_id and qty:");
                   scanf("%d %d",&part_id,&qty);
                   insert(ht,part_id,qty);
                   break;
            case 2:display(ht);
                   break;
            case 3:printf("Enter tha part_id");
                   scanf("%d",&part_id);
                   succ=search(ht,part_id);
                   if(succ=0)
                       printf("pard_id not found");
                   break;
            case 4:printf("Enter tha part_id");
                   scanf("%d",&part_id);
                   succ=delete(ht,part_id);
                   if(succ==0)
                       printf("path not found cannot delete");
                   break;
        }
    }while(ch!=5);
    return 0;
}