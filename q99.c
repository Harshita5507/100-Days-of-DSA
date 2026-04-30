/* Problem: BST Search
Implement the solution for this problem.

Input:
- Input specifications

Output:
- Output specifications   */ 



#include <stdio.h>
#include <stdlib.h>


struct node
{
    int data;
    struct node* left;
    struct node* right;
};


struct node* insert_node(struct node* root, int val)
{
    if (root==NULL)
    {
        struct node* newnode= (struct node*) malloc(sizeof(struct node));
        newnode->data=val;
        newnode->left=NULL;
        newnode->right=NULL;
        return newnode;
    }

    if(val <root->data)
    {
        root->left= insert_node(root->left, val);
    }

    else
    {
        root->right= insert_node(root->right, val);
    }
    return root;

}



int search(struct node* root, int key)
{
    if (root==NULL)
        return 0;


    if (root->data==key)
        return 1;
    

    if (key < root->data)
    return search(root->left, key);
    
    else
    return search(root->right, key);

}




int main() {
    struct node* root = NULL;

    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter %d values:\n", n);
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        root = insert_node(root, val);   // ← must reassign root!
    }

    int key;
    printf("Enter value to search: ");
    scanf("%d", &key);

    if (search(root, key))
        printf("%d found in BST\n", key);
    else
        printf("%d not found in BST\n", key);

    return 0;
}
