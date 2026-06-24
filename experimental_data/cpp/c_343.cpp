#include<bits/stdc++.h>

using namespace std;



typedef long long ll;

int n,m;

vector<ll>h,p;



bool ok(ll leng){



	int pidx = 0;

	for(int i=0;i<n;i++){



		ll mond = p[pidx];

		ll finl = 0;

		if(mond < h[i]){

			if(h[i] - mond > leng )

				return 0;

			finl = max(h[i] , h[i] + leng - 2 * (h[i] - mond) );

			finl = max(finl , h[i] +  ( leng - (h[i] - mond) ) / 2);

		}else{

			finl = h[i] + leng;

		}



		while(pidx < m && p[pidx] <= finl ){

			pidx++;

		}



		if(pidx == m){

			return true;

		}

	}



	return false;

}



int main(){

	scanf("%d%d",&n,&m);

	h.resize(n);

	p.resize(m);

	for(int i=0;i<n;i++)

		scanf("%lld",&h[i]);

	for(int i=0;i<m;i++)

		scanf("%lld",&p[i]);



	ll lo = 0, up= 1LL<<40;



	while(lo <= up){

		ll md = (lo+up)>>1;

		if(ok(md)){

			up = md - 1;

		}else{

			lo = md + 1;

		}

	}

	printf("%lld\n",up+1);

}