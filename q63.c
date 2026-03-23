/* Problem: Implement push and pop operations on a stack and verify stack operations.
Input:
- First line: integer n
- Second line: n integers to push
- Third line: integer m (number of pops)

Output:
- Print remaining stack elements from top to bottom.

Example:
Input:
5
10 20 30 40 50
2


Output:
30 20 10    */


#include <stdio.h>
#include <stdlib.h>


int n;
int top=-1;
int *stack;


int push(int value)
{
    if (top==n-1)
    {
        printf("stack overflow.");
    }

    else
    {
        stack[++top]=value;
    }
}



int pop()
{
    if(top==-1)
    {
        printf("stack underflow.");   
    }

    else
    {
        top--;
    }
}




int display()
{
    if (top==-1)
    {
        printf("empty stack.");
    }

    else
    {
        printf("stack (top to bottom): ");
        for(int i=top; i>=0; i--)
        {
            printf("%d ", stack[i]);
        }
    }
} 




int main()
{
    int i,value,n_pop;
    
    printf("enter n: ");
    scanf("%d", &n);

    stack= (int*)malloc(n* sizeof(int));

    for(i=0;i<n;i++)
    {
        scanf("%d", &value);
        push(value);
    }
    

    printf("Before Pop: ");
    display(); 


    printf("\nenter the number of pops to be performed: ");
    scanf("%d", &n_pop);

    for(i=0;i<n_pop;i++)
    {
        pop();
    }

    printf("After Pop: ");
    display();


    return 0;
}
