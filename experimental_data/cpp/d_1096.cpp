#include<cstdio>
#include<algorithm>
using namespace std;
char s[100001];
int a[100001];
long long cmin[100001][4];
int main()
{
//    freopen("f.in","r",stdin);
//    freopen("f.out","w",stdout);
    int n,i;
    scanf("%d\n%s\n",&n,s);
    for(i=0;i<n;++i)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;++i)
    {
        if(s[i]!='h')
            cmin[i+1][1]=cmin[i][1];
        else
            cmin[i+1][1]=cmin[i][1]+1LL*a[i];
        if(s[i]!='a')
            cmin[i+1][2]=cmin[i][2];
        else
            cmin[i+1][2]=min(cmin[i][2]+1LL*a[i],cmin[i][1]);
        if(s[i]!='r')
            cmin[i+1][3]=cmin[i][3];
        else
            cmin[i+1][3]=min(cmin[i][3]+1LL*a[i],cmin[i][2]);
        if(s[i]!='d')
            cmin[i+1][4]=cmin[i][4];
        else
            cmin[i+1][4]=min(cmin[i][4]+1LL*a[i],cmin[i][3]);
    }
    printf("%I64d\n",cmin[n][4]);
    return 0;
}