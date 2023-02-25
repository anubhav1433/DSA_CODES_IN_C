#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct node
{
    char data;
    struct node *llink;
    struct node *rlink;
};

typedef struct node NODE;
NODE *stk[20];


NODE *getnode(char ch)
{
    NODE *temp;
    temp = (NODE *)malloc(sizeof(NODE));
    temp->data = ch;
    temp->llink = temp->rlink = NULL;
    return temp;
}

NODE *create_tree()
{
    char postfix[20];
    printf("enter postfix exp");
    scanf("%s", postfix);
    int i = 0, k = -1;
    char ch;
    while (postfix[i] != '\0')
    {
        ch = postfix[i];
        NODE *temp = getnode(ch);
        if (isalpha(ch))
        {
            stk[++k] = temp;
        }
        else
        {
            temp->rlink = stk[k--];
            temp->llink = stk[k--];
            stk[++k] = temp;
        }
        i++;
    }
    return stk[k--];
}

void inorder(NODE *root)
{
    if (root != NULL)
    {
        inorder(root->llink);
        printf("%c", root->data);
        inorder(root->rlink);
    }
}

float eval(NODE *root)
{
    float x, lval, rval;
    if (root == NULL)
    {
        return 0;
    }
    if(root->llink == NULL && root->rlink == NULL)
    {
        printf("enter the value for %c", root->data);
        scanf("%f", x);
        return x;
    }
    lval = eval(root->llink);
    rval = eval(root->rlink);
    if (root->data == '+')
        return rval + lval;
    else if (root->data == '-')
        return lval - rval;
    else if (root->data == '*')
        return lval * rval;
    else
        return lval / rval;
}

int main()
{
    NODE *root = NULL;
    root = create_tree();
    inorder(root);
}