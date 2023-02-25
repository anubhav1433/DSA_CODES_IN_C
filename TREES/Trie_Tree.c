#include <stdio.h>
#include <stdlib.h>

#define letter 26
#define charlen 10 // max char of any word

struct node
{
    struct node *branch[letter];
    int is_word;
};

typedef struct node trie;

int len;
char stword[charlen];

trie *getnode()
{
    trie *new;
    new = (trie *)malloc(sizeof(trie));
    for (int ch = 0; ch < letter; ch++)
    {
        new->branch[ch] = NULL;
    }
    new->is_word = 0;
    return new;
}

trie *insert(trie *root, char word[])
{
    trie *save_root;
    if (!root)
    {
        root = getnode();
        return root;
    }
    save_root = root;
    for (int i = 0; i < charlen; i++)
    {
        if (word[i] =='\0')
            break;
        else
        {
            if (!root->branch[word[i] - 'a'])
                root->branch[word[i] - 'a'] = getnode();
            root = root->branch[word[i] - 'a'];
        }
    }
    if (root->is_word == 1)
    {
        printf("duplicated word");
    }
    else
    {
        root->is_word = 1;
    }
    return save_root;
}

void display(trie *root)
{
    for(int i=0;i<letter;i++)
    {
        if(root->branch[i]!=NULL)
        {
            stword[len++]=(i+'a');
            if(root->branch[i]->is_word==1)
            {
                printf("\n");
                for(int j=0;j<len;j++)
                    printf("%c",stword[j]);
            }
            display(root->branch[i]);
        }
    }
    len--;
}

int main()
{
    trie *root = NULL, *check;
    int ch, len_key, i;
    char str[100];
    do
    {
        printf("1.insert 2.display");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("enter string");
            scanf("%s", str);
            root = insert(root, str);
            break;
        case 2:
            len=0;
            display(root);
            break;
        }
    } while (ch != 3);
}