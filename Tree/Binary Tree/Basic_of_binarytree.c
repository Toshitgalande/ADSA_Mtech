#include<stdio.h>
#include<stdlib.h>

// Using struct we created a node data structure.
struct node
{
    int data;
    struct node *left;
    struct node *right;  
};

struct node* create_node(int data)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;

    return newnode;
}

int main(void)
{
    struct node *root;

    //insertion of nodes in binary tree
    root = create_node(45);
    root->left = create_node(74);
    root->right = create_node(21);
    root->left->left = create_node(85);
    root->left->right = create_node(14);
    root->right->left = create_node(23);

    return 0;
}