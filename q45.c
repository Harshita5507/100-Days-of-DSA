/* Problem: Merge Two Sorted Linked Lists - Implement using linked list with dynamic memory allocation.
Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print the merged linked list elements, space-separated
Example:
Input:
5
10 20 30 40 50
4
15 25 35 45

Output:
10 15 20 25 30 35 40 45 50

Explanation:
Compare nodes of both lists, append smaller to result, continue until all nodes are merged.   */


#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};



struct node* createnode(int value)
{
    struct node* x=(struct node*) malloc(sizeof(struct node));
    x->data=value;
    x->next=NULL;
    return x;  
}



struct node* insert_node(struct node* head, int value)
{
    struct node* x=createnode(value);
    x->data=value;
    x->next=NULL;
    return x;
}



struct node* merge_list(struct node* head1, struct node* head2)
{
    struct node* dummy= malloc(sizeof(struct node));
    struct node* tail=dummy;
    dummy->next=NULL;

    while(head1 != NULL && head2 != NULL)
    {
        if(head1->data <= head2->data)
        {
            tail->next=head1;
            head1= head1->next;  }

        else
        {
            tail->next= head2;
            head2= head2->next;  }
        tail= tail->next;
    }

    if(head1 != NULL)
    tail->next=head1;

    else
    tail->next=head2;

    return dummy->next;
}



void display(struct node* head)
{
    while(head !=NULL)
    {
        printf("%d ", head->data);
        head=head->next;
    }
    printf("NULL");
}




int main()
{
    int m,n,i,j,value1,value2;
    struct node* head1= NULL;
    struct node* head2= NULL;

    printf("enter n(no of integers in first linked list: )");
    scanf("%d", &n);

    printf("enter integers of first list: ");
    for(i=0;i<n;i++)
    {
        scanf("%d", &value1);
        head1 = insert_node(head1, value1);
    }

    printf("enter m(no of integers in first linked list: )");
    scanf("%d", &m);

    for(i=0;i<m;i++)
    {
        scanf("%d", &value2);
        head2 = insert_node(head2, value2);
    }

    struct node* merged = merge_list(head1, head2);  
    display(merged);

    return 0;
}
