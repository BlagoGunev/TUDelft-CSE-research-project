#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n,p[N],mk[N],f[N],bk[N],ans;
struct node{
    int num,sm;
    friend bool operator<(node a,node b){
        return a.sm>b.sm;
    }
};
priority_queue<node>q;
signed main(){
    cin>>n;
    for(int i=1;i<=n;i++)scanf("%lld",&p[i]),f[p[i]]++;
    for(int i=1;i<=n;i++)q.push((node){i,f[i]});
    while(q.size()){
        node qq=q.top();
        q.pop();
        if(qq.sm>0)break;
        mk[qq.num]=1;
        if(mk[p[qq.num]]){
            cout<<-1;
            return 0;
        }
        bk[qq.num]=1;
        if(bk[p[qq.num]])continue;
        bk[p[qq.num]]=1;
        f[p[p[qq.num]]]--;
        q.push((node){p[p[qq.num]],f[p[p[qq.num]]]});
    }
    for(int i=1;i<=n;i++){
        if(bk[i])continue;
        int nw=i,op=0;
        while(1){
            if(bk[nw]){
                if(op==1){
                    cout<<-1;
                    return 0;
                }
                break;
            }
            op^=1;
            if(op)mk[nw]=1;
            bk[nw]=1;
            nw=p[nw];
        }
    }
    for(int i=1;i<=n;i++)ans+=mk[i];
    cout<<ans<<endl;
    for(int i=1;i<=n;i++)if(mk[i])printf("%lld ",p[i]);
}