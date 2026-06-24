#include "bits/stdc++.h"

#define MAXN 1000009

#define INF 1000000007

#define mp(x,y) make_pair(x,y)

#define all(v) v.begin(),v.end()

#define pb(x) push_back(x)

#define wr cout<<"----------------"<<endl;

#define ppb() pop_back()

#define tr(ii,c) for(typeof((c).begin()) ii=(c).begin();ii!=(c).end();ii++)

#define ff first

#define ss second



using namespace std;



typedef long long ll;

typedef pair<ll,ll> PII;

template<class T>bool umin(T& a,T b){if(a>b){a=b;return 1;}return 0;}

template<class T>bool umax(T& a,T b){if(a<b){a=b;return 1;}return 0;}

ll dp[MAXN],F[MAXN],cnt[MAXN];

ll arr[MAXN],tree[MAXN];

void upd(ll x){

	for(;x<MAXN;x+=x&(-x))

		tree[x]++;

}

ll tap(ll x){

	ll res=0;

	for(;x>0;x-=x&(-x))

		res+=tree[x];

	return res;	

}

ll mod(ll x){

	return (x%INF);

}

ll Fe(ll x,ll y){

	if(!y)

		return 1LL;

	ll h=Fe(x,y/2);

	h=mod(h*h);

	if(y&1)

		h=mod(h*x*1LL);

	return h;

}

int main(){

	#ifndef ONLINE_JUDGE

    freopen("file.in", "r", stdin);

	#endif	

	ll n;

	scanf("%lld",&n);

	dp[1]=0;dp[2]=1;dp[3]=9;

	F[1]=1;F[2]=2;F[3]=6;

	ll four=Fe(4,INF-2),ans=0,two=Fe(2,INF-2);

	for(ll i=4;i<MAXN;i++){

		F[i]=mod(F[i-1]*i);

		dp[i]=mod(mod(F[i]*four)*mod(i*(i-1)));	

	}

	for(ll i=1;i<=n;i++)

		scanf("%lld",arr+i);ll rem=1;

	cnt[n]=1;upd(arr[n]);

	for(ll i=n-1;i>1;i--){

		cnt[i]=mod(tap(arr[i]-1)*F[rem++]+cnt[i+1]);

		upd(arr[i]);

	}	

	memset(tree,0,sizeof tree);rem=n;

	for(ll i=1;i<=n;i++){

		ll pos=arr[i]-tap(arr[i]-1);

		ans=mod(ans+mod((pos-1)*dp[rem-1]));

		ll all=mod((pos-2)*(pos-1));

		all=mod(all*two);

		ans=mod(ans+mod(F[--rem]*all));

		if(!rem)

			break;

		ans=mod(ans+mod((pos-1)*cnt[i+1]));	

		upd(arr[i]);

	}	

	printf("%lld\n",ans);

	return 0;

}