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