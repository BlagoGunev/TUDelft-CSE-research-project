#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Rof(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int Maxn=2e5;

inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0' || ch>'9')
    {
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0' && ch<='9')
    {
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}

int n,vis[Maxn+5],ans[Maxn+5];
vector<int> v[Maxn+5];
stack<int> st;

inline int dfs(int x)
{
    if(ans[x]) return ans[x];
    if(vis[x]) while(!st.empty())
    {
        int k=st.top(); st.pop();
        vis[k]=0,v[k].pop_back();
        if(k==x) break;
    } if(v[x].empty()) return x;
    vis[x]=1,st.push(x); return dfs(v[x].back());
}

int main()
{
    // freopen("1.in","r",stdin);

    n=read(); For(i,1,n) {int k=read(); while(k--) v[i].push_back(read());}
    For(i,1,n)
    {
        printf("%d ",ans[i]=dfs(i));
        while(!st.empty()) ans[st.top()]=ans[i],st.pop();
    } printf("\n");
    return 0;
}