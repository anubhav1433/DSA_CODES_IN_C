#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char data;
    int top;
    struct node *link;
} NODE;

NODE *init()
{
    NODE *ptr = (NODE *)malloc(sizeof(NODE));
    if (ptr != NULL)
    {
        ptr->link = NULL;
        ptr->top = 0;
        return ptr;
    }
}

NODE *createnode(char ele)
{
    NODE *ptr = (NODE *)malloc(sizeof(NODE));
    if (ptr != NULL)
    {
        ptr->data = ele;
        ptr->link = NULL;
    }
    return ptr;
}

void push(char ele, NODE *head)
{
    NODE *temp = createnode(ele);
    NODE *cur = head->link;
    if (cur == NULL)
    {
        head->link = temp;
        head->top++;
        return;
    }
    while (cur->link != NULL)
    {
        cur = cur->link;
    }
    cur->link = temp;
    ++head->top;
}

void pop(NODE *head)
{
    NODE *cur = head->link, *prev;
    if (cur == NULL)
    {
        printf("the stack is empty\n");
        return;
    }
    if (cur->link == NULL)
    {
        head->link = NULL;
        free(cur);
        head->top--;
        return;
    }

    while (cur->link != NULL)
    {
        prev = cur;
        cur = cur->link;
    }

    prev->link = NULL;
    free(cur);
    head->top--;
    return;
}

void display(NODE *head)
{
    NODE *cur = head->link;
    if (cur == NULL)
    {
        printf("the list is empty\n");
        return;
    }
    while (cur != NULL)
    {
        printf("%c", cur->data);
        cur = cur->link;
    }
    printf("\n");
    return;
}

char peek(NODE *head)
{
    NODE *cur = head->link;
    while (cur->link != NULL)
    {
        cur = cur->link;
    }
    return cur->data;
}

int main()
{
    NODE *stack = init();
    char exp[50];
    printf("enter exp\n");
    scanf("%s", exp);
    char c;

    for (int i = 0; i < strlen(exp); i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(exp[i], stack);
        }

        else if (exp[i] - peek(stack) == 2 || exp[i] - peek(stack) == 1)
        {
            pop(stack);
        }

        else
        {
            continue;
        }
    }
    if (stack->top == 0)
    {
        printf("balanced\n");
    }
    else
    {
        printf("unbalanced\n");
    }
}