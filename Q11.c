/* Problem: Given a sorted array of n integers, remove duplicates in-place. Print only unique elements in order.

Input:
- First line: integer n
- Second line: n space-separated integers (sorted array)

Output:
- Print unique elements only, space-separated

Example:
Input:
6
1 1 2 2 3 3

Output:
1 2 3

Explanation: Keep first occurrence of each element: 1, 2, 3.  */

#include <stdio.h>

int main()
{
    int n,i;
    printf("Enter n: ");
    scanf("%d", &n);

    printf("Enter the elements of the array:");
    int array[n];

    for(i=0;i<n;i++)
    {
        scanf("%d", &array[i]);
    }
    
    int x=0;
    for(i=1;i<n;i++)
    {
        if (array[i] != array[x])
         {
            x=x+1;
            array[x]= array[i];
         }
    }
      printf("Updated array with first occurrences: ");
       for(i=0;i<=x;i++)
        {
         printf("%d ", array[i]);
        }

    return 0;
}