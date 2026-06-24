#include<bits/stdc++.h>

using namespace std;

#define please return

#define ac 0

#define fi first

#define se second

#define endl '\n'

#define pb push_back

#define mkp make_pair

int const N = 1e5+10;

long long const mod = 998244353;

int n;

string s;

long long quickpow(long long base,long long power,long long p){

   long long ret=1;

   while(power){

      if(power%2)

         ret=ret*base%p;

      base=base*base%p;

      power/=2;

   }

   return ret;

}

long long C(long long n,long long m,long long p){

    if(n<m)      return 0;

	if(m>n-m)     m=n-m;

	long long  a=1,b=1;

	for(int i=0;i<m;i++){

		a=(a*(n-i))%p;

		b=(b*(i+1))%p;

	}

	return a*quickpow(b,p-2,p)%p;

}

void solve(){

	cin>>n>>s;

	long long ans=1;

	long long x,y;

	x=y=0;

	for(int i=0;i<s.size();i++){

		char k=s[i];

		if(k=='0'){

			x++;

		}

		else if(s[i+1]=='1'){

			y++;

			i++;

		}

	}

	cout<<C(x+y,y,mod)<<endl;

}



int main(){

	ios::sync_with_stdio(0),cin.tie(0);

	int tt;

	cin>>tt;

	while(tt--){

		solve();

	}

	please ac;

}