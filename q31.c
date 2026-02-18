/*  Problem: Given an array of integers, count the frequency of each distinct element and print the result.
Input:
-First line: integer n (size of array)
-Second line: n integers
Output:
-Print each element followed by its frequency in the format element:count

Example:
Input:
5
1 2 2 3 1

Output:
1:2 2:2 3:1   */


#include <stdio.h>
int main()
{
    int n,i;
    int arr[n], visited[n];
    int count=0;

    printf("enter n: ");
    scanf("%d", &n);

    printf("enter integers: ");
    for(i=0; i<n; i++)
    {
        scanf("%d", &i);
        count++;
    }

    




    return 0;
}