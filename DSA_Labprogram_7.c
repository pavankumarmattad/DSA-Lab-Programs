#include<stdio.h>
#include<stdlib.h>

struct student 
{
    char usn[10],name[20],branch[5];
    int sem,ph;
};
typedef struct student data;

struct sll
{
    data d;
    struct sll *link;
};
typedef struct sll nd;

void display(nd *f)
{
    if(f==0)
    {
        printf("The list is empty!\n");
        return;
    }
    nd *t;
    printf("The contents of the list are:\n");
    for(t=f;t!=0;t=t->link)
     printf("%s %s %s %d %d\n",t->d.usn,t->d.name,t->d.branch,t->d.sem,t->d.ph);
}

nd* insert_front(nd *f)
{
    nd *t,*p;
    t=(nd*)malloc(sizeof(nd));
    printf("Enter the student details:\n");
    scanf("%s%s%s%d%d",t->d.usn,t->d.name,t->d.branch,&t->d.sem,&t->d.ph);
    t->link=0;
    if(f==0)
     return t;
    t->link=f;
    return t;
}

nd * insert_rear(nd *f)
{
   nd *t,*p,*c;
    t=(nd*)malloc(sizeof(nd));
    printf("Enter the student details:\n");
    scanf("%s%s%s%d%d",t->d.usn,t->d.name,t->d.branch,&t->d.sem,&t->d.ph);
    t->link=0;
    if(f==0)
     return t;
    for(c=0,p=f;p!=0;c=p,p=p->link);
    c->link=t;
    return f;  
}

nd * delete_front(nd *f)
{
   if(f==0)
    {
        printf("The list is empty!\n");
        return 0;
    } 
    nd *t;
    t=f->link;
    printf("The deleted student details are:\n");
    printf("%s %s %s %d %d\n",f->d.usn,f->d.name,f->d.branch,f->d.sem,f->d.ph);
    free(f);
    return t;
}

nd * delete_rear(nd *f)
{
   if(f==0)
    {
        printf("The list is empty!\n");
        return 0;
    } 
    /*if(f->link==0)
    {
       printf("The deleted student details are:\n");
       printf("%s %s %s %d %d\n",f->d.usn,f->d.name,f->d.branch,f->d.sem,f->d.ph); 
       free(f);
       return 0;
    }*/
    nd *p,*c;
    for(c=0,p=f;p->link!=0;c=p,p=p->link);
    printf("The deleted student details are:\n");
    printf("%s %s %s %d %d\n",p->d.usn,p->d.name,p->d.branch,p->d.sem,p->d.ph);
    if(f->link != 0)
     c->link=0;
    else 
      return 0;
    free(p);
    return f;
}
 
void main()
{
    int n,ch;
    nd *head=0;
    while(1)
    {
        printf("Enter choice:\n1.Create 2.Display 3.InsertFront\n4.InsertRear 5.DeleteFront 6.DeleteRear\n7.Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter the number of students:\n");
                    scanf("%d",&n);
                    for(int i=0;i<n;i++)
                     head=insert_front(head);
                    break;
            case 2: display(head); break;
            case 3: head=insert_front(head); break;
            case 4: head=insert_rear(head); break;
            case 5: head=delete_front(head); break;
            case 6: head=delete_rear(head); break;
            case 7: exit(0);
            default: printf("Invalid Input!\n"); break;         
        }
    }
}