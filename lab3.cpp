/******************************************************************************

                           Online C Compiler.
               Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 60

void push(int [],int *,int);
int pop(int [],int *);
int palindrome(int [],int *,char []);
void display(int [],int);

int main(){
    int s[MAX],top = -1,ele,del,flag = -1,done = 0,choice;
    char pal[MAX + 1];

    while(done != 1){
        printf("\n1:PUSH    2:POP\n3:PALINDROME    4:EXIT\n");
        printf("Enter ur choice >> \n");
        scanf("%d",&choice);
        switch(choice){
            case 1 : printf("Enter the item to be push\n");
                     scanf("%d",&ele);
                     push(s,&top,ele);
                     display(s,top);

            break;

            case 2 : del = pop(s,&top);
                     printf("top element in stack -> %d\n",del);


            break;

            case 3 : printf("Enter string ->> \n");
                     scanf("%s",pal);
                     top = -1;
                     flag = palindrome(s,&top,pal);
                     if(flag == 1){
                         printf("Given string is a palindrome \n");
                     }
                     else
                     {
                         printf("Given string is not a palindrome \n");
                         top = -1;
                     }
           break;

           case 4 : done = 1;

           break;

           default : printf("Invalid choice \n");
        }
    }
    return 0;
}



void push(int s[],int *top,int ele){
   if(*top == MAX){
       printf("Stack overflow \n");
       return;
   }

   else
   {

       s[++(*top)] = ele;
   }
}

int pop(int s[],int *top){
   if(*top == -1){
       printf("stack underflow \n");
       return -1e9;
   }

   else
   {
       return s[(*top)--];
   }


}

int palindrome(int s[],int *top,char pal[]){   // new stack , int top , string pal
   int i;
   for(i = 0 ; i < strlen(pal); i++){
       push(s,top,pal[i]);
     }
  for(i = 0 ; i < strlen(pal) ; i++){
      if(pal[i] != pop(s,top))
         return -1;
  }
  return 1;
}

void display(int s[],int top){
   int i;
   for(i = top ; i>=0 ; i--){
       printf("%d ",s[i]);
   }
   printf("\n");
}
