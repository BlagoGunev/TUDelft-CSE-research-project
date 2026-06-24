#include <bits/stdc++.h>

#define int long long

#define endl '\n'

#define lowbit(x) (x&(-x))

using namespace std;

const string yes="Yes\n",no="No\n";

const int mod = 998244353;

const int N = 100005;

int n,res,k,m,ans;

int l,r;

int a[200005],b[200005],c[200005];

int qpow(int x,int y,int mo=mod,int res=1){

    for(;y;y>>=1,(x*=x)%=mo) if(y&1)(res*=x)%=mo;

    return res;

}



void solve(){

    cin>>n>>m;

    for(int i=1;i<=n;i++){

        cin>>a[i];

    }

    for(int i=2;i<=n;i++){

        b[i]=b[i-1]+max(0ll,a[i-1]-a[i]);

    }

    for(int i=n-1;i;i--){

        c[i]=c[i+1]+max(0ll,a[i+1]-a[i]);

    }



    while(m--){

        cin>>l>>r;

        if(l<r){

            cout<<b[r]-b[l]<<endl;

        }

        else{

            cout<<c[r]-c[l]<<endl;

        }



    }

}

void main_init(){}

signed main(){

    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cout<<fixed<<setprecision(12);

    int t=1;

	main_init();

    //cin>>t;

    while (t--)

		solve();

}