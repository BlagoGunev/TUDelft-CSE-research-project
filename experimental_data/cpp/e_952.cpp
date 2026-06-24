#include<stdio.h>
#include<map>
#include<string>
#include<set>
#include<time.h>
#include<stdlib.h>
using namespace std;
int a[1005];
int main()
{
    int i,j,n,a=0,b=0;
    scanf("%d",&n);
    char s1[105],s2[105];
    for(i=1;i<=n;i++)
    {
        scanf("%s%s",s1,s2);
        if(s2[0]=='s')
        {
            a++;
        }
        else
            b++;
          //  printf("%d %d\n",a,b);
    }
    if(a>b)
        swap(a,b);
    for(i=1;i<=20;i++)
    {
        int c=0,d=0;
        for(j=1;j<=i;j++)
        {
            if(j&1)
                c+=(i+1)/2,d+=i/2;
            else
                 d+=(i+1)/2,c+=i/2;
        }
     //   printf("%d %d %d %d",c,d,a,b);
        if(c>=b&&d>=a)
            break;
    }
    printf("%d\n",i);
    return 0;
}