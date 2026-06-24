#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <vector>
#include <queue>
#define  inf 0x7fffffff
#define  ll  long long
#define  pb  push_back
#define  maxn 100005
using namespace std;
vector<int>e[maxn];
int n,m,x[maxn],y[maxn],h,t,s[maxn],cnt,ans[3][maxn],anscnt[3];
bool flag[maxn],FLAG[maxn],ansflag;
int f[maxn];
int main(){
    cin>>n>>m>>h>>t;
    for(int i=1;i<=m;i++){
       scanf("%d%d",&x[i],&y[i]);
       s[x[i]]++,s[y[i]]++;
       e[x[i]].pb(y[i]),e[y[i]].pb(x[i]);
    }
    for(int i=1;i<=n;i++)
       s[i]--;
    for(int i=1;i<=m;i++){
       cnt=0;
       if(s[x[i]]>=h&&s[y[i]]>=t || s[x[i]]>=t&&s[y[i]]>=h){
          for(int k=0,l=e[x[i]].size();k<l;k++)if(e[x[i]][k]!=y[i])
             flag[e[x[i]][k]]=true;
          for(int k=0,l=e[y[i]].size();k<l;k++)if(e[y[i]][k]!=x[i])
             if(flag[e[y[i]][k]])cnt++;
          if(s[x[i]]+s[y[i]]-cnt>=h+t){
             ansflag=true;
             if(s[x[i]]>=h&&s[y[i]]>=t){
                cout<<"YES"<<endl;
                cout<<x[i]<<' '<<y[i]<<endl;
                for(int k=0,l=e[y[i]].size();k<l;k++)if(e[y[i]][k]!=x[i])
                   if(!flag[e[y[i]][k]]&&t)ans[2][++anscnt[2]]=e[y[i]][k],t--;
                for(int k=0,l=e[y[i]].size();k<l;k++)if(e[y[i]][k]!=x[i]){
                   if(!t)break;
                   if(flag[e[y[i]][k]])ans[2][++anscnt[2]]=e[y[i]][k],FLAG[e[y[i]][k]]=true,t--;
                }
                for(int k=0,l=e[x[i]].size();k<l;k++)if(e[x[i]][k]!=y[i])
                   if(!FLAG[e[x[i]][k]]&&h)ans[1][++anscnt[1]]=e[x[i]][k],h--;
                break;
             }
             else if(s[x[i]]>=t&&s[y[i]]>=h){    
                cout<<"YES"<<endl;
                cout<<y[i]<<' '<<x[i]<<endl;
                for(int k=0,l=e[y[i]].size();k<l;k++)if(e[y[i]][k]!=x[i])
                   if(!flag[e[y[i]][k]]&&h)ans[1][++anscnt[1]]=e[y[i]][k],h--;
                for(int k=0,l=e[y[i]].size();k<l;k++)if(e[y[i]][k]!=x[i]){
                   if(!h)break;
                   if(flag[e[y[i]][k]])ans[1][++anscnt[1]]=e[y[i]][k],FLAG[e[y[i]][k]]=true,h--;
                }
                for(int k=0,l=e[x[i]].size();k<l;k++)if(e[x[i]][k]!=y[i])
                   if(!FLAG[e[x[i]][k]]&&t)ans[2][++anscnt[2]]=e[x[i]][k],t--;
                break;
             }
          }
          for(int k=0,l=e[x[i]].size();k<l;k++)
             flag[e[x[i]][k]]=false;
       }
    }
    if(ansflag){
       for(int i=1;i<=2;i++)
          for(int j=1;j<=anscnt[i];j++)
             printf("%d%s",ans[i][j],j==anscnt[i]?"\n":" ");
    }
    else cout<<"NO"<<endl;
    return 0;
}