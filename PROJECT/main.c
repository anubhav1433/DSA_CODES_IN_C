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

void copy_contents(struct node *root, struct node * user)
{
    if(!root || !user)
        return;
    root->id = user->id;
    strcpy(root->name,user->name);
    root->numfren = -1;
    for (int i = 0; i <= user->numfren ; i++)
    {
        root->friends[++root->numfren] = user->friends[i];
    }
    
}

void delete_array_element(int *arr, int key, int max)
{
    int flag = 0;
    for(int i = 0; i < max ; i++)
    {
        if(arr[i] == key)
            flag ++;
        if(flag)
            arr[i] = arr[i+1];
    }
}

int isIn(int *arr, int key, int max)
{
    for (int i = 0; i <= max; i++ )
    {
        if(arr[i] == key)
            return 1;
    }
    return 0;
}

//search for user with id=key
struct node* search(int key, struct node *users)
{
    //CODE HERE
    if(!users)
        return NULL;
    if(users->id == key)
        return users;
    if(users->id > key)
        search(key,users->left);
    else
        search(key,users->right);
}

//see document for explanattion
struct node*refineUser(struct node*user, struct node *users)
{
    //CODE HERE
    while(search(user->id,users))
    {
        user->id ++;
    }
    int i = 0;
    while(i <= user->numfren)
    {
        if(!search(user->friends[i],users))
            delete_array_element(user->friends,user->friends[i],user->numfren--);
        else
            i++;
    }
    if(user->numfren == -1 ) 
      user->friends[++user->numfren] = -1;
    for (i = 0; i <= user->numfren; i++) 
    {
        node *t = search(user->friends[i],users);
        if(t)
        {
            if(t->friends[0] != -1)
                t->friends[++t->numfren] = user->id;
            else
                t->friends[0] = user->id;
        }   
    }
    return user;

}

//insert user with id
struct node* insertUser(struct node*root,int id,struct node*user)
{
   //CODE HERE
    if(!root) 
        return user;
    if(id > root->id)
        root->right = insertUser(root->right, id, user);
    else
        root->left = insertUser(root->left, id, user);
    return root;
}

//prints friends list
void friends(int id, struct node *users) 
{
   //CODE HERE
    node *t = search(id, users);
    if(!t)
        return;
                printf("$$$$$$$$$$$\n");
    // printf("%s = %d\n",t->name,t->numfren);

    for(int i = 0; i <= t->numfren; i++)
    {
        printf("%d\n",t->friends[i]);
    }
                printf("$$$$$$$$$$$\n");

    

}

//find child node with minimum value (inorder successor) - helper to delete node
struct node *minValueNode(struct node *node) 
{
  //CODE HERE
    struct node *t = node->right, *p = node;
    if(!t)
        return p;
    while(t->left)
    {
        p = t;
        t = t->left;
    }
    return p;
}

//deletes itself from its friend's nodes
struct node*deleteFriends(int key, struct node*users)
{
    node *t = search(key, users);
    if(!t)
        return NULL;
    for ( int i = 0; i <= t->numfren; i++ )
    {
        node *p = search(t->friends[i], users);
        if(p)
        {
            delete_array_element(p->friends, key, p->numfren--);
            if(p->numfren == -1)
                p->friends[++p->numfren] = -1;
        }    
    }
    
}

// Deleting a node
struct node *deleteNode(struct node *root, int key) 
{
  //CODE HERE
    if(!root)
        return root;
    if(root->id == key)
    {
        if(!root->left)
        {
            node *t = root->right;
            free(root);
            return t;
        }
        else if(!root->right)
        {
            node *t = root->left;
            free(root);
            return t;
        }
        else
        {   
            node *t;
            node *p = minValueNode(root);
            if(p != root)
                t = p->left;
            else
                t = p->right;
            copy_contents(root,t);
            if(p != root)
                p->left = deleteNode(t, t->id);
            else
                p->right = deleteNode(t, t->id);
            return root;
        }

    }
    if(root->id > key)
        root->left = deleteNode(root->left, key);
    else
        root->right = deleteNode(root->right, key);
    return root;

}

//Print USER's IDs in ascending order
void printInOrder(node* myusers) 
{
    //CODE HERE
    if(!myusers)
        return;
    printInOrder(myusers->left);
    printf("%d %s\n",myusers->id,myusers->name);
    printInOrder(myusers->right);
}


int main(int argc, char **argv)
{
    int lines;
    node *users=NULL;   
    FILE *fptr;

    if ((fptr = fopen("input_2.txt","r")) == NULL){
        printf("Error! opening file");
        exit(1);
    }
    fscanf(fptr,"%d", &lines);
    printf("%d\n",lines);
    for(int i = 0; i < lines; i++)
    {

        int opt, id;
        fflush(stdin);
        
        fscanf(fptr,"%d",&opt);
        char str[MAX];
        switch (opt)
        {
            case 1:
      
                fscanf(fptr,"%s",str);
                struct node*tbins=retUser(str);
                tbins=refineUser(tbins, users);
                users=insertUser(users,tbins->id,tbins);
                break;

            case 2:
           
                fscanf(fptr,"%d", &id);
                deleteFriends(id, users);
                users=deleteNode(users, id);
                break;

            case 3:
        
                fscanf(fptr,"%d", &id);
                node* result=search(id,users);
                if(result==NULL) 
                    printf("USER NOT IN TREE.\n");
                else{
                    printf("%d\n",result->id);
                }
                break;

            case 4:
                fscanf(fptr,"%d", &id);
                friends(id, users);
                break;

            case 5:
                printf("############\n");
                printInOrder(users);
                printf("############\n");
                break;

            case 6:
                exit(0);
                break;

            default: 
                printf("Wrong input!\n");
                break;
        }

    }
    return 0;
}