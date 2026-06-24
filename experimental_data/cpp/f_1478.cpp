#include<stdio.h>

#include<iostream>

#include<algorithm>

#include<cmath>

#include<queue>

#include<map>

#include<vector>

#include<stack>

#include<set>

#include<bitset>

#include<unordered_map>

#include<unordered_set>

#include<cstring>

#include<string>

//#define int long long

#define ll long long

//#define x first

//#define y second

#define all(v) v.begin(),v.end()

#define mem(x,y) memset(x,y,sizeof(x))

#define debug1(x) cout<<"*****"<<x<<endl;

#define debug() cout<<"**"<<endl;

#define debug2(x,y) cout<<"*****"<<x<<" "<<y<<endl;

#define debug3(x,y,z) cout<<"*****"<<x<<" "<<y<<" "<<z<<endl;

#define debug4(x,y,z,z1) cout<<"*****"<<x<<" "<<y<<" "<<z<<" "<<z1<<endl;

#define rb ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)

using namespace std;

const ll mod=998244353;

pair<ll,ll>p[5005];

int ans[5005];

signed main(){

	int n;

	scanf("%d",&n);

	for(int i=1;i<=n;i++){

		ans[i]=i;

		auto &[x,y]=p[i];

		scanf("%lld%lld",&x,&y);

	}

	

	auto dot=[&](pair<ll,ll>a,pair<ll,ll>b,pair<ll,ll>c){

		auto [xa,ya]=a;

		auto [xb,yb]=b;

		auto [xc,yc]=c;

		ll x1=xa-xb,x2=xc-xb,y1=ya-yb,y2=yc-yb;

		return (x1*x2+y1*y2)<=0;

	};

	for(int i=3;i<=n;i++){

		for(int j=i;j>=3;j--){

			if(dot(p[ans[j]],p[ans[j-1]],p[ans[j-2]])){

				swap(ans[j-2],ans[j-1]);

			}

		}

	}

	for(int i=3;i<=n;i++){

		if(dot(p[ans[i]],p[ans[i-1]],p[ans[i-2]])){

			puts("-1");

			return 0;

		}

	}

	for(int i=1;i<=n;i++){

		printf("%d ",ans[i]);

	}

}