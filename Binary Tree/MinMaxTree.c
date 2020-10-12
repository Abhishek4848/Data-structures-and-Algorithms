#include <stdio.h>
#include <stdlib.h>

struct bstnode
{
    int data;
    struct bstnode *llink, *rlink;
};

typedef struct bstnode Node;

Node *getnode(int ele)
{
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode-> data = ele;
    newnode->rlink = newnode->llink = NULL;
    return newnode;
}

Node *insert(Node* root, int ele)
{
    if (root == NULL)
    {
        root = getnode(ele);
    }
    else if(ele <= root->data)
    {
        root->llink = insert(root->llink, ele);
    }
    else
    {
        root->rlink = insert(root->rlink, ele);
    }
    return root;
}

// Last element in the left link of a branch is the minimum value
int minEle(Node *root)
{
    Node *aux = root;
    if(root == NULL)
    {
        printf("Empty tree");
        return -1;
    }
    while(aux->llink != NULL)
    {
        aux = aux->llink;
    }
    return aux->data;
}

// Last element in the right link of a branch is the maximum element
int maxEle(Node *root)
{
    Node *aux = root;
    if (root == NULL)
    {
        printf("Empty tree");
        return -1;
    }
    while (aux->rlink != NULL)
    {
        aux = aux->rlink;
    }
    return aux->data;
}

int main()
{
    Node *root = NULL;
    int ch = 1;
    int ele;
    printf("1. Insert \n2. Minimum element \n3. Maximum element \n4. Exit");
    while(ch != 0)
    {
        printf("\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter element to be inserted: ");
                    scanf("%d",&ele);
                    root = insert(root, ele);
                    break;
            case 2: printf("Minimum element is: %d",minEle(root));
                    break;
            case 3: printf("Maximum element is: %d",maxEle(root)); 
                    break;
            case 4: exit(0);
                    break;
            default: printf("Invalid choice !!!");
                     break;   
        }
    }
    return 0;
}