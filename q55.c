/* Problem: Circular Linked List Creation and Traversal - Implement using linked list with 
dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the circular linked list elements starting from head, space-separated

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50

Explanation:
Last node's next points to head. Traverse from head until returning to head to avoid infinite loop.   */


#include <stdio.h>
#include <stdlib.h>


struct node
{
    int data;
    struct node* next;
};



struct node* createnode(int value)
 {
    struct node* x= (struct node*)malloc(sizeof(struct node));
    x->data=value;
    x->next=NULL;
    return x;
 }



 struct node* insert_node(struct node* head, int value)
 {
    struct node* newnode=createnode(value);
    struct node* temp=head;


    if (head == NULL)
    {
        newnode->next = newnode;   // point to itself — first circular link
        return newnode;
    }
    

    while(temp->next !=head)
    {
        temp= temp->next;
    }
    temp->next= newnode;
    newnode->next=head;
    return head;
    
 }


 
void display(struct node *head) 
{
     if (head == NULL) 
     return; 

    struct node* temp = head;
    do                            
    {
        if (temp->next != head)
            printf("%d ", temp->data);
        else
            printf("%d", temp->data);
        temp = temp->next;
    } 
    while (temp != head);

    printf("\n");
}

  


 int main()
 {
    int n,i,value;
    struct node* head=NULL;
    struct node* temp=head;

    printf("enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &value);
        
        head = insert_node(head, value); 
    }    

    head=insert_node(head,value);


    display(head);

    return 0;
 }

