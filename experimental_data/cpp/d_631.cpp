#include <cstdio>

#include <iostream>

using namespace std;



const int N = 200010;



int n, m;

int atot, btot;

char ca[N], cb[N];

long long na[N], nb[N];

bool match[N];

int fail[N];



void init_kmp( int m, char *ch, long long *cnt ) {

	fail[0] = fail[1] = 0;

	for( int i=1,p; i<m; i++ ) {

		p = fail[i];

		while( p && !(ch[p+1]==ch[i+1]&&cnt[p+1]==cnt[i+1]) )

			p = fail[p];

		if( ch[p+1]==ch[i+1] && cnt[p+1]==cnt[i+1] )

			fail[i+1] = p+1;

		else

			fail[i+1] = 0;

	}

}

void kmp( int n, int m, char *pch, long long *pcnt, char *tch, long long *tcnt, bool *match ) {

	int cur = 0;

	for( int i=1; i<=n; i++ ) {

		while( cur && !(pch[cur+1]==tch[i]&&pcnt[cur+1]==tcnt[i]) )

			cur = fail[cur];

		if( pch[cur+1]==tch[i]&&pcnt[cur+1]==tcnt[i] )

			cur++;

		if( cur==m ) {

			match[i] = true;

			cur = fail[cur];

		}

	}

}

int main() {

	scanf( "%d%d", &n, &m );

	for( int i=1; i<=n; i++ ) {

		int v;

		char c;

		scanf( "%d-%c", &v, &c );

		if( c==ca[atot] ) {

			na[atot] += v;

		} else {

			atot++;

			ca[atot] = c;

			na[atot] = v;

		}

	}

	for( int i=1; i<=m; i++ ) {

		int v;

		char c;

		scanf( "%d-%c", &v, &c );

		if( c==cb[btot] ) {

			nb[btot] += v;

		} else {

			btot++;

			cb[btot] = c;

			nb[btot] = v;

		}

	}

	long long ans = 0;

	if( btot==1 ) {

		for( int i=1; i<=atot; i++ ) {

			if( ca[i]==cb[1] && na[i]>=nb[1] )

				ans += na[i] - nb[1] + 1;

		}

	} else if( btot==2 ) {

		for( int i=2; i<=atot; i++ ) {

			if( ca[i-1]==cb[1] && ca[i]==cb[2] && na[i-1]>=nb[1] && na[i]>=nb[2] )

				ans++;

		}

	} else {

		if( atot<=2 ) 

			ans = 0;

		else {

			init_kmp( btot-2, cb+1, nb+1 );

			kmp( atot-2, btot-2, cb+1, nb+1, ca+1, na+1, match+1 );

			for( int i=btot; i<=atot; i++ ) {

				if( match[i-1] && ca[i-btot+1]==cb[1] && ca[i]==cb[btot] 

						&& na[i-btot+1]>=nb[1] && na[i]>=nb[btot] )

					ans++;

			}

		}

	}

	cout<<ans<<endl;

}