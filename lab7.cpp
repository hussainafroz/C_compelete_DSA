///student field : usn , name , branch, phone no ,sem

// using singled linked list

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

#define M 30

#define  MALLOC(ptr,s,t)\
   ptr = (t)malloc(s);\
   if(ptr == NULL)\
   {\
     printf("Insufficient Memory \n");\
     exit(0);\
   }

struct list
{
  int USN;
  char NAM[M]; // name
  char BR[M];  // branch
  char Ph[M]; // phone no
  int SEM; // semester
  struct list* link;
};
typedef struct list* node;

/*functions protocols */
void read_data();
node create_node(node,int);  // node first,int n
node ins_front(node);    // node first,int ele
node ins_rear(node);    // node first,int ele
node del_front(node);       // node first
node del_rear(node);        // node first
void display(node);         // node first
/*-------------------------------------------------*/
/*student informative data types */
int usn;
char name[M];
char branch[M];
char phone[M];
int sem;

int main(){
  int choice,done = 0;
  node first;
  first = NULL;
  int n; // no - of - students
  while(!done){
    printf("1/CREATE\t2/iNSERT_AT_FRONT\t3/INSERT_AT_REAR\n");
    printf("4/DELETE_AT_FRONT\t5/DELETE_AT_REAR\t6/DISPLAY\t7/EXIT\n");
    printf("Enter your choice -> \n");
    scanf("%d",&choice);
    switch(choice){
      case 1 : printf("Enter no of students \n");
               scanf("%d",&n);
               first = create_node(first,n);
               break;
      case 2 : read_data();
               first = ins_front(first);
               break;
      case 3 : read_data();
               first = ins_rear(first);
               break;
      case 4 : first = del_front(first);
               break;
      case 5 : first = del_rear(first);
               break;
      case 6 : display(first);
               break;
       case 7 : done = 1;
                break;
      default : printf("INVALID !!\n");
                break;
      }
    }
    return 0;

}

void read_data(){
  printf("Enter student usn -> \n");
  scanf("%d",&usn);
  printf("Enter student name -> \n");
  scanf("%s",name);
  printf("Enter student branch -> \n");
  scanf("%s",branch);
  printf("Enter student phone number -> \n");
  scanf("%s",phone);
  printf("Enter student semester -> \n");
  scanf("%d",&sem);
}

node create_node(node first,int n){
  int i;
  if(first == NULL){   // linked list is not empty
      for(int i=1;i<=n;i++){
        printf("Enter student data <%d> : \n",i);
        read_data();
        first = ins_front(first);
      }
      return first;

  }
  else
  {
    printf("List has some element\n");
  }

}

node ins_front(node first){
  node temp;
  MALLOC(temp,sizeof(struct list),node);
  temp->USN = usn;
  strcpy(temp->BR,branch);
  strcpy(temp->NAM,name);
  strcpy(temp->Ph,phone);
  temp->SEM = sem;
  //insert at  front


  temp->link = first;
  first = temp;

  return first;
}

node ins_rear(node first){
  node temp,curr = first;
  MALLOC(temp,sizeof(struct list),node);
  temp->USN = usn;
  strcpy(temp->BR,branch);
  strcpy(temp->NAM,name);
  strcpy(temp->Ph,phone);
  temp->SEM = sem;
  temp->link = NULL;
  // insert_at_ rear
  if(first == NULL){
    first = temp;
  }
  while(curr->link != NULL){
    curr = curr->link;
  }
  curr->link = temp;

  return first;
}

node del_front(node first){
  node temp;
  if(first == NULL){
    printf("List is empty\n");
    return NULL;
  }
  else
  {
    temp = first;
    first = first->link;
    free(temp);
    return first;
  }

}

node del_rear(node first){
  node curr = first,prev;
  if(first == NULL){
    printf("List is empty\n");
    return NULL;
  }
  if(first->link == NULL){
    free(first);
    return NULL;
  }
  else
  {
     while(curr->link != NULL){
       prev = curr;
       curr = curr->link;
     }
      prev->link = NULL;
      free(curr);
      return first;
  }
}

void display(node first){
  int cnt = 0;
  if(first == NULL){
    printf("List is empty -> NO DISPLAY\n");
    return;
  }
  while(first != NULL){
    printf("%d\t%s\t%s\t%s\t%d\n",first->USN,first->NAM,first->BR,first->Ph,first->SEM);
    first = first->link;
    cnt++;
  }
  printf("total no :- of nodes = %d\n",cnt);
}
