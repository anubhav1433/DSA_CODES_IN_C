#include <stdio.h>
#include <stdlib.h>
#define tab_size 10

struct inv
{
    int path_id;
    int qty;
    int flag;
};
typedef struct inv parts;

void init(parts *p)
{
    for(int i=0;i<tab_size;i++)
    {
        p[i].flag=-1;
    }
}

void insert(parts *p,int id,int qty,int *count)
{
    int ind;
    if(*count ==tab_size)
    {
        printf("\n hash table full cannot insert");
        return;
    }
    ind=id%tab_size;
    while(p[ind].flag==1)
        ind=(ind+1)%tab_size;
    p[ind].path_id=id;
    p[ind].qty=qty;
    p[ind].flag=1;
    (*count)++;
}

// void remove_ele(int key)
// {
// 	int index=hash_fun(key);
// 	int i=index;
// 	while(ht[i].flag!=0)
// 	{
// 		if(array[i].data->key==key)
// 		{
// 			array[i].flag=2;
// 			array[i].data=NULL;
// 			return;
// 		}
// 		i=(i+1)%tab_size;
// 		if(i==index)
// 			break;
// 	}
// 	printf("elemnet not foundn");
// }

void display(parts *p)
{
    for(int i=0;i<tab_size;i++)
    {
        printf("\n%d:",i);
        if(p[i].flag!=-1)
            printf("%6d,%6d",p[i].path_id,p[i].qty);
    }
}

int main()
{
    int ch,qty,part_id,succ,count=0;
    parts ht[10];
    init(ht);
    do{
        printf("Enter the choice: 1:insert\n 2:display\n 3:search\n 4:delete\n 5:exit");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("Enter the part_id and qty:");
                   scanf("%d %d",&part_id,&qty);
                   insert(ht,part_id,qty,&count);
                   break;
            case 2:display(ht);
                   break;
            case 3:printf("Enter tha part_id");
                   scanf("%d",&part_id);
                   //succ=search(ht,part_id);
                   if(succ=0)
                       printf("pard_id not found");
                   break;
            case 4:printf("Enter tha part_id");
                   scanf("%d",&part_id);
                   //ssucc=delete(ht,part_id);
                   if(succ==0)
                       printf("path not found cannot delete");
                   break;
        }
    }while(ch!=5);
    return 0;
}