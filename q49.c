/* Problem: Count Occurrences of an Element in Linked List - Implement using linked list with 
dynamic memory allocation.
Input:
- First line: integer n (number of nodes)
- Second line: n space-separated integers (linked list elements)
- Third line: integer key (element to be counted)

Output:
- Print the number of times the key appears in the linked list

Example:
Input:
6
10 20 30 20 40 20
20

Output:
3
Explanation:
Traverse the linked list from head to end. Each time a node's data matches the given key, increment a counter.
After traversal, print the final count.  */


 #include <stdio.h>
 #include <stdlib.h>


 struct node
 {
    int data;
    struct node* next; 
 };


 struct node* createnode(int value)
 {
    struct node* x= (struct node*)malloc(sizeof(struct node));
    x->data=value;
    x->next=NULL;
    return x;
 }


 
 struct node* insert_node(struct node* head, int value, int key)
 {
    struct node* newnode=createnode(value);
    struct node* temp=head;

    if (head==NULL)
    return newnode;

    while(temp->next !=NULL)
    {
        temp= temp->next;
    }
    temp->next= newnode;
    return head;
    
 }


int count_occ(struct node* head, int key)
 {
   struct node* temp=head;
   int count=0;

   if (temp==NULL)
   printf("empty list. sorry!");

   while(temp !=NULL)
   {
      if(temp->data==key)
      count++;
     temp=temp->next;
   }
   
   return count;
 }

 
 
 int main()
 {
    int n,i,key,value;
    struct node* head=NULL;
    struct node* temp=head;

    printf("enter number of nodes: ");
    scanf("%d", &n);

    for(i=0; i<n; i++)
    {
      printf("enter value %d: ", i+1);
      scanf("%d", &value);

      struct node* p= createnode(value);

      if(head=NULL)
      {
         head=p;
         temp=head;
      }

      else
      {
         temp->next=p;
         temp=temp->next;
      }

    }

    printf("enter the element whose occurrence is to be found: ");
    scanf("%d", &key);

    printf("%d", count_occ(head,key));

    return 0;
 }

