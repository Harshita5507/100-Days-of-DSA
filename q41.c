/* Problem: Create and Traverse Singly Linked List
Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the result

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50.   */


#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};


struct node* createnode(int value)
{
    struct node* x=(struct node*) malloc (sizeof(struct node));
    x->data= value;
    x->next=NULL;
    return x;
}


struct node* insert_node(struct node* head, int value)
{
    struct node* newnode= createnode(value);
    struct node* temp=head;

     if(head==NULL)
    {
        return newnode;
    }
    while(temp->next != NULL)
    {
        temp=temp->next;
    }

    temp->next=newnode;
    return head;
}


void display(struct node* head)
{
    struct node* temp=head;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp=temp->next;
    }
}

int main()
{
    int n,i,value;
    struct node* head=NULL;

    printf("enter n: ");
    scanf("%d", &n);

    
    printf("enter n spaced- integers: ");
    for(i=0;i<n;i++)
    {
        scanf("%d ", &value);
        head=insert_node(head, value);
    }
    
    display(head);
    return 0;
}
