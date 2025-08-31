#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node* createnode(int data)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

struct node* insertnode(struct node* newnode, int data)
{
    if(newnode == NULL)
         return createnode(data);

    if(data < newnode->data)
        newnode->left = insertnode(newnode->left, data);
    else
        newnode->right = insertnode(newnode->right, data);
}

// inorder traverasl [L Root R}
void inorder(struct node* newnode)
{
    if(newnode != NULL)
    {
        inorder(newnode->left);
        printf("%d ",newnode->data);
        inorder(newnode->right);
    }
}

int main(void)
{
    struct node* root = NULL;
    root = insertnode(root,40);
    root = insertnode(root,23);
    root = insertnode(root,75);
    root = insertnode(root,17);
    root = insertnode(root,-6);
    root = insertnode(root,47);
    root = insertnode(root,89);
    root = insertnode(root,52);

    // checking if insertion is correct or not
    inorder(root);
    return 0;
}