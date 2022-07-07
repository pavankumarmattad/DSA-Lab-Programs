#include<stdio.h>
#include<stdlib.h>

int * create(int *a,int n){
    int i;
    a=(int*)malloc(n*sizeof(int));
    if(a==NULL)
    {
        printf("Array not created!\n");
        exit(0);
    }
    printf("Array created\n");
    printf("Enter the array elements:\n");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    return a;
}

void display(int *a,int n)
{
    int i;
    if(n==0)
     {
         printf("The Array is empty !");
         return;
     }
    printf("The array elements are:\n");
    for(i=0;i<n;i++)
    printf("%d ",a[i]);
}

int * insert(int *a,int *n,int ele, int pos)
{
    int i;
    (*n)++;
    a=(int*)realloc(a,(*n)*sizeof(int));
    for(i=(*n)-1;i>=pos;i--)
    a[i]=a[i-1];
    a[pos]=ele;
    return a;
}

void delete(int *a,int *n,int pos)
{
    int i,temp;
    temp=a[pos];
    for(i=pos;i<(*n)-1;i++)
    a[i]=a[i+1];
    (*n)--;
    printf("The deleted element is:\n%d\n",temp);
    if(*n==0)
    printf("No elements to delete\n");
    //display(a,*n);
}

void main()
{
    int *a,n;
    int key,pos,ele;
    while(1)
    {
        printf("\nEnter your choice:\n1.Create an array\n2.Display\n3.Insert element\n4.Delete element\n5.exit\n");
        scanf("%d",&key);
    switch(key){
        case 1 : printf("Enter the number of elements:\n");
                 scanf("%d",&n);
                 a=create(a,n);
                 break;
        case 2 : display(a,n);
                 break;
        case 3 : printf("Enter the element and position to insert:\n");
                 scanf("%d%d",&ele,&pos);
                 if(pos-1>=0 && pos-1<n+1)
                    a=insert(a,&n,ele,pos-1);
                 else
                    printf("Invalid position!\n");
                 break;
        case 4 : printf("Enter the position of element:\n");
                 scanf("%d",&pos);
                 if(pos-1>=0 && pos-1<n)
                  delete(a,&n,pos-1);
                 else 
                  printf("Invalid Position!\n");
                 break;
        case 5 : free(a);
                 exit(0);
    }     
    }                    
}