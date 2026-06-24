#include<stdio.h>

#include<stdlib.h>

#include<math.h>

#include<string.h>

#include<string>

#include<ctype.h>

#include<queue>

#include<map>

#include<set>

#include<stack>

#include<vector>

#include<algorithm>

#include<iostream>

#include<functional>

const int INF=0x3f3f3f3f;

const double PI=acos(-1.0);

const double EPS=1e-8;

using namespace std;

typedef long long ll;

typedef unsigned long long ull;



int const N=200005;

int sum[N];



int read(){

	int d,f=1;

	char c;

	while(!isdigit(c=getchar())) if(c=='-') f=-1;

	d=c-'0';

	while(isdigit(c=getchar())) d=d*10+c-'0';

	return d*f;

}



int main(){

	int n;

	while(cin>>n){

		int Max=0;

		for(int i=0;i<n;++i){

			int num;

			num=read();

			Max=max(Max,num);

			sum[num]++;

		}

		for(int i=1;i<=Max;++i) sum[i]+=sum[i-1];

		ll ans=0;

		for(int i=1;i<=Max;++i){

			if(sum[i]-sum[i-1]){

				ll t=0;

				int bnd=Max/i;

				for(int j=1;j<=bnd;++j){

					int r=min(Max,i*(j+1)-1);

					t+=(ll)i*j*(sum[r]-sum[i*j-1]);

				}

				ans=max(ans,t);

			}

		}

		cout<<ans<<endl;

	}	

	return 0;

}