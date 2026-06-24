#include <bits/stdc++.h>

using namespace std;
vector<pair<int,int> > v[1010];
int n,q,x,i,j,p,k,a[100010],ans[100010];
int main()
{
    scanf("%d",&n);x=sqrt(n);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    scanf("%d",&q);
    for(i=1;i<=q;i++)
    {
        scanf("%d%d",&p,&k);
        if(k>x)
            while(p<=n)
                p+=a[p]+k,ans[i]++;
        else
            v[k].push_back({p,i});
    }
    for(i=1;i<=x;i++)
        if(v[i].size())
        {
            int Ans[100010];memset(Ans,0,sizeof(Ans));
            for(j=n;j>=1;j--)
            {
                if(j+i+a[j]<=n)
                    Ans[j]=Ans[j+i+a[j]]+1;
                else
                    Ans[j]=1;
            }
            for(auto it:v[i])
                ans[it.second]=Ans[it.first];
        }
    for(i=1;i<=q;i++)
        printf("%d\n",ans[i]);
    return 0;
}