#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<math.h>
typedef struct node
{
int expo,coef;
struct node *next;
}node;
/*FUNCTION PROTOTYPE*/
node * insert(node *,int,int);
node * create();
node * add(node *p1,node *p2);
int eval(node *p1);
void display(node *head);
////////////////////////////////////
node *insert(node*head,int expo1,int coef1)
{
node *p,*q;
p=(node *)malloc(sizeof(node));
p->expo=expo1;
p->coef=coef1;
p->next=NULL;
if(head==NULL)
{
head=p;
head->next=head;
return(head);
}

if(expo1>head->expo)
{
p->next=head->next;
head->next=p;
head=p;
return(head);
}
if(expo1==head->expo)
{
head->coef=head->coef+coef1;
return(head);
}
q=head;
while(q->next!=head&&expo1>=q->next->expo)
q=q->next;
if(p->expo==q->expo)
q->coef=q->coef+coef1;
else
{
p->next=q->next;
q->next=p;
}
return(head);
}
node *create()
{
int n,i,expo1,coef1;
node *head=NULL;
printf("\nEnter no of terms of polynomial -> \n");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("\nEnter coef & expo -> ");
scanf("%d%d",&coef1,&expo1);
head=insert(head,expo1,coef1);
}
return(head);
}
//////////////////////////////////
node *add(node *p1,node *p2)
{
node *p;
node *head=NULL;
printf("\nAddition of polynomial -> ");
p=p1->next;

do
{
head=insert(head,p->expo,p->coef);
p=p->next;
}while(p!=p1->next);


p=p2->next;

do
{
head=insert(head,p->expo,p->coef);
p=p->next;
}while(p!=p2->next);

return head;
}
/////////////////////////
int eval(node *head)
{
node *p;
int x,ans=0;
printf("\nEnter the value of x = ");
scanf("%d",&x);
p=head->next;
do
{
ans=ans+p->coef*pow(x,p->expo);
p=p->next;
}while(p!=head->next);

return ans;
}
//////////////////////////
void display(node *head)
{
node *p,*q;
int n=0;
q=head->next;
p=head->next;

do
{
  n++;
  q=q->next;
}while(q!=head->next);

printf("\nThe polynomial is -> ");

do
{
   if(n != 1)
  {
    printf("%dx^(%d) + ",p->coef,p->expo);
    p=p->next;
  }
   else
  {
   printf("%dx^(%d)",p->coef,p->expo);
   p=p->next;
  }
n--;
}while(p!=head->next);
 printf("\n");
}
/////////////////////////////
int main()
{
  int done = 0,choice,ans;
  node* p1,*p2,*p3;
  p1 = p2 = p3 = NULL;
  while(done != 1){
    printf("1.Add 2.Eval 3.Exit \n");
    printf("Enter your choice\n");
    scanf("%d",&choice);
    switch (choice) {
      case 1: p1 = create();
              display(p1);
              p2 = create();
              display(p2);
              p3 = add(p1,p2);
              display(p3);
              break;
      case 2 : p1 = create();
               display(p1);
               ans = eval(p1);
               printf("Evaluated value = %d",ans);
               break;
      case 3 : done = 1;
               break;
      }
  }


return 0;
}
