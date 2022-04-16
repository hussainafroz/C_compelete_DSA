#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#define MAX 70


void push(float [],int *,float);
float pop(float [],int *);
float eval(char []);
float oper(char,float,float);

int main(){
   char exper[MAX];
   printf("Enter the expression >> \n");
   scanf("%s",exper);
   printf("Enter the original expression >> %s\n",exper);
   printf("\n%f\n",eval(exper));
   return 0;

}

float eval(char exper[]){
   int i;char x;
   float result,s[MAX];float op1,op2,res;
   int top = -1;

   for(i = 0 ;  exper[i] != '\0';i++){
     x = exper[i];
       if(isdigit(x))
       push(s,&top,(x-'0'));
       else{
         op2 = pop(s,&top);
         op1 = pop(s,&top);
         res = oper(x,op1,op2);
         push(s,&top,res);
       }

   }
   result = pop(s,&top);
   return result;

}

float oper(char x,float op1,float op2){
    switch(x){
      case '+' : return (op1 + op2);
      case '-' : return (op1 - op2);
      case '*' : return (op1 * op2);
      case '/' : return (op1 / op2);
      case '^' : return ((float)pow(op1,op2));
      case '%' : return ((float)((int)op1 % (int)op2));
      default : printf("Invalid operations\n");
      exit(1);
    }
}


void push(float s[],int *top,float ele){
   s[++(*top)] = ele;
}

float pop(float s[],int *top){
   return s[(*top)--];
}
