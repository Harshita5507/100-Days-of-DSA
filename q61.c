
/* Problem: Implement a stack data structure using an array with the following operations: push, pop, 
and display.
Input:
- First line: integer n (number of operations)
- Next n lines: operation type and value (if applicable)
  - 1 value: push value
  - 2: pop
  - 3: display

Output:
- For display: print stack elements from top to bottom
- For pop: print popped element or 'Stack Underflow'

Example:
Input:
5
1 10
1 20
3
2
3

Output:
20 10
20
10       */



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
        printf("%d", value);
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
        printf("%d", stack[top]);
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
    int i,choice,value;
    scanf("%d", &n);
    stack = (int *)malloc(n * sizeof(int));
    


while(1)
{
    printf("\n Stack Operation Format: \n");
    printf("1. Value: Push value\n");
    printf("2. Pop \n");
    printf("3. Display \n");
    

    printf("enter choice: ");
    scanf("%d", &choice);


    switch(choice)
    {
        case 1:
        printf("enter value: ");
        scanf("%d", &value);
        push(value);
        break;

        case 2:
        pop();
        break;


        case 3:
        display();
        break;

        default:
        printf("enter valid choice.");
        break;

    }
}



    return 0;
}
