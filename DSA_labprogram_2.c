#include<stdio.h>
#include<string.h>

void read(char *str,char *pat,char *rep)
{
    printf("Enter the main string:\n");
    scanf(" %[^\n]s",str);
    printf("Enter the pattern string: \n");
    scanf(" %[^\n]s",pat);
    printf("Enter the replacement string:\n");
    scanf(" %[^\n]s",rep);
}

void pat_match(char *str,char *pat,char *rep,char *ans)
{
    int c,m,i,k,j,flag;
    c=m=i=k=j=flag=0;
    while(str[c]!='\0')
    {
        if(str[m]==pat[i])
        {
            i++; m++;
            if(pat[i]=='\0')
            {
                printf("\nPat :%s is found at position: %d\n",pat,c);
                flag=1;
                for(;rep[k]!='\0';k++,j++)
                    ans[j]=rep[k];
                i=k=0; c=m; 
            }
        }
        else
        {
            ans[j]=str[c];
            j++; c++; m=c; i=0;
        }
    }
    if(flag==0)
      printf("Pat: %s not found in the string %s",pat,str);
    else
    {
        ans[j]='\0';
        printf("The resulting string is: %s\n",ans);
    }
}

void main()
{
    char str[100],pat[100],rep[100],ans[100];
    read(str,pat,rep);
    pat_match(str,pat,rep,ans);
}