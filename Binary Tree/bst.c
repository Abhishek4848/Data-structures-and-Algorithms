#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *llink;
    struct node *rlink;
};

typedef struct node bst_node;

bst_node *getnode (int ele)
{
    bst_node *newnode = (bst_node*)malloc(sizeof(bst_node));
    newnode->data = ele;
    newnode->llink = newnode->rlink = NULL;
    return newnode;
}

//Insertiion of new node into BST using recursion
bst_node *insert(bst_node *root, int ele)
{
    if (root == NULL)
    {
        root = getnode(ele); //This 'root' variable is a local variable to this function
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

bst_node *search(bst_node *root, int ele)
{
    if (root == NULL) return 0;
    if (ele == root->data) return 1;
    else if (ele <= root->data) return(search(root->llink, ele));
    else if (ele > root->data) return (search(root->rlink, ele));
}

int main()
{
    bst_node *root = NULL;
    int ch = 1;
    int ele, srch;
    printf("1. Insert \n2. Search \n3. Exit");
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
            case 2: printf("Enter element to be searched: ");
                    scanf("%d",&srch);
                    if(search(root, srch))
                    {
                        printf("Found ");
                    }
                    else
                    {
                        printf("Missing");
                    } 
                    break;
            case 3: exit(0);
                    break;
            default: printf("Invalid choice !!!");
                     break;   
        }
    }
    return 0;
}