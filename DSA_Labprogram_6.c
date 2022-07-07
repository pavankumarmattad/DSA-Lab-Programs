#include<stdio.h>
#include<stdlib.h>
#define M 3

void insert(int q[],int *r,int *cnt)
{
  int ele;
  if((*cnt)==M)
  {
    printf("CQ overflow!\n");
    return;
  }
  (*r)=((*r)+1)%M;
  printf("Enter the element:\n");
  scanf("%d",&ele);
  q[*r]=ele;
  (*cnt)++;
}

void delete(int q[],int *f,int *cnt)
{
  if((*cnt)==0)
  {
    printf("CQ Underflow!\n");
    return; 
  } 
  printf("The deleted element is: %d \n",q[(*f)]);
  (*f)=((*f)+1)%M;
  (*cnt)--;
}

void display(int q[],int f,int  cnt)
{
  int i,j;
  if((cnt)==0)
  {
    printf("CQ Underflow!\n");
    return; 
  }
  printf("CQ contents are:\n");
  for(i=f,j=0;j<cnt;)
  {
    printf("%d : %d\n",++j,q[i]);
    i=((i+1)%M);
  }
}

int main()
{
  int q[M];
  int r=-1,f=0,cnt=0,ch;
  while(1)
  {
    printf("1.Insert 2.Delete 3.Display 4.Exit\n");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1: insert(q,&r,&cnt); break;
      case 2: delete(q,&f,&cnt); break;
      case 3: display(q,f,cnt); break;
      case 4: exit(0);
    }
  }
}      