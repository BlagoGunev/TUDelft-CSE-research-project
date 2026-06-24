#include<bits/stdc++.h>
using namespace std;
#define N   500005
#define CH  (ch=getchar())

int n,m,f[35],pos[35],a[N],ans[N],x,y,l,r,mid,R;
vector <pair<int,int> > P[N];

int IN()
{
    char ch;int x=0;
    for (CH;ch>'9'||ch<'0';CH);
    for (;ch>='0'&&ch<='9';CH) (x*=10)+=ch-'0';
    return x;
}

int main()
{
    n=IN();
    for (int i=1;i<=n;i++) a[i]=IN();
    m=IN();
    for (int i=1;i<=m;i++)
    {
        x=IN();
        y=IN();
        P[x].push_back(make_pair(y,i));
    }
    for (int i=n;i;i--)
    {
        x=a[i];
        y=i;
        for (int j=29;j>=0;j--)
        {
            if (x&(1<<j))
            {
                if (!f[j])
                {
                    f[j]=x;
                    pos[j]=y;
                    break;
                }
                if (y<pos[j])
                {
                    swap(x,f[j]);
                    swap(y,pos[j]);
                }
                x^=f[j];
            }
        }
        for (auto it:P[i])
        {    
            R=it.first;
            int tmp=0;
            for (int j=29;j>=0;j--)
            {
                //printf("%d\n",tmp);
                if ((pos[j]<=R)&&((tmp^f[j])>tmp)) tmp^=f[j];
            }
            ans[it.second]=tmp;
        }
    }
    for (int i=1;i<=m;i++) printf("%d\n",ans[i]);
}