//Transpose matrix.
/*  Given a 2D integer array matrix, return the transpose of matrix.
The transpose of a matrix is the matrix flipped over its main diagonal, switching the matrix's row 
and column indices.
Example 1:

Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[1,4,7],[2,5,8],[3,6,9]]
Example 2:

Input: matrix = [[1,2,3],[4,5,6]]
Output: [[1,4],[2,5],[3,6]].      */



#include <stdio.h>
int main()
{
    int m,n,i,j;
    
    printf("enter m(no. of rows): ");
    scanf("%d", &m);

    printf("enter n(no. of columns): ");
    scanf("%d", &n);

    int arr1[m][n];
    int transpose[n][m];


    //elements of first matrix.
    printf("enter elements of first matrix:");
    for(i=0;i<m;i++)
    {
        for(j=0; j<n; j++)
        {
            scanf("%d", &arr1[i][j]);
        }
    }

    //assign value.
     for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            transpose[j][i]= arr1[i][j];
        }
    }

    
    //print transpose matrix. 
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            printf(" %d ", transpose[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}


