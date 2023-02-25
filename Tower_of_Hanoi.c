#include<stdio.h>
void tow(int n,char s,char d,char aux)
{
    static int c=0;
    c++;
    if(n==1)
    {
        printf("move %d from %c to %c\n",n,s,d);
    }
    else
    {
        tow(n-1,s,aux,d);
        printf("move %d from %c to %c\n",n,s,d);
        tow(n-1,aux,d,s);
    }
}
int main()
{
    //printf("%d",10);
    tow(3,'A','B','C');
}