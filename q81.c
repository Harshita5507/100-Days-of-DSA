/* Problem Statement:
Implement a Queue using a linked list supporting enqueue and dequeue operations.

Input Format:
- First line contains integer N
- Next N lines contain queue operations

Output Format:
- Print dequeued elements
- Print -1 if dequeue is attempted on an empty queue.     */


#include <stdio.h>
#include <stdlib.h>


struct node
{
    int data;
    struct node* next;
};


struct node *front=NULL;
struct node* rear=NULL;




void enqueue(int val)
{
    struct node* newnode= (struct node*) malloc(sizeof(struct node));
    newnode->data=val;
    newnode->next=NULL;

    if (rear==NULL)
    {
        front=rear=newnode;
        return;
    }
    rear->next=newnode;
    rear=newnode;
}


int dequeue()
{
    struct node* temp=front;
    if(temp == NULL)
    {
        printf("empty linked list. nothing to dequeue.");
    }

    front=temp->next;
    free(temp);
}


void display()
{
    if (front==NULL)
    {
        printf("empty queue.\n");
    }

    else
    {
        struct node* temp=front;
        while(temp !=NULL)
        {
            printf("%d", temp->data);
            temp=temp->next;
        }
        printf("\n");
    }

}




int main()
{
    int n,i,val;
    char op[10];

    printf("enter number of nodes, n: ");
    scanf("%d", &n);

do
{
    for (int i = 0; i < n; i++) 
    {
        scanf("%s", op);
    
    if (op[0]=='e')
    {
        printf("enter value: ");
        scanf("%d", &val);
        enqueue(val);
    }

    else if (op[0]=='d')
    {
        dequeue();
    }

    else if (op[0]=='p')
    {
        display();
    }

    }
}  while(op[0]!='E');
      
    return 0;
   
}