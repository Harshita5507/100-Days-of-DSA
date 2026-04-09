/*Problem Statement: Given a queue of integers, reverse the queue using a stack.
Input Format:
- First line contains integer N
- Second line contains N space-separated integers

Output Format:
- Print the reversed queue
Example:
Input:
5
10 20 30 40 50

Output:
50 40 30 20 10.    */


#include <stdio.h>
#include <stdlib.h>
#define MAX 100


int n,i;
int s1[MAX], s2[MAX],queue[MAX];
int top1=-1, top2=-1;


void enqueue(int val)
{
    if(top1==MAX-1)
    {
        printf("queue is full.");
    }
    s1[++top1]=val;
}



void shift() 
{
    while (top1 >= 0)
        s2[++top2] = s1[top1--];
}


void display_reversed()
{
    for(int j=top2; j>=0; j--)
    {
        printf("%d ",s2[j]);
    }
    printf("\n");
}


int main()
{
    int val;
    printf("enter n: ");
    scanf("%d",&n);

    printf("enter the elements of queue: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&val);
        enqueue(val);
    }

    shift();

    printf("reversed queue: ");
    display_reversed();

    return 0;

}
