#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int>num[200010];
int deep[200010],st[200010][20];           //倍增优化查询LCA
int sum[200010][30];
void dfs(int x,int fa){
    deep[x]=deep[fa]+1;st[x][0]=fa;
    for(int i=0;i<30;i++)
    sum[x][i]+=sum[fa][i];
    for(int i=1;i<=19;i++)
    st[x][i]=st[st[x][i-1]][i-1];
    for(auto i:num[x])
    if(i!=fa)dfs(i,x);
}
int lca(int x,int y){
    if(deep[x]<deep[y])
    swap(x,y);
    int h=deep[x]-deep[y];
    for(int i=19;i>=0;i--)
    if(h>=(1<<i))h-=1<<i,x=st[x][i];
    if(x==y)return x;
    for(int i=19;i>=0;i--)
    if(st[x][i]!=st[y][i])
    x=st[x][i],y=st[y][i];
    return st[x][0];
}
int f(int x,int y,bitset<35>&now){
    int ans=0;
    if(deep[x]<deep[y])swap(x,y);
    y=st[y][0];
    for(int i=0;i<30;i++)if(!now[i]){
        if(sum[x][i]-sum[y][i])ans++;
    }
    else ans++;
    return ans;
}
int main(){
    int t;scanf("%d",&t);
    while(t--){
        int n;scanf("%d",&n);
        for(int i=1;i<=n;i++){
            int x;scanf("%d",&x);
            for(int j=0;j<30;j++)
            sum[i][j]=x>>j&1;
            num[i].clear();
        }
        for(int i=1;i<n;i++){
            int x,y;scanf("%d%d",&x,&y);
            num[x].push_back(y);
            num[y].push_back(x);
        }dfs(1,0);
        int q;scanf("%d",&q);
        while(q--){
            int x,y;scanf("%d%d",&x,&y);
            int mid=lca(x,y);
            int s=0,d=0;
            bitset<35>now,opp;
            for(int i=0;i<30;i++){
                if(sum[x][i]-sum[st[x][0]][i])s++,now[i]=1;
                if(sum[x][i]+sum[y][i]-2*sum[st[mid][0]][i])d++;
            }
            int flag=0,p=x,ans=s+d;
            if(x==mid)flag=1;
            for(int i=s;i<=d;i++){
                if(s<i){
                    if(!flag){
                        for(int j=19;j>=0;j--)
                        if(deep[st[p][j]]>=deep[mid]&&f(st[p][j],x,now)<i){
                            p=st[p][j];
                        }
                        p=st[p][0];
                        if(deep[mid]>deep[p])p=mid;
                        s=f(p,x,now);
                        if(p==mid){
                            for(int j=0;j<30;j++)
                            if(sum[x][j]-sum[st[mid][0]][j])now[j]=1;
                            flag=1;
                        }
                    }//printf("%d %d\n",i,p);
                    if(flag&&s<i){
                        int l=y;
                        for(int j=19;j>=0;j--)
                        if(deep[st[l][j]]>=deep[mid]&&f(mid,st[l][j],now)>=i){
                            l=st[l][j];
                        }p=l;s=f(p,mid,now);
                    }
                }
                if(s>i)continue;
                if(flag)ans=max(ans,i+f(p,y,opp));
                else {
                    int res=0;
                    for(int i=0;i<30;i++)
                    if(sum[p][i]+sum[y][i]-2*sum[st[mid][0]][i])res++;
                    ans=max(ans,res+i);
                }
            }
            printf("%d ",ans);
        }puts("");
    }
}