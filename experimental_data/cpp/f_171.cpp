#include <cstdio>
const int N=2000000;
int p[N/5]={2},m=1;
bool a[N];
void pri()
{
    for(int i=3;i<N;i+=2)
        if(a[i]==false)
        {
            p[m++]=i;
            if(i>=1000)continue;
            for(int j=i*i;j<N;j+=i)
                a[j]=true;
        }
}
bool ok(int n)
{
    int tmp=0,nn=n;
    while(nn)
    {
        tmp=tmp*10+nn%10;
        nn/=10;
    }
    if(tmp==n)return false;
    if(tmp%2==1&&!a[tmp])return true;
    else return false;
}
int main()
{
    pri();
    int n,now=0,ans=0;
    scanf("%d",&n);
    for(int i=0;i<m;i++)
    {
        if(ok(p[i]))now++;
        if(now==n)
        {
            ans=p[i];
            break;
        }
    }
    printf("%d\n",ans);
    scanf(" ");
}