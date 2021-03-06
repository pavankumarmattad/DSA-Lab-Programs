#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ELE 4

void push(int[], int *);
void pop(int[], int *);
void display(int[], int *);
void palin();

int main()
{
    int ch, top = -1; 
    int s[MAX_ELE];
    for (;;)
    {
        printf("1:push\n2:pop\n3:display\n4:Palindrome\n5.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1: push(s, &top); break;
            case 2: pop(s, &top); break;
            case 3: display(s, &top); break;
            case 4: palin(); break;
            default: exit(0);
        }
    }
}

void palin()
{
    char a[20];
    int start = 0, top;
    printf("Enter any integer value\n");
    scanf("%s", a);
    top = strlen(a) - 1;
    for (; start < top;)
        if (a[top--] != a[start++])
        {
            printf("Not a palindrome number\n");
            return;
        }
    printf("Palindrome number\n");
}

void display(int s[], int *top)
{
    int i;
    if ((*top) == -1)
        printf("stack empty\n");
    else
    {
        printf("stack elements are\n");
        for (i = (*top); i >= 0; i--)
            printf("%d\n", s[i]);
    }
}

void push(int *s, int *top)
{
    int ele;
    if ((*top) == MAX_ELE - 1)
    {
        printf("stack overflow\n");
        return;
    }
    (*top)++;
    printf("enter the element\n");
    scanf("%d", &ele);
    s[*top] = ele;
}

void pop(int s[], int *top)
{
    if ((*top) == -1)
        printf("stack underflow\n");
    else
    {
        printf("Element popped is\n");
        printf("%d\n", s[*top]);
        (*top)--;
    }
}