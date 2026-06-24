#include<bits/stdc++.h> 

#define Mod 998244353 

#define gc getchar() 

#define PB push_back 

#define ll long long 

#define I inline int 

#define V inline void 

#define LL inline long long 

#define FOR(i,a,b) for(int i=a;i<=b;i++) 

#define ROF(i,b,a) for(int i=b;i>=a;i--) 

using namespace std;

LL read(){

	ll x=0;bool fl=0;char s=gc;

	while('0'>s||s>'9'){fl|=(s=='-');s=gc;}

	while('0'<=s&&s<='9'){x=x*10+s-48;s=gc;}

	return fl?-x:x;

}



const int N=100011;

int n,a[N];

ll f[2][N];

vector<int>VA[2];



V chk(ll &x){x-=Mod,x+=x>>31&Mod;}

int main(){

	int T=read();

	FOR(tt,1,T){

		n=read();		

		FOR(i,1,n)a[i]=read();

		

		ll ans=0;

		ROF(i,n,1){

			int p=(i&1),las=0;

			VA[p].clear();

			for(int t:VA[p^1]){

				ll p1=(a[i]+t-1)/t,p2=a[i]/p1;

				ans=(ans+i*(p1-1)*f[p^1][t])%Mod;

				chk(f[p][p2]+=f[p^1][t]);

				

				f[p^1][t]=0;

				if(p2!=las)VA[p].PB(p2),las=p2;

			}

			

			VA[p].PB(a[i]);

			chk(++f[p][a[i]]);

		}

		

		

		cout<<ans<<'\n';

		

		for(int t:VA[1])f[1][t]=0;

		for(int t:VA[0])f[0][t]=0;

		VA[0].clear(),VA[1].clear();		

	}

	return 0;

}

/*



1

3

5 4 3





4

3

5 4 3

4

3 2 1 4

1

69

8

7264 40515 28226 92776 35285 21709 75124 48163

*/