#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node *llink,*rlink;
    int info;
};
typedef struct node nd;

nd *insert(nd*root,int key)
{
    nd*cur=root,*prev=0;
    nd *t= (nd *) malloc(sizeof(nd));
    t->info=key; t->llink=t->rlink=0;
    if (!cur) return t;
    while(cur)
    {
        if (t->info == cur->info)
        { 
            printf("Redundancy\n"); 
            free(t); 
            return root; 
        }
        prev=cur;
        if (t->info < cur->info)
        cur=cur->llink;
        else
        cur=cur->rlink;
    }
    if (t->info < prev->info)
    prev->llink=t;
    else
    prev->rlink=t;
    return root;
}

void recurSearch( nd *root, int key) 
{
    if (!root) 
    { 
        printf("Unsuccessful search\n"); 
        return; 
    }
    if (key == root->info) 
    { 
        printf("Successful search\n"); 
        return;
    }
    if (key < root->info)
    return recurSearch(root->llink,key);
    return recurSearch(root->rlink,key);
}

void inorder(nd *r)
{
  if(r)
  {  
    inorder(r->llink);
    printf("%d ",r->info);
    inorder(r->rlink);
  }  
}

void postorder(nd *r)
{
  if(r)
  {  
    postorder(r->llink);
    postorder(r->rlink);
    printf("%d ",r->info);
  }  
}
 
void preorder(nd *r)
{
  if(r)
  {  
    printf("%d ",r->info);
    preorder(r->llink);
    preorder(r->rlink);
  }
}

nd * delete(nd * root,int key)
{
  nd *cur,*prev,*q,*suc;
  if(!root)
  {
    printf("Binary search Tree empty!\n");
    return 0;
  }
  prev=0;cur=root;
  while(cur)
  {
    if(key==cur->info)
    {
      printf("Successful Search\n");
      break;
    }
    prev=cur;
    if(key<cur->info)
     cur=cur->llink;
    else
     cur=cur->rlink; 
  }
  if(!cur)
  {
    printf("Key Not Found!\n");
    return root;
  }
  if(!cur->llink)
   q=cur->rlink;
  else if(!cur->rlink)
   q=cur->llink;
  else
  {
    suc=cur->rlink;
    while(suc->llink)
     suc=suc->llink;
    suc->llink=cur->llink;
    q=cur->rlink;
  } 
  if(!prev)
   return q;
  if(cur==prev->llink)
   prev->llink=q;
  else
   prev->rlink=q;
  free(cur);
  printf("The node with value %d deleted Successfully !\n",key);
  return root;
}

void main()
{
    nd *root=0;
    int ch,i,key,n;
    while(1)
    {
        printf("Enter choice:\n1. Insert\n2. Search\n3. Inorder\n4. Preorder\n5. Postorder\n6. Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter the number of nodes:\n");
                    scanf("%d",&n);
                    for(i=0;i<n;i++)
                    {
                        printf("Enter the node value:\n");
                        scanf("%d",&key);
                        root=insert(root,key);
                    }
                    break;
            case 2: printf("Enter the value to be searched:\n");
                    scanf("%d",&key);
                    recurSearch(root,key);
                    break;
            case 3: inorder(root);
                    printf("\n");
                    break;
            case 4: preorder(root);
                    printf("\n");
                    break;
            case 5: postorder(root);
                    printf("\n");
                    break;
            case 6: printf("Enter the value to delete:\n");
                    scanf("%d",&key);
                    root=delete(root,key); 
                    break;      
            case 7: exit(0);        
        }
    }
}