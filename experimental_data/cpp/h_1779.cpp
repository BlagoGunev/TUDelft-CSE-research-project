#include<cstdio>

#include<cstring>

#include<iostream>

#include<algorithm>

#include<unordered_map>

#include<vector>

#include<numeric>

#include<cmath>

#include<array>

#include<map>

#include<set>

#include<queue>

using namespace std;

#define ll long long

#define uint unsigned int

#define ge getchar 

#define pun putchar('\n')

#define pu putchar

#define puk putchar(' ')

#define pb push_back

#define hl '\n'

typedef vector<ll> vll;

typedef array<int,2> pii;

const int nn=40;

int n;

ll a[nn],b[nn],S;

vll operator - (const vll&a,const vll&b){

	vll c;

	int m=b.size(),l=0;

	for(auto u:a){

		if(l<m&&u==b[l]){

			l++;

		}else c.pb(u);

	}

	return c;

}

int y[1<<12],ny[1<<12];

ll s[1<<12];

vll o[9];

void pre(){

	int zt=1<<12;

	for(int i=1;i<zt;i++)y[i]=y[i>>1]+(i&1);

	for(int i=0;i<12;i++)ny[1<<i]=i;

}

bool eat(int h,ll sx,vll a){//h<=8 maxsum<=sx n=3*h<=24; 2^{n/2}*n/2

	//2(sx+maxsum)>=S

	ll xx=(S+1)/2-sx;

	if(xx>sx)return 0;

	int n=h*3/2;

	int zt=1<<n;

	for(int i=1;i<zt;i++)s[i]=s[i^(i&-i)]+a[ny[i&-i]];

	for(int i=0;i<=h;i++)o[i].clear();

	for(int i=0;i<zt;i++)if(y[i]<=h&&s[i]<=sx)o[y[i]].pb(s[i]);

	for(int i=0;i<=h;i++)sort(o[i].begin(),o[i].end());

	for(int i=1;i<zt;i++)s[i]=s[i^(i&-i)]+a[n+ny[i&-i]];

	ll mx=0,u=0;

	for(int i=0;i<zt;i++)if(y[i]<=h&&s[i]<=sx){

		if(o[h-y[i]].size()){

			ll x=sx-s[i];//max <=x

			auto&r=o[h-y[i]];

			auto p=upper_bound(r.begin(),r.end(),x);

			if(p!=r.begin()){

				auto rs=*(p-1);

				if(rs+s[i]>mx){

					mx=rs+s[i];

					if(mx>=xx)return 1;

				}

			}

		}

	}

	return 0;

}

bool chk(int h,ll sum,vll a){

	if(h*2==n)return sum*2>=S;

	if(h*4==n){//h<=8

		//eat max h

		return eat(h,sum,a);

	}

	//h=2,4

	if(h==2){

		int l=0,r=a.size()-1;

		while(l<r){

			while(l<r&&a[l]+a[r]>sum)r--;

			if(l==r)return 0;

			while(l+1<r&&a[l+1]+a[r]<=sum)l++;

			vll d={a[l],a[r]};

			bool ok=chk(h*2,sum+a[l]+a[r],a-d);

			if(ok)return 1;

			l++;r--;

		}

		return 0;

	}

	//h=4

	int m=a.size();

	for(int i=0;i+3<m;i++)

		for(int j=i+1;j+2<m;j++)

			for(int k=j+1;k+1<m;k++){

				int l=k+1;

				ll s=a[i]+a[j]+a[k];

				if(s+a[l]>sum)continue;

				while(l+1<m&&s+a[l+1]<=sum)l++;

				if(i+1<j&&a[i+1]+a[j]+a[k]+a[l]<=sum)continue;

				if(j+1<k&&a[i]+a[j+1]+a[k]+a[l]<=sum)continue;

				if(k+1<l&&a[i]+a[j]+a[k+1]+a[l]<=sum)continue;

				vll d={a[i],a[j],a[k],a[l]};

				bool ok=chk(h*2,sum+s+a[l],a-d);

				if(ok)return 1;

			}

	return 0;

}

bool win(int k){

	vll c(n);

	for(int i=0;i<n;i++)c[i]=b[i];

	for(int i=n-1;i>=0;i--)if(i!=k&&b[i]<=b[k]){

		vll d={b[i],b[k]};

		bool ok=chk(2,b[i]+b[k],c-d);

		if(ok)return 1;

	}

	return 0;

}



int main(){

	pre();

	scanf("%d",&n);

	for(int i=0;i<n;i++)scanf("%lld",&a[i]);

	for(int i=0;i<n;i++)b[i]=a[i],S+=b[i];

	sort(b,b+n);

	int l=0,r=n-1;//>=r win,<l lose

	while(l<r){

		int m=l+r>>1;

		if(win(m))r=m;else l=m+1;

	}

	for(int i=0;i<n;i++)if(a[i]>=b[r])pu('1');else pu('0');pun; 

	return 0;

}