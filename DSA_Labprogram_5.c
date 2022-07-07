#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

double compute(char syb,double op1,double op2)
{
    switch(syb)
    {
        case'+':return op1+op2;
        case'-':return op1-op2;
        case'*':return op1*op2;
        case'/':return op1/op2;
        case'$':
        case'^':return pow(op1,op2);
    }
}

void toh(int n, char source, char aux, char dest)
{
    if (n == 1)
    {
        printf("Move disk 1 from tower %c to tower %c\n", source,dest);
        return;
    }
    toh(n - 1, source, dest ,aux);
    printf("Move disk %d from tower %c to tower %c\n", n, source, dest);
    toh(n - 1, aux, source ,dest);
}

void main()
{
    char pf[20];
    double stack[20],op1,op2;
    int top=-1,i,n,ch;
    while(1)
    {
        printf("Enter choice:\n1.Postfix Evaluation\n2.Tower of Hanoi\n3.Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("Enter valid postfix expression:\n");
                   scanf("%s",pf);
                   for(i=0;pf[i]!='\0';i++)
                   {
                       if(isdigit(pf[i]))
                        stack[++top]=pf[i]-'0';
                       else
                       {
                           op2=stack[top--];
                           op1=stack[top--];
                           stack[++top]=compute(pf[i],op1,op2);
                       } 
                   }
                   printf("Result of evaluation is: %lf\n",stack[top--]);
                   break;

            case 2:printf("Enter the number of disks :\n");
                   scanf("%d", &n);
                   printf("The sequence of moves involved in the Tower of Hanoi are :\n");
                   toh(n,'A','B','C');
                   break;
            case 3:return;           
        }
    }
}