#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node *rlink;
	struct node *llink;
	int rthread,lthread;
}NODE;
typedef struct tree
{
	NODE* root;
}th;

th* initialize()
{
		th *temp=malloc(sizeof(th));
		temp->root=NULL;
		return(temp);
}
void create(th *ptr,int ele)
{
	NODE *temp=malloc(sizeof(NODE));
	temp->data=ele;
	temp->rlink=temp->llink=NULL;
	temp->rthread=temp->lthread=1;
	NODE *cur=ptr->root;
	if(cur==NULL)
	{
		ptr->root=temp;
		return;
	}
	while(1)
	{
		if(ele<cur->data)
		{
			if(cur->lthread==0)
			{
				cur=cur->llink;
			}
			else
				break;
		}
		else{
			if(cur->rthread==0)
			{
				cur=cur->rlink;
			}
			else
				break;
		}
	}
	if(ele<cur->data)
	{
		temp->rlink=cur;
		temp->llink=cur->llink;
		cur->llink=temp;
		cur->lthread=0;
	}
	else{
		temp->rlink=cur->rlink;
		temp->llink=cur;
		cur->rlink=temp;
		cur->rthread=0;
	}
}
NODE* inorder_succ(NODE *ptr)
{
	if(ptr==NULL)
	{
		printf("Empty\n");
		return(NULL);
	}
	if(ptr->rthread==1)
		ptr=ptr->rlink;
	else{
		ptr=ptr->rlink;
		while(ptr->lthread==0 &&ptr->llink!=NULL)
		{
			ptr=ptr->llink;
		}
	}
	return(ptr);
}
	
	
NODE *inorder(th *ptr)
{
	NODE *cur=ptr->root;
	if(cur==NULL)
	{
		printf("tree is empty");
		return(NULL);
	}
	while(cur->lthread==0)
	{
		cur=cur->llink;
	}
	while(cur!=NULL)
	{
		printf("%d\t",cur->data);
		cur=inorder_succ(cur);
	}
	return(ptr->root);
	
}


	


int main()
{
	th *ptr=initialize();
	int ch,ele;
	while(1)
	{
		printf("1.create a threaded binary tree\n 2. inorder\n");
		printf("enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("enter the element\n");
					scanf("%d",&ele);
					create(ptr,ele);
					break;
			case 2:ptr->root=inorder(ptr);			 
			break;
		}
	}
	return(0);
}