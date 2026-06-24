#include <algorithm>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <map>
#define  fi        first
#define  se	   	   second
#define  pb	  	   push_back
#define  maxn	   1000003
#define  mod	   1000000007
using	 namespace std;
typedef  long long LL;
typedef  pair<int,int> pi;

int n;
int ans[2];
int cnt[26];
int cnt2[26];
LL fact[maxn];
string s1,s2,t;

LL calcPow( LL x , LL y ) {
	if( !y )
		return 1;
	LL tmp = calcPow( x , y / 2 );
	tmp = ( tmp * tmp ) % mod;
	if( y & 1 )
		tmp = ( tmp * x ) % mod;
	return tmp;
}

void f( int ind , int kd , LL q ) {
	if( ind == n ) {
		ans[kd] = ( ans[kd] + 1 ) % mod;
		return;
	}
	int val = t[ind] - 'a';
	for( int i = 0 ; i < val ; i++ )
		if( cnt[i] ) {
			LL add = ( q * cnt[i] ) % mod;
			add = ( add * fact[n-ind-1] ) % mod;
			ans[kd] = ( ans[kd] + add ) % mod;
		}
	if( cnt[val] ) {
		LL c = cnt[val];
		cnt[val]--;
		f( ind + 1 , kd , ( q * c ) % mod );
		cnt[val]++;
	}
}

int main() {
	
	cin >> s1 >> s2;
	n = s1.length();
	
	for( int i = 0 ; i < n ; i++ )
		cnt[s1[i]-'a']++;
	for( int i = 0 ; i < n ; i++ )
		cnt2[s2[i]-'a']++;
	
	bool same = true;
	for( int i = 0 ; i < 26 ; i++ )
		if( cnt[i] != cnt2[i] )
			same = false;
	
	fact[0] = 1;
	for( int i = 1 ; i <= n ; i++ )
		fact[i] = ( fact[i-1] * i ) % mod;
	
	LL q = 1;
	for( int i = 0 ; i < 26 ; i++ )
		q = ( q * fact[ cnt[i] ] ) % mod;
	q = calcPow( q , mod - 2 );
	
	t = s1;
	f( 0 , 0 , q );
	
	t = s2;
	f( 0 , 1 , q );
	
	int res = ( ans[1] - ans[0] + mod ) % mod;
	res = ( res - same + mod ) % mod;
	
	printf( "%d\n" , res );
	
}