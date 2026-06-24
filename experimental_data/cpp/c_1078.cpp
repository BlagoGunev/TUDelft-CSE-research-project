#include <bits/stdc++.h>
#define MOD  998244353

using namespace std;
long long dp[1000005][3];
vector<int> V[1000005];
void dfs(int n,int p=-1){
    if(V[n].size()==1 && p!=-1){
        dp[n][0]=1;return;
    }
    for(int i=0;i<V[n].size();++i){
        if(V[n][i]==p)continue;
        dfs(V[n][i],n);

    }
    long long temp[3];temp[0]=temp[1]=temp[2]=0;temp[0]=1;
    bool flag=0;
    for(int i=0;i<V[n].size();++i){
        if(V[n][i]==p) continue;

        long long temp0,temp1,temp2;temp0=temp1=temp2=0;
        temp0=(temp[0]*dp[V[n][i]][0]+temp[0]*dp[V[n][i]][1])%MOD;
        temp1=((temp[0]*(dp[V[n][i]][0]+dp[V[n][i]][2]))%MOD+(temp[1]*dp[V[n][i]][0])%MOD+(temp[1]*2ll*dp[V[n][i]][1])%MOD+temp[2]*(dp[V[n][i]][0]+dp[V[n][i]][2]))%MOD;
        temp2=(temp[0]*dp[V[n][i]][1]+temp[2]*(dp[V[n][i]][0]+2ll*dp[V[n][i]][1]))%MOD;
        temp[0]=temp0;
        temp[1]=temp1;
        temp[2]=temp2;
    }

    dp[n][0]=temp[0];dp[n][1]=temp[1];dp[n][2]=temp[2];
     // cout << n << " " << 0 << " " << dp[n][0] << " " << n << " " << 1 << " " << dp[n][1] << endl;
}
int main(){
    int n;cin >> n;
   
    int deg=0;int ind=-1;
    for(int i=1;i<n;++i){
        int a,b;scanf("%d %d",&a,&b);
        V[a].push_back(b);
        V[b].push_back(a);
    }
    for(int i=1;i<=n;++i){
        if(V[i].size()>1){
            ind=i;break;
        }
    }
    if(n==1){
        cout << "1" << endl;return 0;
    }
    if(n==2){
        cout << "2" << endl;return 0;
    }ind=1;
    dfs(ind);
    cout << (dp[ind][0]+dp[ind][1])%MOD << endl;
    return 0;
}