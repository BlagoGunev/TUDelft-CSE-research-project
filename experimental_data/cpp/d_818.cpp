#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5;
int a[maxn+50],f[1000000+5],mx=0;
int n,k,cnt=0;
int main()
{

    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;++i) scanf("%d",&a[i]);
    //int len;
   // for(len=n;len>=1;--len)
      //  if(a[len]==k) break;
   // if(len==0) return 0*printf("%d",a[1]);
    for(int i=1;i<=n;++i)
    {
        if(a[i]!=k)
        {
            if(f[a[i]]>=cnt)
            {


            ++f[a[i]];
            mx=max(mx,f[a[i]]);

            }continue;
        }
        ++cnt;
        if(mx<cnt) return 0*printf("-1");
    }
    for(int i=1;i<=1000000;++i)
        if(mx==f[i]) return 0*printf("%d",i);
    return 0;
}