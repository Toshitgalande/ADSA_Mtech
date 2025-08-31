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
    struct node *newnode  = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left =  NULL;
    newnode->right = NULL;
    return newnode;
}

// Inorder traverasl [L, Root, R]
 void inorder(struct node* newnode)
{
    if(newnode != NULL)
    {
    inorder(newnode->left);
    printf("%d ",newnode->data);
    inorder(newnode->right);
    }

 }

 // Preorder traversal [Root, L, R]
 void preorder(struct node* newnode)
 {
    if(newnode != NULL)
    {
    printf("%d ",newnode->data);
    preorder(newnode->left);
    preorder(newnode->right);
    }
 }

 // postorder traversal [L, R, Root]
 void postorder (struct node* newnode)
 {
    if(newnode != NULL)
    {
    postorder(newnode->left);
    postorder(newnode->right);
    printf("%d ",newnode->data);
    }
 }

int main(void)
{
    struct node* root = createnode(10);
    
    // Insertion in Binary Tree
    root->left = createnode(2);
    root->right = createnode(33);
    root->left->left = createnode(41);
    root->right->right = createnode(65);
    root->left->left->left = createnode(98);
    root->right->right->right = createnode(51);

    printf("Preorder traversal: ");
    inorder(root);
    printf("\nInorder travesal: ");
    preorder(root);
    printf("\nPostorder traversal: ");
    postorder(root);
    return 0;
}