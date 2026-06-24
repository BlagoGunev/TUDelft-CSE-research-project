#include <bits/stdc++.h>

using namespace std;

const int maxn = 2010;

const int MOD=1e9+7;

char a[maxn],b[maxn],*p;

int n,m,d;

int dp[maxn][maxn];

void add(int &x,int y){

    x+=y;

    x%=MOD;

}

int dfs(int l,int mod,int jud){

    if(l==n+1) return !mod;

    if(!jud&&dp[l][mod]!=-1) return dp[l][mod];

    int ret=0;

    int to=jud?p[l]:9;

    for(int i=0; i<=to; i++){

        if(l&1){

            if(i==d) continue;

            add(ret,dfs(l+1,(mod*10+i)%m,jud&&i==to));

        }

        else{

            if(i!=d) continue;

            add(ret,dfs(l+1,(mod*10+i)%m,jud&&i==to));

        }

    }

    if(!jud) dp[l][mod]=ret;

    return ret;

}

bool judge(){

    int mod=0;

    for(int i=1; i<=n; i++){

        mod=(mod*10+a[i])%m;

        if(i&1){

            if(a[i]==d) return false;

        }else{

            if(a[i]!=d) return false;

        }

    }

    return !mod;

}

int f(char *a){

    p=a;

    return dfs(1,0,1);

}

int main()

{

    while(scanf("%d%d%s%s",&m,&d,a+1,b+1)!=EOF){

        memset(dp,-1,sizeof(dp));

        n=strlen(a+1);

        for(int i=1; a[i]; i++) a[i]=a[i]-'0';

        for(int i=1; b[i]; i++) b[i]=b[i]-'0';

        //cout<<f(a)<<" "<<f(b)<<endl;

        int ans=f(b);

        add(ans,MOD-f(a)+judge());

        cout<<ans<<endl;

    }

}