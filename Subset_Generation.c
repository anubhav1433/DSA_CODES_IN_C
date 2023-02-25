#include<stdio.h>
#include<math.h>

int main()
{
    int n;
    scanf("%d",&n);
    char set[n];
    for(int i=0;i<n;i++)
    {
        scanf("%c ",&set[i]);
    }
    int p=pow(2,n);
        for(int i=0;i<p;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i & (1<<j))
                    printf("%c",set[j]);
            }
            printf("\n");
        }
        return 0;
}