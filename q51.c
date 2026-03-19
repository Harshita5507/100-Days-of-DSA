/*Problem: Doubly Linked List Insertion and Traversal - Implement using linked list with dynamic 
memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the linked list elements in forward order, space-separated

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50

Explanation:
Each node has data, next, prev. Insert nodes sequentially, traverse from head using next pointer.   */

#include <stdio.h>
#include <stdlib.h>


struct node
{
    int data;
    struct node* next;
    struct node* prev;
};


struct node* createnode(int value)
{
    struct node* x=(struct node*)malloc(sizeof(struct node));
    x->data=value;
    x->next=NULL;
    x->next=NULL;
    return x;
}



struct node* insert_node(struct node* head, int value)
{
    struct node* newNode = createnode(value);

    if (head == NULL)
        return newNode;

    struct node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;

    return head;
}




void display(struct node* head)
{
    struct node* temp = head;

    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Forward: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");

}



int main()
{
    int n,i,value;
    struct node* head= NULL; 

    printf("enter no of nodes: ");
    scanf("%d", &n);

    printf("enter elements: ");
    for(i=0;i<n;i++)
    {
        scanf("%d", &value);
        head=insert_node(head,value);
    }
    
    display(head);


    return 0;
}


