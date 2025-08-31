#include<stdio.h>
#include<stdlib.h>

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

struct node* minValueNode(struct node* node)
{
    struct node* current = node;
    // Find the leftmost node in rightmost tree 
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

struct node* deleteNode(struct node* root, int data)
{
    if (root == NULL)
        return root;

    // Traverse to find the node to delete
    if (data < root->data)
        root->left = deleteNode(root->left, data);

    else if (data > root->data)
        root->right = deleteNode(root->right, data);

    else
    {
        // Node with one child or no child
        if (root->left == NULL)
        {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children
        struct node* temp = minValueNode(root->right); // find inorder succesor
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}



struct node* inorder(struct node* node)
{
    if(node == NULL)
        return NULL;
    
    inorder(node->left);
    printf("%d ",node->data);
    inorder(node->right);
}

struct node* preorder(struct node* node)
{
    if(node == NULL)
        return NULL;
    
    printf("%d ",node->data);
    preorder(node->left);
    preorder(node->right);
}

struct node* postorder(struct node* node)
{
    if(node == NULL)
        return NULL;
    
    postorder(node->left);
    postorder(node->right);
    printf("%d ",node->data);
}

int main(void)
{
    struct node *root=NULL;
    int no_of_nodes =0;

    // static insertion in tree
    root = insert_node(root,15);
    root = insert_node(root, 10);
    root = insert_node(root,20);
    root = insert_node(root, 45);
    root = insert_node(root, 9);
    root = insert_node(root, 12);
    root = insert_node(root, 8); 
    

    // Dynamic insertion in tree 
   /* printf("Enter the no. of nodes: ");
    scanf("%d", &no_of_nodes);
    while(no_of_nodes)
    {
        int data;
        printf("Enter the data: ");
        scanf("%d",&data);
        root = insert_node(root, data);
        no_of_nodes--;
    }
*/
    // All traversal
    printf("Inorder traverasal of tree:\n");
    inorder(root);

    printf("\nPreorder traverasal of tree:\n");
    preorder(root);

    printf("\nPostorder traverasal of tree:\n");
    postorder(root);
    
    // deletion
    root = deleteNode(root,45);
    // All traversal
    printf("\n-----After deletion:------\n");

    printf("Inorder traverasal of tree:\n");
    inorder(root);

    printf("\nPreorder traverasal of tree:\n");
    preorder(root);

    printf("\nPostorder traverasal of tree:\n");
    postorder(root);

    return 0;
}