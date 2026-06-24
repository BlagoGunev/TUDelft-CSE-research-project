#pragma GCC optimize("Ofast")

#pragma GCC target("avx,avx2,fma")



#include<bits/stdc++.h>

#define itn int

#define ll long long

#define pir pair<ll,ll>

#define fi first

#define se second

#define pb push_back

using namespace std;



ll read(){

	ll a=0;bool b=0;char c=getchar();

	while(c>'9'||c<'0')b^=(c=='-'),c=getchar();

	while(c>='0'&&c<='9')a=a*10+c-48,c=getchar();

	return b?-a:a;

}



const int N=300005;

int n,q,a[N],b[N],t[N],s[N];

vector<int>ed[N]; 

void add(int i,int k){for(;i<N;i+=i&-i)t[i]+=k;}



int main(){

	n=read(),q=read();

	for(int i=1;i<=n;i++)a[i]=i-read();

	for(int i=1;i<=q;i++){

		b[i]=read()+1, ed[n-read()].push_back(i);

	}

	for(int i=1;i<=n;i++){

		if(a[i]>=0){

			int nu=0,nw=0;

			for(int j=18;j>=0;j--){

				if(nw+(1<<j)<=i&&nu+t[nw+(1<<j)]>=a[i]){

					nw+=(1<<j);nu+=t[nw];

				}

			}

			add(1,1);add(nw+1,-1);

		}

		for(int j:ed[i]){

			for(int k=b[j];k;k-=k&-k)s[j]+=t[k];

		}

	}

	for(int i=1;i<=q;i++)cout<<s[i]<<'\n';

	return 0;

}