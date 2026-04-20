/*  Problem Statement: Construct a Binary Tree from the given level-order traversal.
Input Format:
- First line contains integer N
- Second line contains N space-separated integers (-1 represents NULL)

Output Format:
- Print inorder traversal of the constructed tree.

Example:
Input:
7
1 2 3 4 5 -1 6

Output:
4 2 5 1 3 6     */



#include <stdio.h>
#include <stdlib.h>



struct node {
    int data;
    struct node* left;
    struct node* right;
};



struct node* createnode(int val)
{
    struct node* newnode= (struct node*) malloc(sizeof(struct node));
    newnode->data=val;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}



struct node* insert(struct node* root, int val)
{
    if (root==NULL)
    {
        root=createnode(val);
    }
    
    else if (val < root->data)
    {
        insert(root->left, val);
    }

    else if(val > root-> data)
    {
        insert(root->right, val);
    }
    return root;

}




int inorder(struct node* root)
{
    if (root==NULL)
    {
        return 0;
    }

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}



void display(struct node* root)
{
    if (root==NULL)
    return;

    printf("%d", root->data);
    display(root->left);
    display(root->right);

}



int main()
{
    int N,i, val;
    struct node* root= NULL;


    printf("enter number of nodes: ");
    scanf("%d",&N);


    printf("enter elements: ");
    for (i=0 ;i<N; i++)
    {
        scanf("%d", &val);
        if (val != -1)
        {
            root= insert(root, val);
        }
    }


    inorder(root);
    display(root);

    return 0;
}
