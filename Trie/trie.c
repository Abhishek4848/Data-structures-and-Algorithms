#include<stdio.h>
#include<stdlib.h>
#define max_size 255

int length,top;
char word[100];

struct trienode
{
    struct trienode *child[max_size];
    int endofword;
};

typedef struct trienode trienode;

trienode *getnode()
{
    trienode *temp = (trienode*)malloc(sizeof(trienode));
    for(int i = 0; i < max_size; i++)
    {
        temp->child[i] = NULL; //initially all variables are assigned to NULL
    }
    temp->endofword = 0; // Assigning end of word to 0=>word not complete; 1=>complete word
    return(temp);
}

void insert(trienode *root, char *key)
{
    trienode *cursor = root;
    for(int i = 0; key[i] != '\0'; i++)
    {
        int index = key[i];
        if(cursor->child[index] == NULL)
        {
            cursor->child[index] = getnode();
        }
        cursor = cursor->child[index];
    }
    cursor->endofword = 1;
}

void display(trienode* root)
{
    trienode *cur = root;
    int i,j;
    for(i = 0; i < max_size; i++)
    {
        if(cur->child[i] != NULL)
        {
            word[length++] = i;
            if(cur->child[i]->endofword == 1)
            {
                printf("\n");
                for(j = 0; j < length; j++)
                {
                    printf("%c",word[j]);
                }
            }
            display(cur->child[i]);
        }
    }
    length--;
    return;
}

int search(trienode *root, char *key)
{
    trienode *cur  = root;
    for(int i = 0; key[i] != '\0'; i++)
    {
        int index = key[i];
        if(cur->child[index] == NULL)
        {
            return 0;
        }
        cur = cur->child[index];
    }
    if(cur->endofword ==1)
    {
        return 1;
    }
    return 0;
}

void main()
{
    int ch = 1;
    char str[100], key[100];
    trienode *root = getnode();
    printf("1. Insert \n2. Display \n3. Search \n4. Exit");
    while(ch != 0)
    {
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter string to be inserted:");
                    scanf("%s",str);
                    insert(root,str);
                    break;
            case 2: printf("The elements in the trie are:");
                    display(root);
                    break;
            case 3: printf("Enter string to be searched:");
                    scanf("%s",key);
                    int k = search(root, key);
                    if (k == 1)
                    {
                        printf("Found");
                    }
                    else
                    {
                        printf("Missing");
                    }
                    break;
            case 4: exit(0);
                    break;
            default: printf("Invalid choice");
                    break;
        }
    }
}