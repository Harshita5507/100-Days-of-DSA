/* Problem: Count Nodes in Linked List

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the result

Example:
Input:
10 20 30 40 50

Output:
5        */

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};



struct node* createnode (int value)
{
    struct node* newnode=(struct node*) malloc (sizeof(struct node*));
    newnode->data=value;
    newnode->next=NULL;
    return newnode;
}



struct node* insert_node(struct node* head, int value)
{
    struct node* newnode= createnode(value);
    struct node* temp=head;

    if(head==NULL)
    return newnode;

    while(temp->next !=NULL)
    {
        temp=temp->next;
    }

    temp->next=newnode;
    return head;
}


int count=0;
int count_node(struct node* head)
{
    struct node* temp=head;
    while(temp->next !=NULL)
    {
        temp=temp->next;
        count++;
    }
    printf("Count of nodes: %d", count);
    return count;
}


int main()
{
    int value,n,i;
    struct node* head=NULL;
    
    printf("enter n: ");
    scanf("%d", &n);

    printf("enter value: ");
    for(i=0;i<n;i++)
    {
        scanf("%d", &value);
        head=insert_node(head, value);
    }
    count_node(head);

    return 0;
}
