#include <stdio.h>
#include <stdlib.h>
#define HZ 3

FILE *fp;
struct employee
{
    int empno;
    char name[20];
    int sal;
};
typedef struct employee EMP;

struct hashtable
{
    int key;       // emp no; unique key value
    long int addr; // OFFSET address in file
};
typedef struct hashtable ht;

int hashval(int num)
{
    int key;
    key = num % HZ; // division method, being used to calculate hash value
    return key;
}

void search(ht *h)
{
    EMP a;
    int hindex, countindex;
    printf("Enter emp no to search\n");
    scanf("%d", &(a.empno));
    hindex = hashval(a.empno);
    countindex = hindex;
    while (h[hindex].key != a.empno)
    {
        hindex = (hindex + 1) % HZ;
        if (countindex == hindex)
        {
            printf("Search unsuccessful\n");
            return;
        }
    }
    printf("Search Successful\n");
    fseek(fp, h[hindex].addr, SEEK_SET);
    // fread(&a,sizeof(EMP),1,fp); // stores information in binary format
    fscanf(fp, "%d%s%d", &(a.empno), a.name, &(a.sal));
    printf("%d %s %d\n", a.empno, a.name, a.sal);
}

/*void display(ht *h, int n)
{
    EMP a;
    int j, i;
    for (i = 0; i < HZ; i++)
    {
        if (h[i].key != -1)
        {
            printf("Hash table: %d %d |\t", h[i].key, h[i].addr);
            fseek(fp, h[i].addr, SEEK_SET);
            // fread(&a,sizeof(EMP),1,fp);
            fscanf(fp, "%d%s%d", &(a.empno), a.name, &(a.sal));
            printf("Contents in Secondary storage: %d %s %d\n",a.empno,a.name,a.sal);
        }
    }
}*/
void insert(ht *h, int n)
{
    EMP a;
    int flag = 0;
    int i, hindex, countindex;
    for (i = 0; i < n; i++, flag = 0)
    {
        printf("Enter empno name and salary\n");
        scanf("%d%s%d", &(a.empno), a.name, &(a.sal));
        hindex = hashval(a.empno); // hash value is calculated
        countindex = hindex;
        while (h[hindex].key != -1)
        // checking whether hindex position in h is empty
        {
            hindex = (hindex + 1) % HZ;
            flag = 1;
            if (hindex == countindex)
            {
                printf("Entry not possible... \n");
                return;
            }
        }
        h[hindex].key = a.empno;
        fseek(fp, 0, SEEK_END);
        h[hindex].addr = ftell(fp);
        // fwrite(&a,sizeof(EMP),1,fp);
        fprintf(fp,"%d %s %d\n", a.empno, a.name, a.sal);
        printf("Entry successful...\n");
        if (flag)
            printf("Linear probing used\n");
    }
}

int main()
{
    ht h[HZ];
    int n, ch;
    fp = fopen("emp.txt", "w+");
    for (n = 0; n < HZ; n++) // assigning key to -1
        h[n].key = -1;
    for (;;)
    {
        printf("1. Insert\n");
        printf("2. Search\n");
        //printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter choice\n");
        scanf("%d", &ch);
        // rewind(fp);
        switch (ch)
        {
        case 1:
            printf("Enter no of employees\n");
            scanf("%d", &n);
            insert(h, n);
            break;
        case 2:
            search(h);
            break;
        // case 3:
        //     display(h, n);
        //     break;
        case 4:
            exit(0);
        }
    }
    return 0;
}