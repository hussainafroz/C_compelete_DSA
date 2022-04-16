#include<stdio.h>



void towerofhanaoi(int ,char ,char ,char ,int*);

int main(){
  int n,m=0;
  printf("Enter the number of disk >> \n");
  scanf("%d",&n);
  towerofhanaoi(n,'a','b','c',&m);
  printf("No of moves >> %d \n",m);
  return 0;
}

void towerofhanaoi(int n,char a,char b,char c,int *m){
  if(n == 1){
    printf("Move disk %d from %c peg to %c peg\n",n,a,c);
    (*m)++;
    return;
  }
  else
  {
    towerofhanaoi(n-1,a,c,b,m);
    printf("Move disk %d from %c peg to %c peg\n",n,a,c);
    (*m)++;
    towerofhanaoi(n-1,b,a,c,m);
  }
}
