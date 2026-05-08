/* Problem Statement:
Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Search Tree.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers
- Third line contains two node values

Output Format:
- Print the LCA value

Example:
Input:
7
6 2 8 0 4 7 9
2 8

Output:
6                */



#include <stdio.h>
#include <stdlib.h>


struct node
{
  int data;
  struct node* left;
  struct node* right;
};




struct node* create(int data)
{
  struct node* createnode= (struct node*) malloc (sizeof(struct node));
  createnode->data=data;
  createnode->left=NULL;
  createnode->right=NULL;
  return createnode;
}



struct node* insert(struct node* root, int val)
{
  if (root==NULL)
  return create(val);


  if (val < root->data)
        root->left = insert(root->left, val);  
        
        
    else if (val > root->data)
        root->right = insert(root->right, val); 

    return root;
}



int LCA(struct node* root, int p, int q)
{
  if (root==NULL)
  return 0;

  if (p<root->data && q< root->data)
  {
    return LCA(root-> left, p,q);
  }

  else if (p>root->data && q>root->data)
  {
    return LCA(root->right, p, q);
  }

  else
  {
    return root->data;
  }

}




int main()
{

  int n,i,val,p,q;
  struct node* root=NULL;

  printf("enter n: ");
  scanf("%d", &n);

  printf("enter the elements: ");
  for(int i=0; i<n;i++)
  {
    scanf("%d", &val);
    root= insert(root, val);
  }

  printf("enter two node values: ");
  scanf("%d %d", &p, &q);


  int lca_value= LCA(root,p,q);

  printf("LCA value: %d", lca_value);


  return 0;
}
