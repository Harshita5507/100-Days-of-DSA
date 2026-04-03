
/* Problem: Circular Queue Using Array - Implement using linked list with dynamic memory allocation.
Input:
- First line: integer n (number of elements to enqueue)
- Second line: n space-separated integers
- Third line: integer m (number of dequeue operations)

Output:
- Print queue elements from front to rear after operations, space-separated.

Example:
Input:
5
10 20 30 40 50
2

Output:
30 40 50 10 20

Explanation:
Use array and front/rear pointers. Rear wraps around to start after reaching array end. 
Dequeue removes elements from front. Display remaining elements in correct order.       */



#include <stdio.h>
#include <stdlib.h>


int n, *queue;
int front=-1;
int rear=-1;



void Enqueue(int val)
{

    if (front != -1 && (rear+1)%n == front)
    {
        printf("queue overflow.");
    }

    else if(front==-1 && rear==-1)
    {
        front=rear=0;
    }
    
    else
    {
        rear= (rear+1)%n;
    }

    queue[rear]=val;
}




int Dequeue()
{
    if (front==-1)
    {
        printf("empty queue."); 
    }
    else
    {
        front= (front+1)%n;
    }
}




void display()
{
    if (front==-1)
    {
        printf("Queue empty.");
    }

    else
    {
        int count = (rear - front + n) % n + 1;

        for(int i=0; i<count; i++) 
        printf("%d ", queue[(front+i)%n]);
    }
}




int main()
{
    int i,m,val;

    printf("enter n elements to enqueue: ");
    scanf("%d", &n);

    queue = malloc(n * sizeof(int));


    printf("enter the %d elements: ", n);
    for(i=0;i<n;i++)
    {
        scanf("%d", &val);
        Enqueue(val);
    }


    

    printf("enter m, number of dequeues to perform: ");
    scanf("%d", &m);

    for(i=0;i<m;i++)
    {
        Dequeue();
    }

    printf("post dequeuing: \n");
    display();

    
    return 0;
}
