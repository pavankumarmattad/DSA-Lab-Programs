#include<stdio.h>
#include<stdlib.h>

struct employee
{
    char ssn[10],name[20],dept[10],desig[20],ph[11];
    float sal;
};
typedef struct employee emp;

struct dll
{
    struct dll* llink;
    emp data;
    struct dll *rlink;
};
typedef struct dll nd;

void insert_rear(nd *h)
{
  nd * t;
  t=(nd*)malloc(sizeof(nd));
  printf("Enter the employee details:\n");
  printf("SSN: "); scanf("%s",(t->data.ssn));
  printf("Name: "); scanf("\n"); scanf("%[^\n]%*c",t->data.name);
  printf("Department: "); scanf("%s",t->data.dept);
  printf("Designation: "); scanf("%s",t->data.desig);
  printf("Salary: "); scanf("%f",&(t->data.sal));
  printf("Ph.No: "); scanf("%s",t->data.ph);
  printf("\n");
  t->rlink=0; t->llink=0;
  nd *p,*c;
  if(h->rlink==0)
      h->rlink=t;
  else{
  for(c=0,p=h->rlink;p!=0;c=p,p=p->rlink);
  c->rlink=t;
  t->llink=c;
  }
}

void insert_front(nd *h)
{
  nd * t;
  t=(nd*)malloc(sizeof(nd));
  printf("Enter the employee details:\n");
  printf("SSN: "); scanf("\n"); scanf("%[^\n]%*c",(t->data.ssn));
  printf("Name: "); scanf("%s",t->data.name);
  printf("Department: "); scanf("%s",t->data.dept);
  printf("Designation: "); scanf("%s",t->data.desig);
  printf("Salary: "); scanf("%f",&(t->data.sal));
  printf("Ph.No: "); scanf("%s",t->data.ph);
  printf("\n");
  t->rlink=t->llink=0;
  if(h->rlink==0)
  {
      h->rlink=t;
      return;
  }
  t->rlink=h->rlink;
  (h->rlink)->llink=t;
  h->rlink=t;
}

void display(nd*h)
{
    if(h->rlink==0)
    {
        printf("The employee list is empty!\n");
        return;
    }
    nd *p;
    int cnt=1;
    for(p=h->rlink;p!=0;p=p->rlink,cnt++)
    {
        printf("The details of employee %d are:\n",cnt);
        printf("SSN: %s\nName: %s\nDepartment: %s\nDesignation: %s\nSalary: %f\nPh.No: %s\n\n",((p->data).ssn),((p->data).name),
        ((p->data).dept),((p->data).desig),((p->data).sal),((p->data).ph));
    }
    printf("The total number of employes is: %d\n\n",cnt-1);    
}

void delete_front(nd *h)
{
    if(h->rlink==0)
    {
        printf("The employee list is empty!\n");
        return;
    }
    nd *t;
    t=h->rlink;
    printf("The deleted employee details are:\n");
    printf("SSN: %s\nName: %s\nDepartment: %s\nDesignation: %s\nSalary: %f\nPh.No: %s\n",(t->data.ssn),(t->data.name),(t->data.dept),
    (t->data.desig),(t->data.sal),(t->data.ph));
    h->rlink=t->rlink;
    if(h->rlink!=0)
    (h->rlink)->llink=0;
    free(t);
}

void delete_rear(nd *h)
{
   if(h->rlink==0)
    {
        printf("The employee list is empty!\n");
        return;
    }
    nd *t,*c;
    for(t=h->rlink;t->rlink!=0;c=t,t=t->rlink);
    printf("The deleted employee details are:\n");
    printf("SSN: %s\nName: %s\nDepartment: %s\nDesignation: %s\nSalary: %f\nPh.No: %s\n",(t->data.ssn),(t->data.name),(t->data.dept),
    (t->data.desig),(t->data.sal),(t->data.ph));
    if(h->rlink->rlink==0)
    {
        free(t); h->rlink=0;
        return;
    }
    (t->llink)->rlink=0;
    free(t); 
}

void reverse(nd *h)
{
    if(h->rlink==0)
    {
        printf("DLL is empty!\n");
        return;
    }
    nd * p,*c,*temp;
    for(c=0,p=h->rlink;p!=0;c=p,p=p->llink)
    {
        temp=p->llink;
        p->llink=p->rlink;
        p->rlink=temp;
    }
    h->rlink=c;
}

int main()
{
    nd header={.llink=0,.rlink=0};
    int key,n,i;
    while(1)
    {
        printf("Enter the choice:\n1.Create N Employee list by end insertion\n2.InsertFront\n3.DeleteFront\n4.InsertRear 5.DeleteRear\n6.Display 7.Exit\n");
        printf("\n");
        scanf("%d",&key);
        switch(key)
        {
            case 1: printf("Enter the number of employees:\n");
                    scanf("%d",&n);
                    for(i=0;i<n;i++)
                     insert_rear(&header);
                    break;
            case 2: insert_front(&header); break;
            case 3: delete_front(&header); break;
            case 4: insert_rear(&header); break;
            case 5: delete_rear(&header); break;
            case 6: display(&header); break;
            case 7: reverse(&header); break;
            default: return 0;         
        }
    }
}