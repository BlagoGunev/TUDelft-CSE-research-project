#include<stdio.h>
#include<string.h>
#include<queue>
#include<algorithm>
#include<math.h>
using namespace std;
int main()
{
    int n,x,i,m;
    int a[3];
    scanf("%d%d",&n,&x);
    n=n%6;
        memset(a,0,sizeof(a));
        a[x]=1;
        if(n%2==0)
        {
            while(n)
            {
                swap(a[2],a[1]);
                n--;
                swap(a[1],a[0]);
                n--;
            }
        }
        else
        {
            swap(a[0],a[1]);
            n--;
            while(n)
            {
                swap(a[2],a[1]);
                n--;
                if(n==0)
                    break;
                swap(a[1],a[0]);
                n--;
            }
        }
        for(i=0; i<3; i++)
        {
            if(a[i]==1)
            {
                printf("%d\n",i);
                break;
            }
        }
    return 0;
}