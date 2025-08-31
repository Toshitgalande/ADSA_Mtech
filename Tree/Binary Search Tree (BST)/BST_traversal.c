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

struct node* insert_node(struct node* newnode, int data)
{
    if(newnode == NULL)
         return createnode(data);

    if(data < newnode->data)
        newnode->left = insert_node(newnode->left, data);
    else
        newnode->right = insert_node(newnode->right, data);
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
    struct node* root = NULL;
    int no_of_nodes =0;
    // Static insertion
    /*root = insertnode(root,40);
    root = insertnode(root,23);
    root = insertnode(root,75);
    root = insertnode(root,17);
    root = insertnode(root,-6);
    root = insertnode(root,47);
    root = insertnode(root,89);
    root = insertnode(root,52);*/

    // Dynamic insertion in tree 
    printf("Enter the no. of nodes: ");
    scanf("%d", &no_of_nodes);
    while(no_of_nodes)
    {
        int data;
        printf("Enter the data: ");
        scanf("%d",&data);
        root = insert_node(root, data);
        no_of_nodes--;
    }

    // All traversal
    printf("Inorder traverasal of tree:\n");
    inorder(root);

    printf("\nPreorder traverasal of tree:\n");
    preorder(root);

    printf("\nPostorder traverasal of tree:\n");
    postorder(root);

    return 0;
}