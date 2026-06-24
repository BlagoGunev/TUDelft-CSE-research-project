// LUOGU_RID: 103380582
#include<bits/stdc++.h>

using namespace std;

#define rd(i,n) for(int i=0;i<n;i++)

#define rp(i,n) for(int i=1;i<=n;i++)

#define rep(i,a,b) for(int i=a;i<=b;i++)

#define per(i,a,b) for(int i=b;i>=a;i--)

#define st string

#define vt vector

#define pb push_back

//#define int long long

typedef long long ll;

typedef long double ld;

typedef pair<int,int> pii;

typedef pair<ll,ll> pll;

ll t,d[300005];

ll n,T,m,ans[300005],x[300005];

ll lst[300005],nto[300005],to[300005],rk[300005];

char c;

signed main(){

	ios::sync_with_stdio(false);

	cin.tie(0);

//	freopen("f.in","r",stdin);

//	freopen("f.out","w",stdout);

	cin>>n>>m>>T;

	t=T;

	ll out=0;

	rp(i,n){

		cin>>x[i]>>c;x[i]--;to[i]=i;

		if(c=='R')d[i]=1,out=(out+(x[i]+t)/m%n)%n;

		else {

			d[i]=-1;

			if(t>x[i]){

//				cout<<1<<endl;

//				cout<<(t-x[i])/m<<endl;

				out=(out-1-(t-1-x[i])/m%n+n+n)%n;

			}

		}

		lst[i]=(x[i]+d[i]*t%m+m)%m;

	}

	sort(to+1,to+1+n,[](int a,int b){

		if(x[a]==x[b])return d[a]<d[b];

		return x[a]<x[b];

	});

	out=(out%n+n)%n;

//	cout<<out<<endl;

	rp(i,n)nto[(i-1+out)%n+1]=to[i];

//	rp(i,n)cout<<to[i]<<" ";

//	cout<<endl;

//	rp(i,n)cout<<nto[i]<<" ";

//	cout<<endl;

	rp(i,n)rk[nto[i]]=i;

//	rp(i,n)cout<<rk[i]<<" ";

//	cout<<endl;

	sort(lst+1,lst+1+n);

	rp(i,n)ans[i]=lst[rk[i]];

	rp(i,n)cout<<ans[i]+1<<" ";

	cout<<endl;

	return 0;

}

//Crayan_r