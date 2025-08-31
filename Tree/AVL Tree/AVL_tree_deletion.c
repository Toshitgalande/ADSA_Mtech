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
    newnode->height = 1;
    return newnode;
}

int height_of_node(struct node* node)
{
    if(node == NULL)
        return 0;
    else
        return node->height;
}

int Balance_factor_of_node(struct node* node)
{
    if(node == NULL)
        return 0;
    
    return height_of_node(node->left) - height_of_node(node->right);
}

// Function return next smalllest value from rightsubtree of node
struct node* minvalue(struct node* node)
{
    struct node* current = node;
    while(current || current->left != NULL)
    {
        current = current->left;
    }
    return current;
}

struct node* right_rotation(struct node* node)
{
    struct node* T1 = node->left;
    struct node* T2 = T1->right;

    // Rotation
    T1->right = node;
    node->left =T2;

    // Updating height after right rotation
    node->height = 1 + fmax(height_of_node(node->left), height_of_node(node->right));
    T1->height = 1 + fmax(height_of_node(T1->left), height_of_node(T1->right));

    //New root 
    return T1;
}  

struct node* left_rotation(struct node* node)
{
    struct node* T1 = node->right;
    struct node* T2 = T1->left;

    // Rotation
    T1->left = node;
    node->right = T2;

    // Hieght updation after left rotation
    node->height = 1 + fmax(height_of_node(node->left), height_of_node(node->right));
    T1->height = 1 + fmax(height_of_node(T1->left), height_of_node(T1->right));

    // As T1 becomes root
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
    node->height = 1 + fmax(height_of_node(node->left), height_of_node(node->right));
    
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

struct node* delete_node(struct node* node, int data)
{
    // Searching node in tree
    if(node == NULL)
        return NULL;

    if(data < node->data)
        node->left = delete_node(node->left, data);
    else if( data > node->data)
        node->right = delete_node(node->right, data);

    // node found
    else
    {
        // Node with one child or no child
        if (node->left == NULL)
        {
            struct node* temp = node->right;
            free(node);
            return temp;
        }
        else if (node->right == NULL)
        {
            struct node* temp = node->left;
            free(node);
            return temp;
        }

        // node having two children
        struct node* temp = minvalue(node->right);
        node->data = temp->data;
        node->right =delete_node(node->right, node->data);
    }

    // if tree become empty after deletion
    if(node == NULL)
        return NULL;

    // updating height of new node
    node->height = 1 + fmax(height_of_node(node->left), height_of_node(node->right));

    int balance_factor = Balance_factor_of_node(node);

    // LL -> right rotaion
    if(balance_factor > 1 && Balance_factor_of_node(node->left) >= 0)
        return right_rotation(node);

    // RR -> left rotation
    if(balance_factor < -1 && Balance_factor_of_node(node->right) <= 0)
        return left_rotation(node);

    // LR -> LR rotation
    if (balance_factor > 1 && Balance_factor_of_node(node->left) < 0)
    {
        node->left = left_rotation(node->left);
        return right_rotation(node);
    }
    // RL -> RL rotation
    if(balance_factor < -1 && Balance_factor_of_node(node->right) > 0)
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
    root = insert_node(root,15);
    root = insert_node(root, 10);
    root = insert_node(root,20);
    root = insert_node(root, 5);
    root = insert_node(root, 9);
    root = insert_node(root, 12);
    root = insert_node(root, 8); 

     // Dynamic insertion in tree 
    /*printf("Enter the no. of nodes: ");
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
    printf("Inorder travesal of AVL tree:\n");
    inorder(root);
    root = delete_node(root, 9);
    printf("\nInorder travesal after deletion from tree:\n");
    inorder(root);
    return 0;
}