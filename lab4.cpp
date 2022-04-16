
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define MAX 60

void push(char [],int *,char );
int pop(char [],int *);
void convert(char [],char []);
int icp(char);
int isp(char);

int main(){
 char infix[MAX],postfix[MAX];
 printf("Enter the infix expression\n");
 scanf("%s",infix);
 printf("the Original infix expression = %s\n",infix);
 convert(infix,postfix);
 printf("\nThe postfix string is = %s\n",postfix);
 return 0;
}

// function to convert an infix expression to postfix

void convert(char infix[],char postfix[]){
 int i,len,k,top;
 char x;
 char s[MAX]; // stack
 top = 0;
 i = k = 0;
 len = strlen(infix);
 s[top] = '(';
 infix[len] = ')';

 while(i <= len){
   x = infix[i];
   if(icp(x) == 8)
      x = '#';

       switch(x){
             case '#': postfix[k++] = infix[i];
                      break;
             case ')' : while(s[top] != '(')
             {
               postfix[k++] = pop(s,&top);
             }
             pop(s,&top);


             if(top == -1){
               postfix[k] = '\0';
               return;
             }

             break;

             default :
                 while(icp(x) < isp(s[top]))
                 {
                   postfix[k++] = pop(s,&top);
                 }              // insert all the character which does follow the formats
                 push(s,&top,x);

       }
       i++;
   }
 }

 int icp(char x){
   if(isalnum(x))
     x = '#';

   switch(x)
   {
     case '+':
     case '-': return (1);

     case '*':
     case '/':
     case '%': return (3);

     case '^': return (6);
     case '#': return (8);
     case '(': return (9);
     case ')': return (0);
     default : printf("error\n");
          return  (-1);
   }
 }


int isp(char x){
 switch(x){
   case '+':
   case '-': return (2);
   case '*':
   case '/':
   case '%': return (4);
   case '^':return (5);
   case '#':return (8);
   case '(': return (0);
   default : printf("error\n");
   return (-1);
 }
}

void push(char s[],int *top,char ele){
  s[++(*top)] = ele;

}

int pop(char s[],int *top){
  return s[(*top)--];
}
