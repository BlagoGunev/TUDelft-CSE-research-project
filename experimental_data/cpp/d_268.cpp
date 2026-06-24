#include <bits/stdc++.h>

using namespace std;

int n,h;

int mod = 1000000009;

int memo[2][32][32][32][2];



inline int get(int pos,int h1,int h2,int h3,bool ok){

	if(pos == n+1)

		return (h1 <= h || h2 <= h || h3 <= h || ok);

	return memo[pos&1][h1][h2][h3][ok];

}



int dp(){

	for(int pos=n;pos>0;pos--)

	for(int h1=h+1;h1>0;h1--)

	for(int h2=h+1;h2>0;h2--)

	for(int h3=h+1;h3>0;h3--)

	for(int ok=0;ok<2;ok++){

		if(h1 >= h+1 && h2 >= h+1 && h3 >= h+1 && ok == 0) continue;

		int &ret = memo[pos&1][h1][h2][h3][ok];

		ret = 0;

		ret = (ret+ get(pos+1,min(h1+1,h+1),min(h2+1,h+1),min(h3+1,h+1), ok) ) % mod;

		ret = (ret+ get(pos+1,(ok?2:(h+1)),min(h2+1,h+1),min(h3+1,h+1), h1<=h) )%mod;

		ret = (ret+ get(pos+1,min(h1+1,h+1),(ok?2:(h+1)),min(h3+1,h+1), h2<=h) )%mod;

		ret = (ret+ get(pos+1,min(h1+1,h+1),min(h2+1,h+1),(ok?2:(h+1)), h3<=h) )%mod;

	}

	return get(1,1,1,1,1);

}



int main(){

	scanf("%d %d" , &n,&h);

	printf("%d", dp());

}