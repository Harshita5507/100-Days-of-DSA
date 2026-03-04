/* Problem: Delete First Occurrence of a Key - Implement using linked list with dynamic memory allocation.
Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer key

Output:
- Print the linked list elements after deletion, space-separated

Example:
Input:
5
10 20 30 40 50
30

Output:
10 20 40 50

Explanation:
Traverse list, find first node with key, remove it by adjusting previous node's next pointer.  */

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* createnode(int value)
{
    struct node* x=(struct node*)malloc(sizeof(struct node));
    x->data=value;
    x->next=NULL;
    return x;
}


struct node* insert(struct node* head, int value)
{
    struct node* newnode=createnode(value);
    if(head==NULL)
    {
        head=newnode;
        return head;
    }
        struct node* temp=head;
        while(temp->next !=NULL)
        temp=temp->next;

        temp->next=newnode;
        return head;
}



struct node* delete_node(struct node* head, int key)
{
    if (head==NULL)
    {
        return NULL;
    }

    struct node* temp= head;
    if(key==0)
    {
        head= temp->next;
        free(temp);
        return head;
    }

    for(int i=0; temp!= NULL && i<key-1; i++)
    {
        temp=temp->next; 
    }

    struct node* next= temp->next->next;

    //unlink node from the list.
    free(temp-> next);
    
    temp->next=next;
    return head;
}




void display(struct node *head) 
{
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
}



int main()
{
    int n,key,value,choice;
    struct node* head=NULL;
    struct node* tail=NULL;


    scanf("%d", &n);
    for (int i = 0; i < n; i++) 
    {
        int value;
        scanf("%d", &value);
        head = insert(head, value);
    }
    
    printf("enter key at which first occurrence of node is to be deleted: ");
    scanf("%d", &key);

    head= delete_node(head,key);
    display(head);

    return 0;
}
