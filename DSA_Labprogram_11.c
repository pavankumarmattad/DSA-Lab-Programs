#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 50

int **a=0,n;
int *visited;
void create()
{
    int i,j;
    printf("Enter the number of vertices:\n");
    scanf("%d",&n);
    visited = (int*)malloc(sizeof(int)*n);
     for(i=0;i<n;i++)
        visited[i]=0;
    a=(int**)malloc(sizeof(int*)*n);
    for(i=0;i<n;i++)
     a[i]=(int *)malloc(sizeof(int)*n);
    printf("Enter the values of adjacency matrix:\n");
    for(i=0;i<n;i++)
      for(j=0;j<n;j++)
       scanf("%d",&a[i][j]);
}

void DFS(int i)
{
    printf("%d ",i);
    visited[i]=1;
    for(int j=0;j<n;j++)
     if(a[i][j]==1 && visited[j]!=1)
       DFS(j);    
}

int q[100],f=0,r=-1;
void bfs(int i)
{
    printf("%d ",i);
    visited[i]=1;
    for(int j=0;j<n;j++)
     if(a[i][j]==1 && visited[j]==0)
     {
      q[++r]=j;
      visited[j]=1;
     }
    if(f<=r)
    {
        //visited[q[f]]=1;
        bfs(q[f++]);
    }  
}

int main()
{
    int i,ch;
    while(1)
    {
        printf("Enter Choice:\n1. Create\n2. DFS\n3. BFS\n4. Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: create(); break;
            case 2: printf("Enter the Starting node:\n");
                    scanf("%d",&i);
                    DFS(i); printf("\n");
                    for(i=0;i<n;i++)
                      visited[i]=0;
                    break;
            case 3: printf("Enter the starting node:\n");
                    scanf("%d",&i);
                    bfs(i); printf("\n");
                    for(i=0;i<n;i++)
                      visited[i]=0;
                    break;
            case 4: exit(0);        
        }
    }
}/*
0 1 1 0 0 0 0 0
0 0 0 1 1 0 0 0
0 0 0 0 0 1 1 0
0 0 0 0 0 0 0 1
0 0 0 0 0 0 0 1
0 0 0 0 0 0 0 1
0 0 0 0 0 0 0 1
0 0 0 0 0 0 0 0*/