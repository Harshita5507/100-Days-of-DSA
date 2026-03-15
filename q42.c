/*Given the head of a singly linked list, return the middle node of the linked list.

If there are two middle nodes, return the second middle node. */

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};



struct node* createnode(int value)
{
    struct node* x=(struct node*) malloc(sizeof(struct node));
    x->data=value;
    x->next=NULL;
    return x;
}



struct node* insertnode(struct node* head, int value)
{
    struct node* temp=head;

    struct node* newnode=createnode(value);
    if(head==NULL)
    {
        head=newnode;
        return head;
    }

    while(temp->next !=NULL)
    {
        temp=temp->next;
    }

    if(temp->next==NULL)
    {
        temp->next=newnode;
        newnode->next=NULL;
    }
    return head;
}



void display(struct node* head)
{
    struct node* temp=head;

    while(temp !=NULL)
    {
        printf("%d ->", temp->data);
        temp=temp->next;
    }
}



struct node* middlenode(struct node* head) 
{
    struct node* fast= head;
    struct node* slow= head;

    while(fast != NULL && fast->next != NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}



int main()
{
    int n,i,value;
    struct node* head=NULL;

    printf("enter no of nodes: ");
    scanf("%d", &n);


    for(i=0;i<n;i++)
    {
        printf("enter value of node number %d: ", i+1);
        scanf("%d", &value);
    
        head=insertnode(head, value);
    }

    printf("Current List: \n");
    display(head);

    struct node* middle=middlenode(head);

    printf("\nMiddle node: %d", middle->data);

    return 0;
}
