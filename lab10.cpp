

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>


#define MAX_SIZE 50

struct BSTree{
  int val;
  struct BSTree* left;
  struct BSTree* right;
};

typedef struct BSTree* node;

#define MALLOC(ptr,s,t)\
   ptr = (t)malloc(s);\
    if(ptr == NULL){\
        printf("Insufficient memory \n");\
        exit;\
    }



/*function protocols*/
node create(node,int);
node create_bst(node,int);
void preorder(node);
void inorder(node);
void postorder(node);
int search_item(node,int);
int n;

int main(){
    int choice,done = 0,i,flag,key;
    node root;
    root = NULL;
    while(!done){
      printf("1.create \t 2.preorder \n");
      printf("3.inorder \t 4.postorder \t 5.search \n");
      printf("6.exit \n");
      printf("ur wish ->> \n");
      scanf("%d",&choice);
      switch(choice){
          case 1 : printf("Enter the no of elements ->> \n");
                   scanf("%d",&n);
                   root = create(root,n);
                   break;
          case 2 : preorder(root);
                   printf("\n");
                   break;
          case 3 : inorder(root);
                  printf("\n");
                  break;
          case 4 : postorder(root);
                   printf("\n");
                  break;
          case 5 : printf("enter the element to search ->> \n");
                   scanf("%d",&key);
                   flag = search_item(root,key);
                    if(flag == 1){
                      printf("element found\n");
                    }
                    else
                    {
                      printf("element not found\n");
                    }
                    break;
          case 6 : done = 1;
                   break;
          default : printf("invlaid choice\n");

      }
    }
    return 0;
}


// create node

node create(node root,int n){
   int i,item;
   node temp;
   if(root == NULL){
     for(i=0;i<n;i++){
       scanf("%d",&item);
       root = create_bst(root,item);
     }
     return root;
   }
  else
    printf("bst have some elements in it ?? ");
}


// bst

node create_bst(node root,int item){
  node curr,per,tem;
  MALLOC(tem,sizeof(struct BSTree),node);
   tem->val = item;
   tem->left = tem->right = NULL;
   if(root == NULL) return tem;


   per = NULL;
   curr = root;
   while(curr != NULL)
   {
     per = curr;
     if(item == curr->val){
       printf("Dublicate is not allowed \n");
       free(curr);
       return root;
     }

     if(item < curr->val){
       curr = curr->left;
     }
     else
     {
       curr = curr->right;
     }
   }
   if(item < per->val){
     per->left = tem;
   }
   else
   {
     per->right = tem;
   }
   return root;
}

int search_item(node root,int key){
  if(root == NULL){
    return 0;
  }
  else if(root->val == key){
    return 1;
  }
  else if(root->val > key){
     return search_item(root->left,key);
  }
  else
  {
    return search_item(root->right,key);
  }

}

void preorder(node root){
  if(root == NULL){
    return;
  }
  printf("%d ",root->val);
  preorder(root->left);
  preorder(root->right);
}

void inorder(node root){
  if(root == NULL){
    return;
  }
  inorder(root->left);
  printf("%d ",root->val);
  inorder(root->right);
}

void postorder(node root){
  if(root == NULL){
    return;
  }
  postorder(root->left);
  postorder(root->right);
  printf("%d ",root->val);
}
