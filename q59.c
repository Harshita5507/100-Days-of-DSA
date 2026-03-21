/* Problem: Polynomial Using Linked List - Implement using linked list with dynamic memory allocation.
Input:
- First line: integer n (number of terms)
- Next n lines: two integers (coefficient and exponent)

Output:
- Print polynomial in standard form, e.g., 10x^4 + 20x^3 + 30x^2 + 40x + 50
Example:
Input:
5
10 4
20 3
30 2
40 1
50 0

Output:
10x^4 + 20x^3 + 30x^2 + 40x + 50

Explanation:
Each node stores coefficient and exponent. Traverse nodes to print polynomial in decreasing exponent order.  */


#include <stdio.h>
#include <stdlib.h>

struct term
{
    int coeff;
    int exp;
    struct term* next;
};



struct term* createterm(int coeff,int exp)
{
    struct term* x= (struct term*) malloc(sizeof(struct term));
    x->coeff = coeff;
    x->exp = exp;
    x->next = NULL;
    return x;
}


void printpolynomial(struct term* head)
{
    struct term* current = head;
    int first = 1;
    

    while (current != NULL) 
    {
        if (!first && current->coeff > 0) 
        {
            printf(" + ");
        } 

        else if (current->coeff < 0) 
        
        {
            printf(" - ");
        }

        
        int abscoeff = abs(current->coeff);
        
        if (current->exp == 0) 
        {
            printf("%d", abscoeff);
        } 

        else if (current->exp == 1) 
        {
            printf("%dx", abscoeff);
        }

        else 
        {
            printf("%dx^%d", abscoeff, current->exp);
        }
        
        first = 0;
        current = current->next;
    }
    printf("\n");


}



int main()
{
    int n,i,exp,coeff;
    struct term* head=NULL;
    struct term* tail=NULL;

    scanf("%d", &n);

    scanf("%d %d", &coeff, &exp);

    struct term* newterm= createterm(coeff,exp);

    if (head=NULL)
    {
        head=tail=newterm;
    }

    else
    {
        tail->next=newterm;
        tail=newterm;
    }


    printpolynomial(head);


    return 0;
}