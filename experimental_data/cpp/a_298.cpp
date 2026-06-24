#include<cstdio>
using namespace std;
int main()
{
    int n,i;
    scanf("%d",&n);
    char a[1009];
    scanf("%s",a);
    for( i=0;i<n;i++)
    {
        if(a[i]!='.') break;
    }
    int s=i+1;
    char c=a[i];
    for(;i<n;i++)
    {
        if(a[i]==c) continue;
        else if(a[i]!='.')
        {
            printf("%d %d\n",s,i);
            break;
        }
        else
        {
            if(c=='R')
            {
                printf("%d %d\n",s,i+1);
                break;
            }
            else
            {
                printf("%d %d\n",i,s-1);
                break;
            }
        }
    }
    return 0;
    
}