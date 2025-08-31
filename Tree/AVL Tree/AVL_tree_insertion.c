#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct node
{
    int data;
    struct node *left;
    struct node *right; 
    int height; 
};

struct node* create_node(int data)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

int tree_height(struct node* node)
{
    if(node == NULL)
        return 0;
    // Conidersing the height of tree starts with '0'
    int left_tree_height = tree_height(node->left);
    int right_tree_height = tree_height(node->right);

    return fmax(left_tree_height, right_tree_height) + 1;
    //max(left tree height, right tree height)

}

int Balance_factor_of_node(struct node* node)
{
    if(node == NULL)
        return 0;
    
    return tree_height(node->left) - tree_height(node->right);
}

// right rotation
struct node* right_rotation(struct node* node)
{
    // Temporary storing node
    struct node* T1 = node->left;
    struct node* T2 = T1->right;

    // Rotation
    T1->right = node;
    node->left = T2;

    // After Rotation height need to ajustsed
    node->height = 1 + fmax(tree_height(node->left), tree_height(node->right));
    T1->height = 1 + fmax(tree_height(T1->left), tree_height(T1->right));

    // As T1 becomes root after Right Rotation
    return T1;

}

// left rotation
struct node* left_rotation(struct node* node)
{
    // Temporary storing node
    struct node* T1 = node->right;
    struct node* T2 = T1->left;

    // Rotation
    T1->left = node;
    node->right = T2;

    // Hieght updation after insertion

    node->height = 1 + fmax(tree_height(node->left), tree_height(node->right));
    T1->height = 1 + fmax(tree_height(T1->left), tree_height(T1->right));

    // As T1 becomes root after Left Rotation
    return T1;

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

    // upadating height of ancestor node
    node->height = 1 + fmax(tree_height(node->left), tree_height(node->right));
    
    int balance_factor = Balance_factor_of_node(node);

    // Imbalance checking

    // 1. LL-> Right Rotation
    if(balance_factor > 1 && data < node->left->data) // checking balancing factor of node and if its cause due to insertion in leftsubtree 
        return right_rotation(node);

    // 2. RR-> Left Rotation
    if(balance_factor < -1 && data > node->right->data) // checking balancing factor of node and if its cause due to insertion in rightsubtree 
        return left_rotation(node);

    // 3. LR -> LR rotation  
    if(balance_factor > 1 && data > node->left->data)  // cause due to insertion in leftsubtree of node
    {
        node->left = left_rotation(node->left); 
        return right_rotation(node); 
    }

    // 4. RL-> RL Rotation
    if(balance_factor < -1 && data < node->right->data) // cause due to insertion in rightsubtree of node
    {
        node->right = right_rotation(node->right);
        return left_rotation(node);
    }
    
    return node;
}

// Inorder Traversal [L Root R]
void inorder(struct node* root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

int main(void)
{
    struct node *root=NULL;
    int no_of_nodes =0;

    // static insertion in tree
    /*root = insert_node(root,15);
    root = insert_node(root, 10);
    root = insert_node(root,20);
    root = insert_node(root, 5);
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
    printf("Inorder travesal of tree:\n");
    inorder(root);
    return 0;
}