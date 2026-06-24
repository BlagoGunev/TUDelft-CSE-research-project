#include<stdio.h>
#include<string.h>
int main()
{
    char a[105];
    int n,i,b[105];
    while(~scanf("%d",&n))
    {
        scanf("%s",a);
        memset(b,0,sizeof(b));
        for(i=0;i<n;i++)
        {
            if(a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u'||a[i]=='y')
                 b[i]=1;
        }
        for(i=1;i<n;i++)
        {
            if(b[i]==1&&b[i-1]==1)
            {
                a[i]='0';
            }
        }
        for(i=0;i<n;i++)
        {
            if(a[i]=='0')
            {
                continue;
            }
            else
            {
                printf("%c",a[i]);
            }
        }
        printf("\n");
    }
    return 0;
}