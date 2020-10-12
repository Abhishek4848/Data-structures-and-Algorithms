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

void preorder(Node *root)
{
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->llink);
    preorder(root->rlink);
}

void inorder(Node *root)
{
    if (root == NULL) return;
    inorder(root->llink);
    printf("%d ", root->data);
    inorder(root->rlink);
}

void postorder(Node *root)
{
    if (root == NULL) return;
    postorder(root->llink);
    postorder(root->rlink);
    printf("%d ", root->data);
}

int main()
{
    Node *root = NULL;
    int ch = 1;
    int ele;
    printf("1. Insert \n2. Preorder \n3. Inorder \n4. Post order \n5. Exit");
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
            case 2: preorder(root);
            break;
            case 3: inorder(root);
            break;
            case 4: postorder(root);
            break;
            case 5: exit(0);
                    break;
            default: printf("Invalid choice !!!");
                     break;   
        }
    }
    return 0;
}