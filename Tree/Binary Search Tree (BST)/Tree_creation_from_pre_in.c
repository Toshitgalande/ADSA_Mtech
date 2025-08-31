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
    // Return root index for current tree
int inorder_root_index(int inorder[], int data, int instart, int inend)
{
    for(instart; instart<=inend; instart++)
    {
        if(inorder[instart] == data)
            return instart;
    }
    return -1;
}

struct node* build_tree(int inorder[], int preorder[], int instart, int inend, int prestart, int preend)
{
    if(instart > inend || prestart > preend)
        return NULL;
    
    int root_data = preorder[prestart];
    struct node* node = create_node(root_data);

    int root_index = inorder_root_index(inorder, root_data, instart, inend);

    int left_subtree = root_index - instart;

    
    
    node->left = build_tree(inorder, preorder, instart, root_index -1, prestart+1, left_subtree+prestart);
    node->right = build_tree(inorder, preorder, root_index+1, inend, prestart+left_subtree+1, preend);

    return node;
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
    int inorder[]={8,9,10,12,15,20,45};
    int preorder[]={15,10,9,8,12,20,45};

    // Building tree
    int size = sizeof(inorder) / sizeof(int);
    struct node* root = build_tree(inorder, preorder, 0, size - 1, 0, size - 1);
    
    printf("Postorder traversal from preorder & inorder:\n");
    postorder(root);
    return 0;
}