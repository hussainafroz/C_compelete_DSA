
#include <stdio.h>
#include <stdlib.h>
#define MAX 10
/*FUNCTION PROTOTYPE */
int create(int);
void linear_prob(int[], int, int);
void display (int[]);
int main()
{
 int a[MAX],num,key,i;
 printf(" collision handling by linear probing : \n");
 for (i=0;i<MAX;i++)
  {
   a[i] = -1;
  }
  while(1){
    int ans;
    printf("\nEnter the data -> \n");
    scanf("%d",&num);
    key = create(num);
    linear_prob(a,key,num);
    printf("\n Do you want to continue ?\n");
    scanf("%d",&ans);
    if(ans == 0){
      break;
    }
  }
 display(a);
 return 0;
}

int create(int num) // return num%100
{
 int key;
 key=num%10;
 return key;
}
void linear_prob(int a[MAX], int key, int num)
{
 int flag, i, count=0;
 flag=0;
 if(a[key]== -1)
 {
   a[key] = num;
 }
 else
 {
 printf("\nCollision Detected...!!!\n");
 i=0;
 while(i<MAX)
 {
  if (a[i]!=-1) // cnt of total non empty seats
       count++;
 i++;
 }
 printf("Collision avoided successfully using LINEAR PROBING\n");
 if(count == MAX)
 {
 printf("\n Hash table is full");
 display(a);
 exit(1);
 }
 //for(i=key+1;i<max;i++)
 for(i=key+1; i<MAX; i++)
 {
 if(a[i] == -1)
 {
 a[i] = num;
 flag =1;
 break;
 }
 }
 //for(i=0;i<key;i++)
 i=0;
 while((i<key) && (flag==0))
 {
 if(a[i] == -1)
 {
 a[i] = num;
 flag=1;
 break;
 }
 i++;
 }
 }
}
void display(int a[MAX])
{
int i,choice;
 printf("1.Display ALL\n2.Filtered Display\n");
 scanf("%d",&choice);
if(choice==1)
 {
 printf("\n the hash table is\n");
 for(i=0; i<MAX; i++)
 printf("\n %d %d ", i, a[i]);
 }
else
 {
 printf("\n the hash table is\n");
 for(i=0; i<MAX; i++)
 if(a[i]!=-1)
 {
 printf("\n %d %d ", i, a[i]);
 continue;
 }
 }
}
