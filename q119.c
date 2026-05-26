/* q119: Problem Statement: Check whether a given binary tree satisfies the Min-Heap property.
Input Format:
- First line contains integer N
- Second line contains level-order traversal

Output Format:
- Print YES if valid Min-Heap, otherwise NO

Example:
Input:
7
1 3 5 7 9 8 10

Output:
YES

Explanation:
Each parent node must be smaller than its children.     */



#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};


struct node* createnode(int value)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;
    return newnode;
}



void insert(struct node** root, int value)
{
    struct node* newnode = createnode(value);
    if (*root == NULL)
    {
        *root = newnode;
    }
    else
    {
        struct node* temp = *root;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}



void display(struct node* root)
{
    struct node* temp = root;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}




int main()
{
    int N;
    scanf("%d", &N);

    int* arr = (int*)malloc(N * sizeof(int));

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Check Min-Heap property

    int isMinHeap = 1; // Assume it's a Min-Heap until proven otherwise

    for (int i = 0; i < N / 2; i++)
    {
        int leftChildIndex = 2 * i + 1;
        int rightChildIndex = 2 * i + 2;

        if (leftChildIndex < N && arr[i] > arr[leftChildIndex])
        {
            isMinHeap = 0;
            break;
        }
        if (rightChildIndex < N && arr[i] > arr[rightChildIndex])
        {
            isMinHeap = 0;
            break;
        }
    }

    if (isMinHeap)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }

    free(arr);
    return 0;
}