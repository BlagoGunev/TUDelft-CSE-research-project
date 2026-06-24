#include<bits/stdc++.h>
using namespace std;

#define li long int
#define ll long long int
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
#define itr iterator
#define ipl( n) scanf( "%ld", &n)
#define ipll( n) scanf( "%I64d", &n)
#define ips( n) scanf( "%s", n)
#define ipss( n) cin. getline( n, sizeof( n))
#define ipst( n) getline( cin, n)
#define getc() getchar()
//#define getc() getchar_unlocked()
#define ipf( n) scanf( "%f", &n)
#define ipd( n) scanf( "%lf", &n)
#define opl( n) printf( "%ld", n)
#define opll( n) printf( "%I64d", n)
#define opf( n) printf( "%f", n)
#define opd( n) printf( "%lf", n)
#define op( n) printf( n)
#define ol printf( "\n")
#define os printf( " ")
#define wm1 op( " @ ")
#define wm2 op( " $ ")
#define wm3 op( " ^ ")
#define wm4 op( " * ")
#define EPS 1e-11
#define mx 1003
#define mxd 11
#define mod 1000000007

void iplf( li &num)
{
    	num= 0;
    	char c= getc();
    	while( c< '0'|| c> '9')
    	{
        	c= getc();
    	}
    	while( c>= '0'&& c<= '9')
    	{
        	num= 10* num+ c- '0';
        	c= getc();
    	}
    	return;
}

li n, m, k, w;

struct game
{
	char board[ mxd][ mxd];

	void scn()
	{
		char c;
		for( li i= 1; i<= n; i++)
		{
			for( li j= 1; j<= m; j++)
			{
				c= getc();
				while( (c< 'a'|| c> 'z') && (c< 'A'|| c> 'Z')&& c!= '.') c= getc();
				board[ i][ j]= c;
			}
		}

		return;
	}

	li diff( game &ob)
	{
		li ret= 0;
		
		for( li i= 1; i<= n; i++)
		{
			for( li j= 1; j<= m; j++)
			{
				if( this-> board[ i][ j]!= ob. board[ i][ j]) ret++;
			}
		}
		return ret* w;
	}
};

struct game lvl[ mx];

li cost[ mx][ mx];

li reach[ mx], _cost[ mx];

void MST()
{
	_cost[ 0]= 1e9;

	set< pair< li, li> > s;

	for( li i= 1; i<= k; i++)
	{
		_cost[ i]= cost[ i][ 0];

		s. insert( mp( _cost[ i], i));
	}

	vector< bool> visited( k+ 1, false);

	visited[ 0]= true;

	while( !s. empty())
	{
		li v= s. begin()-> snd;

		s. erase( s. begin());

		visited[ v]= true;

		for( li i= 1; i<= k; i++)
		{
			if( visited[ i]) continue;

			if( cost[ v][ i]< _cost[ i])
			{
				s. erase( mp( _cost[ i], i));
				s. insert( mp( cost[ v][ i], i));
				reach[ i]= v;
				_cost[ i]= cost[ v][ i];
			}
		}
	}

	return;
}

void solve()
{
	ipl( n); ipl( m); ipl( k); ipl( w);

	for( li i= 1; i<= k; i++)
	{
		lvl[ i]. scn();
	}

	for( li i= 1; i<= k; i++)
	{
		cost[ i][ 0]= n* m;
		cost[ 0][ i]= n* m;

		for( li j= i+ 1; j<= k; j++)
		{
			cost[ i][ j]= lvl[ i]. diff( lvl[ j]);
			cost[ j][ i]= cost[ i][ j];
		}
	}

	MST();

	li ans= 0;

	for( li i= 1; i<= k; i++)
	{
		ans+= _cost[ i];
	}

	opl( ans); ol;

	stack< li> stk;
	
	stk. push( 0);

	vector< bool> visited( k+ 1, false);

	while( !stk. empty())
	{
		li par= stk. top();
		stk. pop();
		for( li i= 1; i<= k; i++)
		{
			if( visited[ i]) continue;

			if( reach[ i]== par)
			{
				opl( i); os; opl( par); ol;
				stk. push( i);
				visited[ i]= true;
			}
		}
	}

	return;
}

int main()
{
    	solve();
	return 0;
}