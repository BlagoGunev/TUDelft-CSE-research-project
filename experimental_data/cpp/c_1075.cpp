// Stanley --------------------- header begin
#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <cmath>
#include <queue>
using namespace std;

typedef double D;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;

#define mod9 1000000009LL
#define mod7 1000000007LL
#define INF  1023456789LL
#define eps 1e-9
#define SZ(x) (int)(x).size()

int getInt();
int getNegInt();
int N, M;
int vert[100005];
typedef pair<int,int> pii;
// ---------------------------- header ends

int main(int argc, char** argv ){
	vector< int > hori;
	scanf("%d%d",&M,&N);
	for ( int i = 1 ; i <= M ; i++ )
		vert[i] = getInt();
	for ( int i = 1 ; i <= N ; i++ ){
		int a, b, c;
		a = getInt();
		b = getInt();
		c = getInt();
		if ( a == 1 )
			hori.push_back(b);
	}
	sort( hori.begin(), hori.end() );
	sort( vert+1, vert+M+1 );
	int ans = N + M, now = N, ptr = 0;
	for ( int i = 1 ; i <= M ; i++ ){
		
		while ( ptr < hori.size() && hori[ptr] < vert[i] )
			ptr++;
		int rem = hori.size() - ptr + i - 1;
		if ( rem < ans )
			ans = rem;
	}
	while ( ptr < hori.size() && hori[ptr] < (int)1e9 )
		ptr++;
	int rem = hori.size() - ptr + M;
	if ( rem < ans )
		ans = rem;
	cout << ans << endl;


	



	return 0;
}

// tail begin

int getInt(){
	int ret = 0;
	char c = getchar();
	while ( c < '0' || c > '9' ) c = getchar();
	while ( c >= '0' && c <= '9' )
		ret *= 10, ret += c - '0', c = getchar();
	return ret;
}
int getNegInt(){
	int ret = 0, sign = 1;
	char c = getchar();
	while ( (c < '0' && c != '-' ) || c > '9' ) c = getchar();
	if ( c == '-' ) sign = -1, c = getchar();
	while ( c >= '0' && c <= '9' )
		ret *= 10, ret += c - '0', c = getchar();
	return ret * sign;
}

// tail end