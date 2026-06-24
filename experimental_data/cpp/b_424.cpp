#include<bits/stdc++.h>

using namespace std;



#define scl(x) scanf("%lld",&x)

#define sc(x)  scanf("%d",&x)

#define ll long long

#define lop(i,n) for(int i=0;i<n;++i)

typedef pair<int,int> ii;

typedef pair<ll,ll> pll;



ii arr[1010];

int n,s;



int main(){

#ifndef ONLINE_JUDGE

	freopen("i.txt","r",stdin);

#endif

	sc(n),sc(s);

	lop(i,n){

		int x,y,v;

		sc(x),sc(y),sc(v);

		arr[i]={x*x+y*y,v};

	}

	arr[n++]=ii(0,s);

	sort(arr,arr+n);

	int i=1;

	while(i!=n&&s<1000000)

		s+=arr[i].second,i++;

	if(s<1000000)puts("-1");

	else printf("%.12lf",sqrt(arr[i-1].first));

}