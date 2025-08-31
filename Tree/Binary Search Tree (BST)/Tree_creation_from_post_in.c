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

struct node* build_tree(int inorder[], int postorder[], int instart, int inend, int poststart, int postend)
{
    if(instart > inend || poststart > postend)
        return NULL;
    
    int root_data = postorder[postend];
    struct node* node = create_node(root_data);

    int root_index = inorder_root_index(inorder, root_data, instart, inend);

    int right_subtree = inend - root_index;
    int left_subtree = root_index - instart;
    
    
    node->left = build_tree(inorder, postorder, instart, root_index -1, poststart, poststart+left_subtree-1);
    node->right = build_tree(inorder, postorder, root_index+1, inend, poststart+left_subtree, postend-1);
    
    return node;
}

// preorder traversal [Root L R]
struct node* preorder(struct node* node)
{
    if(node == NULL)
        return NULL;
    
    printf("%d ",node->data);
    preorder(node->left);
    preorder(node->right);
}

int main(void)
{
    int inorder[]={8, 9, 10, 12, 15, 20, 45};
    int postorder[]={8, 9, 12, 10, 45, 20, 15 };

    // Building tree
    int size = sizeof(inorder) / sizeof(int);
    struct node* root = build_tree(inorder, postorder, 0, size - 1, 0, size - 1);
    
    printf("Preorder traversal from postorder & inorder:\n");
    preorder(root);
    return 0;
}