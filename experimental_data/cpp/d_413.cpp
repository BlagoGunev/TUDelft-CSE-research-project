//                                   <................... be name khoda .....................>
#include<bits/stdc++.h>
using namespace std;
inline int iin()
{
	int x;
	scanf("%d",&x);
	return x;
}
inline void print(int x )
{
	printf("%d ",x);
}
const int N = 3000, Mod = 1e9 + 7, M = 2049;
inline void mul( int &x, int y){ x = 1ll * x * y % Mod; }
inline void sum( int &x, int y){ x = x + y; if( x >= Mod ) x -= Mod; }
inline void di( int &x, int y ){ x = x + Mod - y; x %= Mod;}
int dp[ 2 ][ M ];
int ans = 0, n , k, c = 1;
int in[ N ];
main()
{
	n = iin(), k = (1 << iin());
	dp[ 1 ][ 0 ] = 1;
	for(int i = 0;i < n; i++ ) in[ n-i-1 ] = iin();
	int i = n;
	while( i-- )
	{
		int I = (n-i-1) & 1, J = 1 - I ;
		int a = in[ i ];
		fill( dp[ I ], dp[ I ] + M,0 );
		if( a == 2 || !a )
		{
			for(int j = 0;j <= k; j++ )
			{
				int cur = min( j + 2, k );
				sum(dp[ I ][ cur ],dp[ J ][ j ]);
			}
		}
		if( a == 4 || !a )
		{
			for(int j = 0;j <= k; j++)
			{
				int cur = min( j + 4, k );
				if( j & 2 )
					cur = 4;
				sum(dp[ I ][ cur ],dp[ J ][ j ]);
			}
		}
//		cout << i << endl;
//		for(int j = 0;j <= k; j++ ) cout << dp[ I ][ j ] <<' ';
//		cout << endl;
	}
	print(dp[ 1- n & 1 ][ k ]);
}