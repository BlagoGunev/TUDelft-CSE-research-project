#include<cstdio>
#include<cstring>
#include<cctype>
#include<algorithm>
using namespace std;
int gti(void)
{
    char c=getchar();
    int st=1,ret=0;
    for (;!isdigit(c)&&c!='-';c=getchar());
    if (c=='-') st=-1,c=getchar();
    for (;isdigit(c);c=getchar()) ret=ret*10+c-'0';
    return ret*st;
}
const int N=1e9;
int y,n;
int step[200200];

int main(void)
{
    n=gti();
    for (int i=1;i<=n;i++) step[i]=gti();
    for (int i=2;i<=n;i++)
    {
        int k=step[i]-step[i-1];
        k=k<0?-k:k;
        if (k==0)
        {
            printf("NO\n");
            return 0;
        }
        if (k!=1&&y&&y!=k)
        {
            printf("NO\n");
            return 0;
        }
        if (k!=1&&y==0)
            y=k;
    }
    if (y==0) y=N;
    for (int i=2;i<=n;i++)
    {
        int k=step[i]-step[i-1];
        k=k<0?-k:k;
        if (k==1&&(step[i]-1)/y!=(step[i-1]-1)/y)
        {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n%d %d\n",N,y);
    return 0;
}