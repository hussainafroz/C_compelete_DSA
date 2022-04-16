/* Lab_Program1 : Design, develop and implement a menu driven program in C for the following array operations
    a) Creating an array of N integer elements.
    b) Display of array elements with suitable headings.
    c) Inserting an element (ELEM) at a given valid position (POS).
    d) Deleting an element at a given valid position (POS).
    e) Exit

    Support the program with functions for each of the above operations.
*/

#include<stdio.h>
#include<stdlib.h>
#define MAX 50

void create_array(int [], int);
void display(int [], int);
int insert_at_pos(int, int[], int, int);
int del_at_pos(int [], int ,int);

int main()
{
    int choice , a[10],n,item,pos;
    for(;;)
    {

        printf("\n\n1: Create_array        2: Display_array");
        printf("\n3: Insert_at_POS         4: Del_at_POS");
        printf("\n5: Exit");


        printf("\n\nEnter your choice >>");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("\nEnter the number of elements");
                scanf("%d", &n);
                printf("\nenter %d elements",n);
                create_array(a,n);
                break;

            case 2:
                display(a,n);
                break;

            case 3:
                printf("\nEnter the item to be inserted");
                scanf("%d", &item);
                printf("\nEnter the position");
                scanf("%d",&pos);
                n = insert_at_pos(item,a,n,pos);
                break;

            case 4:
                printf("\nEnter the position");
                scanf("%d", &pos);
                n = del_at_pos(a,n,pos);
                break;

            case 5:
                exit(1);


            default: printf("\nInvald Choice");

        }

    }
}

// Function to create an array
void create_array(int a[], int n)
{
    int i;
    for(i=0; i<n ;i++)
    {
        scanf("%d", & a[i]);
    }
}

// Function to display an array
void display(int a[], int n)
{
    int i;
    printf("\n");
    for(i=0; i<n ;i++)
    {
        printf("%d ", a[i]);
    }
}

// Function to insert at a specified position
int insert_at_pos(int item, int a[], int n, int pos)
{
    int i;
    if (pos > n || pos<0)
    {
        printf("\nInvalid Position");
    }
    for (i=n-1; i>= pos-1; i--)
    {
        a[i+1]=a[i];
    }
    a[pos-1] = item;
    return n+1;
}

//Function to delete an item at a specified position
int del_at_pos(int a[], int n, int pos)
{
    int i;
    if (pos > n || pos<0)
    {
        printf("\n Invalid position");
    }

    for(i = pos-1; i<n ; i++)
    {
        a[i]= a[i+1];
    }
     return n-1;
}
