 /// desin circular queue

 #include <stdio.h>
 #include <string.h>
 #include <ctype.h>
 #include <stdlib.h>
  //#include <malloc.h>
 #define MAX_SIZE 5

 void enqueue(char [],int*,int*);   // q[],r,cnt
 char delqueue(char [],int*,int*); // q[],f,cnt
 void display(char [],int ,int ); // q[],f,cnt

 int main(){
   char q[100],temp;

   int choice,done = 0,i;
   int f = 0;
   int r = -1;
   int cnt = 0;
   while(!done){
     printf("1> INSERT \t 2> DELETE \t 3> DISPLAY \t 4> EXIT \n");
     printf("Enter your choice ->\n");
     scanf("%d",&choice);
     switch(choice){
       case 1:

         enqueue(q,&r,&cnt);
         display(q,f,cnt);
         break;
      case 2:
         temp = delqueue(q,&f,&cnt);
         if(temp == '#'){
           printf("underflow \n");
         }
         else
         {
         printf("Element deleted is : %c\n", temp);
         display(q,f,cnt);
        }
         break;
      case 3:
         display(q,f,cnt);
         break;
      case 4:
          done = 1;
          break;
      default:
         printf("Invalid !!\n");
     }
   }
   return 0;
 }


 ///function for inserting element into a circular queue

 void enqueue(char q[],int *r,int *cnt){
    char ele;
    if(*cnt == MAX_SIZE){
      printf("Overflow \n");
      return;
    }
    else
    {
      printf("enter element to insert : ");
      scanf("%s",&ele);
      *r = (*r + 1) % MAX_SI
      q[*r] = ele;
      (*cnt)++;
    }
 }

 ///function to delete an element from a circular queue

 char delqueue(char q[],int *f,int *cnt){
   char temp1;
   if(*cnt == 0){
      return '#';
   }
   temp1 = q[*f];
   *f = (*f + 1) % MAX_SIZE;
   (*cnt)--;
   return temp1;
 }

 ///function to display all element in circular queue

 void display(char q[],int f,int cnt){
   int i;
   if(cnt == 0){
     printf("circular queue is empty\n");
     return;
   }

   for(int i=1;i<=cnt;i++){
     printf("%c ",q[f]);
     f = (f + 1) % MAX_SIZE;
   }
   printf("\n");
 }
