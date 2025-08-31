#include<stdio.h>
#include<stdlib.h>
#include<math.h>

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

struct node* insert_node(struct node* node, int data)
{
    if(node==NULL)
        return create_node(data);
    
    else
    {
        if(data > node->data)
            node->right = insert_node(node->right, data);

        else if(data < node->data)
            node->left = insert_node(node->left, data);     
    }
    return node;

}

struct node* inorder(struct node* node)
{
    if(node != NULL)
    {
        inorder(node->left);
        printf("%d ",node->data);
        inorder(node->right);
    }
}

struct node* preorder(struct node* node)
{
    if(node != NULL)
    {
        printf("%d ",node->data);
        preorder(node->left);
        preorder(node->right);
    }
}

void postorder(struct node* node)
{
    if(node != NULL)
    {
        postorder(node->left);
        postorder(node->right);
        printf("%d ",node->data);
    }
}

int tree_height(struct node* node)
{
    int left_tree_height=0;
    int right_tree_height=0;

    // Conidersing the height of tree starts with '0'
    if(node == NULL)
        return -1;

    else
    {
        left_tree_height = 1 + tree_height(node->left);
        right_tree_height = 1 + tree_height(node->right);        
    }

    return fmax(left_tree_height, right_tree_height);
    //max(left tree height, right tree height)

}


int main(void)
{
    struct node *root=NULL;
    int no_of_nodes =0;

    // static insertion in tree
   /* root = insert_node(root,15);
    root = insert_node(root, 10);
    root = insert_node(root,20);
    root = insert_node(root, 45);
    root = insert_node(root, 9);
    root = insert_node(root, 12);
    root = insert_node(root, 8); */

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
    
    printf("\nHeight of tree: %d ",tree_height(root));
    return 0;
}