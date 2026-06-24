#include<bits/stdc++.h>
using namespace std;
#define maxx 1000001
#define m 1000000

int n,cn,top;
int t[maxx],ans[maxx],sta[maxx],ls[21000000],rs[21000000],fa[maxx][20];

void up(int &o,int lst,int l,int r,int x)
{
    cn=cn+1;
    o=cn;
    ls[o]=ls[lst];
    rs[o]=rs[lst];
    if(l==r)
    {
        return;
    }
    int mid=l+(r-l)/2;
    if(x<=mid)
    {
        up(ls[o],ls[lst],l,mid,x);
    }
    else
    {
        up(rs[o],rs[lst],mid+1,r,x);
    }
}

bool as(int o,int l,int r,int x)
{
    if(o==0)
    {
        return 0;
    }
    else if(l==r)
    {
        return 1;
    }
    int mid=l+(r-l)/2;
    if(x<=mid)
    {
        return as(ls[o],l,mid,x);
    }

    return as(rs[o],mid+1,r,x);
}

main()
{
    sta[top]=1;
    n=1;
    int q;
    cin >> q;
    while(q--)
    {
        char ch;
        cin >> ch;
        if(ch=='+')
        {
            int x;
            cin >> x;
            n=n+1;
            fa[n][0]=sta[top];
            sta[++top]=n;
            if(as(t[fa[n][0]],1,m,x)==0)
            {
                ans[n]=ans[fa[n][0]]+1;
                up(t[n],t[fa[n][0]],1,m,x);
            }
            else
            {
                ans[n]=ans[fa[n][0]];
                t[n]=t[fa[n][0]];
            }
            for(int i=1;i<20;i++)
            {
                fa[n][i]=fa[fa[n][i-1]][i-1];
            }
        }
        else if(ch=='-')
        {
            int x;
            cin >> x;
            int u=sta[top];
            for(int i=0;i<20;i++)
            {
                if((x>>i)%2)
                {
                    u=fa[u][i];
                }
            }
            sta[++top]=u;
        }
        else if(ch=='!')
        {
            top=top-1;
        }
        else if(ch=='?')
        {
            cout << ans[sta[top]] << endl;
            fflush(stdout);
        }
    }

    return 0;
}