#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

typedef struct node NODE;

struct llist
{
    NODE *head;
};

typedef struct llist LLIST;

void init(LLIST *p, LLIST *q, LLIST *r) // initialization
{
    p->head = NULL;
    q->head = NULL;
    r->head = NULL;
}

NODE *getnode(int ele) // creation of dynamic memory
{
    NODE *temp;
    temp = (NODE *)malloc(sizeof(NODE));
    temp->data = ele;
    temp->link = NULL;
    return temp;
}

void ordered_insertion(LLIST *ptr, int ele)
{
    NODE *temp = getnode(ele);
    if (ptr->head == NULL) // insert at pos if value is small
        ptr->head = temp;
    NODE *first = ptr->head;
    if (temp->data < first->data)
    {
        temp->link = first;
        ptr->head = temp;
    }

    NODE *prev = NULL;
    while (first != NULL && temp->data > first->data)
    {
        prev = first;
        first = first->link;
    }
    prev->link = temp;
    temp->link = first;
}

void insert(LLIST *p, int ele) // inserting at beginning
{
    NODE *temp;
    temp = getnode(ele);
    if (p->head == NULL)
    {
        p->head = temp;
    }
    else
    {
        temp->link = p->head;
        p->head = temp;
    }
}

void insertr(LLIST *p, int ele) // inserting at rare end
{
    NODE *temp;
    temp = getnode(ele);
    NODE *pt = p->head;
    while (pt->link != NULL)
    {
        pt = pt->link;
    }
    pt->link = temp;
}

void insertpos(LLIST *p, int pos, int ele) // inserting at given pos
{
    // NODE *prev=NULL;
    // NODE *cur=p->head;
    // int c=0;
    // NODE *temp;
    // temp=getnode(ele);
    // if(pos==1)
    // {
    //     insert(p,ele);
    // }
    // else
    // {
    //     while(cur->link!=NULL && c!=pos)
    //     {
    //         prev=cur;
    //         cur=cur->link;
    //         c++;
    //     }
    //     prev->link=temp;
    //     cur->link=cur;
    // }
    NODE *temp;
    temp = getnode(ele);
    NODE *prev = NULL;
    NODE *ptr = p->head;
    for (int i = 0; i < pos; i++)
    {
        prev = ptr;
        ptr = ptr->link;
    }
    prev->link = temp;
    temp->link = ptr;
}

void sort(LLIST *p) // sorting ascending order
{
    NODE *ptr = p->head;
    for (NODE *i = ptr; i != NULL; i = i->link)
    {
        for (NODE *j = i->link; j != NULL; j = j->link)
        {
            if (i->data > j->data)
            {
                int temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

void length(LLIST *p) // length of list
{
    int c = 1;
    NODE *ptr = p->head;
    while (ptr->link != NULL)
    {
        c++;
        ptr = ptr->link;
    }
    printf("length=%d\n", c);
}

void delete (LLIST *p) // delete from first
{
    NODE *temp;
    temp = p->head;
    p->head = p->head->link;
    free(temp);
}

void deleter(LLIST *p) // delete from end
{
    NODE *ptr = p->head;
    NODE *temp = ptr->link;
    while (temp->link != NULL)
    {
        temp = temp->link;
        ptr = ptr->link;
    }
    ptr->link = NULL;
    free(temp);
}

void display(LLIST *p) // display fn
{
    NODE *ptr = p->head;
    while (ptr != NULL)
    {
        printf("\t%d", ptr->data);
        ptr = ptr->link;
    }
}

void destroy(LLIST *p) // deleting the complete list
{
    NODE *temp;
    while (p->head != NULL)
    {
        temp = p->head;
        p->head = p->head->link;
        free(temp);
    }
}

void rev(LLIST *p) // reversing the list
{
    // NODE *prev = NULL;
    // NODE *temp;
    // NODE *cur = p->head;
    // NODE *next = cur->link;
    // while (cur != NULL)
    // {
    //     cur->link = prev;
    //     prev = cur;
    //     cur = next;
    //     if (next != NULL)
    //         next = next->link;
    // }
    // p->head = prev;
    NODE *cur = p->head, *prev = NULL, *next = cur->link;
    while (cur != NULL)
    {
        next = cur->link;
        cur->link = prev;
        prev = cur;
        cur = next;
    }
    p->head = prev;
}



void deletealtnode(LLIST *ptr)
{
	NODE *curr=ptr->head;
	NODE *delete=curr;
	if(ptr->head==NULL)
	{
	printf("list is Empty\n");
	}
	else if(curr->link==NULL)
	{
		ptr->head=NULL;
		free(curr);
	}
	else
	{
		NODE *delete=curr;
		NODE *prev;
		ptr->head=curr->link;
		curr=curr->link;
		free(delete);
		while(curr->link!=NULL&&curr->link->link!=NULL)
		{
			delete=curr->link;
			prev=curr;
			curr=delete->link;
			prev->link=curr;
			free(delete);
		}
		if(curr->link==NULL)
	    {
	    	return;
		}
		else
		{
			curr->link=NULL;
			free(curr->link);
		}
		
	}
	
}

void search(LLIST *p, int ele) // searching the element in list
{
    int c = 0;
    NODE *ptr = p->head;
    for (NODE *i = ptr; i != NULL; i = i->link)
    {
        if (i->data == ele)
        {
            c = 1;
            break;
        }
    }
    if (c == 1)
        printf("found");
    else
        printf("NOT FOUND");
}


    void deletepos(LLIST * p, int pos) // deleting the element from given pos
    {
        NODE *temp;
        NODE *prev = NULL;
        NODE *ptr = p->head;
        int i = 0;
        while (ptr != NULL && i < pos)
        {
            prev = ptr;
            ptr = ptr->link;
            i++;
        }
        prev->link = ptr->link;
        ptr->link = NULL;
        free(ptr);
    }

    int main()
    {
        LLIST l1, l2, l3;
        init(&l1, &l2, &l3);
        // insert(&l1, 10);
        // insertr(&l2, 12);
        // insert(&l2, 15);
        // insert(&l1, 15);
        // insertpos(&l2, 2, 100);
        insert(&l1, 50);
        insert(&l1, 40);
        insert(&l1, 30);
        insert(&l1, 20);
        insert(&l1, 10);
        deletealtnode(&l1);
        // search(&l1,110);
        // sort(&l1);
        // length(&l1);
        // delete(&l1);
        // deleter(&l1);
        // deletepos(&l1,1);
        // rev(&l1);
        display(&l1);
        // destroy(&l1);
    }