#include<iostream>

#include<algorithm>

#include<cstdio>

using namespace std;

int n, k;

int a[20000];

int c[1000100];

int b[1000100];

int main(){

	scanf("%d%d", &n, &k);

	for(int i=0; i<n; i++)scanf("%d", a+i);

	sort(a, a+n);

	for(int i=0; i<n; i++)

	for(int j=i+1; j<n; j++)

		b[a[j]-a[i]]++;

	for(int mod=1; mod<=a[n-1]+1; mod++){

		int cnt=0;

		for(int i=mod; i<=1000000; i+=mod){

			cnt+=b[i];

			if(cnt>(k+1)*k/2)break;

		}

		if(cnt<=(k*(k+1)/2)){

			int tot=0;

			for(int i=0; i<n; i++){

				int t=a[i]%mod;

				if(c[t]==mod)tot++;

				c[t]=mod;

				if(tot>k)break;

			}

			if(tot<=k){

				printf("%d\n", mod);

				break;

			}

		}

	}

	return 0;

}