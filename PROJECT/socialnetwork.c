#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include<stdbool.h>
#define MAX 100

typedef struct node 
{
    int id; //ID of user
    int numfren; //number of friends of user
    char name[MAX]; //name of user
    int* friends; //friends of user as an array
    struct node* right;  //user to the right
    struct node* left; //user to the left
} node;

struct node* retUser(char str[MAX])
{
    char name[MAX];
    char ID[MAX];
    char strfriends[MAX];

    //copied ID
    char*token=strtok(str,",");
    strcpy(ID,token);

    //copied Name
    token=strtok(NULL,",");
    strcpy(name,token);

    //copied friends' ID
    token=strtok(NULL,",");
    strcpy(strfriends,token);
    //printf("%s\n",(strfriends));

    //creating user nodes
    int id=atoi(ID);
    struct node *user = malloc(sizeof(struct node));
    user->id=id;
    user->friends=(int*)malloc(MAX * sizeof(int));
    strcpy(user->name,name);


    //adding user's friend's IDs
    token = strtok(strfriends,"|");  
    int i=0;
    while( token != NULL ) 
    {

        int temp=atoi(token);
        user->friends[i]=temp;
        i++;
        token = strtok(NULL,"|");
    }
    user->numfren=i;
    if(i==0){user->friends[i]=-1;}
    return user;
}
 

//search for user with id=key
struct node* search(int key, struct node *users)
{
    if(users == NULL || users->id == key)
     return users;
    else
    {
        if(key<users->id)
            return search(key,users->left);
        else if(key>users->id)
            return search(key, users->right);
    }
}

//see document for explanattion
struct node*refineUser(struct node*user, struct node *users)
{
    while(search(user->id,users)!=NULL)
    {
        (user->id)++;
    }
    int j,count=0;
    node *temp;
    for(int i=0;i<user->numfren;i++)
    {
        temp=search(user->friends[i],users);
        if(temp!=NULL)
        {
            temp->friends[temp->numfren++]=user->id;
            count++;
        }
        else
        {
            user->friends[i]=-2;
        }
    }
    if(count==0)
    {
        user->friends[0]=-1;
        user->numfren=0;
    }
    else
    {
        for(int i=0;i<user->numfren;i++)
        {
            if(user->friends[i]==-2)
            {
                int j=i;
                while(j<user->numfren)
                {
                    user->friends[j]=user->friends[j+1];
                    j++;
                }
                user->numfren--;
            }
        }
    }
    return user;
}

//insert user with id
struct node* insertUser(struct node*root,int id,struct node*user)
{
   user->right=NULL;
   user->left=NULL;
   if(root==NULL)
   {
        root=user;
        return root;
   }
   node* temp=root;
   while(1)
   {
        if(id>temp->id)
        {
            if(temp->right==NULL)
            {
                temp->right=user;
                break;
            }
            else
            {
                temp=temp->right;
            }
        }
        else
        if(id<temp->id)
        {
            if(temp->left==NULL)
            {
                temp->left=user;
                break;
            }
            else
            {
                temp=temp->left;
            }
        }
   }
   return root;
}

//prints friends list
void friends(int id, struct node *users) 
{
   node* temp=search(id,users);
   if(temp->numfren==0)
   {
        printf("-1\n");
        return;
   }
   for(int i=0;i<temp->numfren;i++)
   {
        printf("%d\n",temp->friends[i]);
   }
}

//find child node with minimum value (inorder successor) - helper to delete node
struct node *minValueNode(struct node *node) 
{
    struct node *temp= node->right, *Q= node;
    if(!temp)
        return Q;
    while(temp->left)
    {
        Q=temp;
        temp=temp->left;
    }
    return Q;
}

//deletes itself from its friend's nodes
struct node*deleteFriends(int key, struct node*users)
{
    node *a,*p;
    int first;
    a=search(key,users);
    for(int i=0;i<a->numfren;i++)
    {
        first=a->friends[i];
        p=search(first,users);
        int j=0;
        while(j<p->numfren)
        {
            if(p->friends[j]==first)
            {
                break;
            }
            j++;
        }
        while(j<a->numfren)
        {
            p->friends[j]=p->friends[j+1];
            j++;
        }
        p->numfren--;
    }
}


// Deleting a node
struct node *deleteNode(struct node *root, int key) 
{
    if (root == NULL)
        return root;

    if (key < root->id)
        root->left = deleteNode(root->left, key);

    else if (key > root->id)
        root->right = deleteNode(root->right, key);
        
    else 
    {
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
  
        struct node* temp = minValueNode(root->right);
        root->id = temp->id;
        strcpy(root->name,temp->name);
        root->friends=temp->friends;
        root->numfren=temp->numfren;
        root->right = deleteNode(root->right, temp->id);
    }
    return root;
}

//Print USER's IDs in ascending order
void printInOrder(node* myusers) 
{
    if(myusers==NULL)
    {
        return;
    }
    printInOrder(myusers->left);
    printf("%d %s\n",myusers->id,myusers->name);
    printInOrder(myusers->right);
}


int main(int argc, char **argv)
{
    node *users=NULL;   
    while(1)
    {

        int opt, id;
        fflush(stdin);
        scanf("%d",&opt);
        char str[MAX];
        switch (opt)
        {
            case 1:
      
                scanf("%s",str);
                struct node*tbins=retUser(str);
                tbins=refineUser(tbins, users);
                users=insertUser(users,tbins->id,tbins);
                break;

            case 2:
           
                scanf("%d", &id);
                deleteFriends(id, users);
                users=deleteNode(users, id);
                break;

            case 3:
        
                scanf("%d", &id);
                node* result=search(id,users);
                if(result==NULL) 
                    printf("USER NOT IN TREE.\n");
                else{
                    printf("%d\n",result->id);
                }
                break;

            case 4:
                scanf("%d", &id);
                friends(id, users);
                break;

            case 5:
                printInOrder(users);
                break;

            case 6:
                exit(0);
                break;

            default: 
                printf("Wrong input! \n");
                break;
        }

    }
    return 0;
}