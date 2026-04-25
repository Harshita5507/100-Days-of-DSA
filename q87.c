/* Problem Statement:
Perform inorder, preorder, and postorder traversals of a given binary tree.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 represents NULL)

Output Format:
- Print inorder, preorder, and postorder traversals

Example:
Input:
7
1 2 3 4 5 6 7

Output:
4 2 5 1 6 3 7
1 2 4 5 3 6 7
4 5 2 6 7 3 1    */




#include <stdio.h>
#include <stdlib.h>


struct node
{
    int data;
    struct node* left;
    struct node* right;
};



struct node* create(int val)
{
    struct node* new= (struct node*)malloc(sizeof(struct node));
    new->data=val;
    new->left=NULL;
    new->right=NULL;
    return new;
}





struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;

    struct Node* root = createNode(arr[0]);
    struct Node* queue[n];
    int front = 0, rear = 0;

    queue[rear++] = root;
    int i = 1;

    while (i < n) 
    {
        struct Node* current = queue[front++];

        if (i < n && arr[i] != -1) 
        {
            current->left = create(arr[i]);
            queue[rear++] = current->left;
        }
        i++;

        if (i < n && arr[i] != -1) 
        {
            current->right = create(arr[i]);
            queue[rear++] = current->right;
        }

        i++;
    }
    return root;
}








void preorder(struct node* root)
{
    if (root==NULL)
    {
        return NULL;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}


void inorder(struct node* root)
{
    if (root==NULL)
    {
        return NULL;
    }

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}


void postorder(struct node* root)
{
    if (root== NULL)
    return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);

}





int main()
{
    int N,i, val;
    struct node* root= NULL;


    printf("enter number of nodes: ");
    scanf("%d ",&N);


    printf("enter elements: ");
    for (i=0 ;i<N; i++)
    {
        scanf("%d ", &val);
        if (val != -1)
        {
            root= insert(root, val);
        }
    }


    preorder(root);
    inorder(root);
    postorder(root);
    

    return 0;
}
