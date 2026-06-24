#include<bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")

//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#define F first

#define S second

#define all(x) x.begin(),x.end()

#define pb(x) push_back(x)

#define int long long

typedef long long ll;

void setIO(string s) {

    freopen((s + ".in").c_str(), "r", stdin);

    freopen((s + ".out").c_str(), "w", stdout);

}const int sz=3e5+5;

const int MOD=998244353;

int one[2][2];

int zero[2][2];

struct dat{

    int mat[2][2];

};

dat merge(dat a,dat b){

    dat c={};

    for(int i=0;i<2;i++){

        for(int j=0;j<2;j++){

            for(int k=0;k<2;k++){

                c.mat[i][j]=(c.mat[i][j]+a.mat[i][k]*b.mat[k][j])%MOD;

            }

        }

    }/*for(int i=0;i<2;i++){

        for(int j=0;j<2;j++){

            cout<<a.mat[i][j]<<' ';

        }cout<<'\n';

    }for(int i=0;i<2;i++){

        for(int j=0;j<2;j++){

            cout<<b.mat[i][j]<<' ';

        }cout<<'\n';

    }for(int i=0;i<2;i++){

        for(int j=0;j<2;j++){

            cout<<c.mat[i][j]<<' ';

        }cout<<'\n';

    }cout<<'\n';*/

    return c;

}

dat seg[4*sz];

void build(int l,int r,int id){

    if(l==r){

        for(int i=0;i<2;i++){

            for(int j=0;j<2;j++){

                seg[id].mat[i][j]=zero[i][j];

            }

        }return;

    }int mm=l+(r-l)/2;

    build(l,mm,id*2);

    build(mm+1,r,id*2+1);

    seg[id]=merge(seg[id*2],seg[id*2+1]);

}

void modify(int l,int r,int val,int pos,int id){

    if(l==r){

        if(val==1){

            for(int i=0;i<2;i++){

                for(int j=0;j<2;j++){

                    seg[id].mat[i][j]=one[i][j];

                }

            }

        }else{

            for(int i=0;i<2;i++){

                for(int j=0;j<2;j++){

                    seg[id].mat[i][j]=zero[i][j];

                }

            }

        }

        return;

    }int mm=l+(r-l)/2;

    if(pos<=mm){

        modify(l,mm,val,pos,id*2);

    }else{

        modify(mm+1,r,val,pos,id*2+1);

    }

    seg[id]=merge(seg[id*2],seg[id*2+1]);

}

signed main(){

    ios::sync_with_stdio(0);

    cin.tie(0);cout.tie(0);

    //setIO("Ian");

    zero[0][0]=3;

    zero[0][1]=0;

    zero[1][0]=1;

    zero[1][1]=2;

    one[0][0]=1;

    one[0][1]=2;

    one[1][0]=1;

    one[1][1]=2;

	int n;

    cin>>n;

    vector<vector<pair<int,int>>>v(sz);

    for(int i=1;i<=n;i++){

        int a,b;

        cin>>a>>b;

        v[a].push_back({1,i});

        v[b+1].push_back({0,i});

    }build(1,n-1,1);

    ll ans=0;

    int cur=0;

    for(int i=0;i<=300000;i++){

        for(auto x:v[i]){

            if(x.S==1)cur=x.F;

            else{

                modify(1,n-1,x.F,x.S-1,1);

            }

        }ans=(ans+seg[1].mat[cur][1])%MOD;

        //if(i<=4)cout<<ans<<'\n';  

    }cout<<ans<<'\n';

}