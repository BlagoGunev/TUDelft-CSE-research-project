#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

#define F first
#define S second

int a[101000];
int dp[101000];
int son[101000];
int bro[101000];
int start[101000];
pair< int, int > edge[201000];

void makeTree( int v ){
	for ( int i = start[v]; i < start[ v + 1 ]; i ++ )
		if ( son[ edge[i].S ] == -1 ){
			bro[edge[i].S] = son[v];
			son[v] = edge[i].S;
			makeTree( edge[i].S );
		}
}

long long dfs( int v ){
//	cout << "dfs: " << v << endl;
	int u = son[v];
	if ( a[v] == 0 )
		return dp[v] = 0;
	
	long long ret = 0;
	long long total = 0;
	vector< long long > arr;
	while( u != -1 ){
		a[u] --;
		arr.push_back( dfs(u) );
		total += dp[u];
		u = bro[u];
	}
	sort ( arr.begin(), arr.end() );
	for ( int i = arr.size() - 1; i >= 0; i -- ){
		ret = ret + arr[i] + 2;
		a[v] --;
		if ( a[v] == 0 )
			break;
	}
	if ( a[v] < total ){
		ret = ret + a[v] * 2;
		dp[v] = 0;
	}
	else{
		ret = ret + total * 2;
		dp[v] = a[v] - total;
	}
//	cout << "v: " << v << " " << dp[v] << " " << ret << endl;
	return ret;
}

main(){
	int i, j, n;
	int u, v;
	int root;
	
	scanf ( "%d", &n );
	for ( i = 0; i < n; i ++ )
		scanf ( "%d", a + i + 1 );
	for ( i = 1; i < n; i ++ ){
		scanf ( "%d %d", &u, &v );
		edge[i*2+0] = make_pair( u, v );
		edge[i*2+1] = make_pair( v, u );
	}
	memset ( son, -1, sizeof ( son ) );
	memset ( bro, -1, sizeof ( bro ) );
	sort ( edge + 2, edge + n + n );
	j = 1;
	while( j <= edge[2].F )
		start[j++] = 2;
	for ( i = 3; i < n + n; i ++ )
		if ( edge[i].F != edge[i-1].F )
			while( j <= edge[i].F )
				start[j++] = i;
	while( j <= n + 1 )
		start[j++] = i;
//	for ( i = 0; i <= n + 1; i ++ )	cout << start[i] << " ";	cout << endl;
	scanf ( "%d", &root );
	makeTree( root );
	cout << dfs( root ) << endl;
	
//	cin >> i;
	
	return 0;
}