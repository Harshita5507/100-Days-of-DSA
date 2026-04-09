/*Problem: Queue Using Array - Implement using linked list with dynamic memory allocation.
Input:
- First line: integer n (number of elements)
- Second line: n space-separated integers

Output:
- Print queue elements from front to rear, space-separated

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50

Explanation:
Use array and front/rear pointers. Enqueue inserts at rear, dequeue removes from front.
Display from front to rear.  */


#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int front=-1,rear=-1,queue[MAX];


int Enqueue(int element)
{

    if (front!=-1 &&front== (rear+1)%MAX)
    {
        printf("queue overflow.");
        return -1;
    }

    if (front==-1 && rear==-1)
    {
        front=rear=0;   
    }

    else
    {
        rear=(rear+1)%MAX;
    }
    queue[rear]=element;

}





int display()
{
    if (front==-1)
    {
        printf("Queue empty.");
    }

    else
    {
        for(int i=front; i<=rear;i++)
        {
            printf("%d ", queue[i]);
        }
    }
}



int main()
{
    int n,i,element,option;

    printf("enter n: ");
    scanf("%d", &n);

    printf("enter elements \n"); 

    for(i=0;i<n;i++)
    {
        printf("element %d: ", i+1);
        scanf("%d ", &element);
        Enqueue(element);
    }

    display();
    
    return 0;
}
