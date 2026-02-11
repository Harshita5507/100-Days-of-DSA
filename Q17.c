/*
Problem: A secret system stores code names in forward order. To display them in mirror format, you must transform the given code name so that its characters appear in the opposite order.
Input:
- Single line: a lowercase string containing only alphabetic characters (no spaces)

Output:
- Print the transformed code name after applying the mirror operation.

Example:
Input:
hello

Output:
olleh
Explanation: The first character moves to the last position, the second to the second-last, and so on until the entire string is mirrored.   */


#include <stdio.h>


void reverse_string(char *string)
{
    int left=0;
    int right=0;

    while(string[right] != '\0')
    {
        right++;

    }
    right--;

    while(left<right)
    {
        char temp= string[left];
        string[left]= string[right];
        string[right]= temp;

    left++;
    right--;
    }
}


int main()
{
    int i;
    char string[100];

    printf("enter string: ");

    scanf("%s", &string);

    reverse_string(string);


    printf("%s ", string);

    return 0;
}