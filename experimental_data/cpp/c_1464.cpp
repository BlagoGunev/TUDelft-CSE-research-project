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



const int N=104580;

const ll mod=1000000007;

ll n,k;

char s[N];



int main(){

	n=read();

	k=read();

	scanf("%s",s+1);

	k-=1<<(s[n]-'a');

	k+=1<<(s[n-1]-'a');

	n-=2;

	int u[26]={0};

	for(int i=1;i<=n;i++)u[s[i]-'a']++;

	for(int i=25;i>=0;i--){

		while(u[i]--){

			if(k<0)k+=1<<i;

			else k-=1<<i;

		}

	}

	puts(k?"No":"Yes");

	return 0;

}