#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct term{
    int cf,ex,ey,ez;
    struct term *link;
};
typedef struct term tm;

void i_f(tm *h)
{
    tm *t=(tm*)malloc(sizeof(tm));
    scanf("%d%d%d%d",&(t->cf),&(t->ex),&(t->ey),&(t->ez));
    t->link=h->link;
    h->link=t;
}

void eval(tm *h)
{
    int x,y,z;
    double sum=0;
    printf("Enter the values for x,y and z:\n");
    scanf("%d%d%d",&x,&y,&z);
    tm *t;
    for(t=h->link;t!=h;t=t->link)
     sum=sum+(t->cf)*pow(x,t->ex)*pow(y,t->ey)*pow(z,t->ez);
    printf("The Evaluation result is: %lf\n",sum); 
}

void display(tm *h)
{
    if(h->link==h)
    {
        printf("There are no nodes present in csll!\n");
        return;
    }
    tm *t;
    printf("The terms of the polynomial are:\n");
    for(t=h->link;t!=h;t=t->link)
     printf("%d %d %d %d\n",t->cf,t->ex,t->ey,t->ez);
}

void polyadd(tm *h1,tm *h2,tm *h3)
{
    tm *t,*t1,*n;
    for(t=h1->link;t!=h1;t=t->link)
    {
        for(t1=h2->link;t1!=h2;t1=t1->link)
        {
            if(t1->cf!=-999 && (t->ex==t1->ex && t->ey==t1->ey && t->ez==t1->ez))
            {
                n=(tm*)malloc(sizeof(tm));
                (*n)=(*t1);
                n->cf+=t->cf;
                t1->cf=-999;
                n->link=h3->link;
                h3->link=n;
                break;
            }
        }
        if(t1==h2)
        {
            n=(tm*)malloc(sizeof(tm));
            (*n)=(*t);
            n->link=h3->link;
            h3->link=n;
        }
    }
    for(t1=h2->link;t1!=h2;t1=t1->link)
    {
        if(t1->cf!=-999)
        {
            n=(tm*)malloc(sizeof(tm));
            (*n)=(*t1);
            n->link=h3->link;
            h3->link=n;
        }
    }
}

int main()
{
    int n,i;
    tm p1={.link=&p1},p2={.link=&p2},p3={.link=&p3};
    printf("Enter the number of terms in the polynomial for evaluation:\n");
    scanf("%d",&n);
    printf("Enter the polynomial:\n");
    for(i=0;i<n;i++)
     i_f(&p1);
    eval(&p1);
    printf("Enter the number of terms in first polynomial:\n");
    scanf("%d",&n);                                                                 
    printf("Enter the polynomial 1:\n");
    for(i=0;i<n;i++)
     i_f(&p1);
    printf("Enter the number of terms in polynomial 2:\n");
    scanf("%d",&n);
    printf("Enter the second polynomial:\n");
    for(i=0;i<n;i++)
     i_f(&p2); 
    polyadd(&p1,&p2,&p3);
    printf("The result of addition is :\n");
    display(&p3); 
}