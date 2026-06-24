#include <bits/stdc++.h>



//#define ll long long

#define ld long double

#define ull unsigned long long

#define pb push_back

#define pob pop_back

#define int long long



#define Shrek_Crash228 ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);



using namespace std;



vector <int> v;   

vector <string> v1;

vector <pair <int , int>> v2;

map <string, int> mp;



const int N = 1e5 + 123;



int n, m, a[N];









/////////////////////////////////////////////////////////////



bool bp( int x )

{

    int l = 1, r = n;

    

    while( l <= r )

    {

        int mid = (l + r) / 2;

        

        if( a[mid] == x ) return true;

        

        if( a[mid] > x ) r = mid - 1;

        

        if( a[mid] < x ) l = mid + 1;

    }

    return false;

}



/////////////////////////////////////////////////////////////









/////////////////////////////////////////////////////////////



pair <int, int> t[4 * N];



void build( int v, int tl, int tr ) 

{

	if( tl == tr ) 

	{

	    t[v] = {a[tl], 1};

	    return;

	}

	int tm = ( tl + tr ) / 2;

	

	build ( v * 2, tl, tm );

	build ( v * 2 + 1, tm + 1, tr );

	

	if( t[v + v].first < t[v + v + 1].first )

	{

	    t[v] = t[v + v];

	}

	if( t[v + v].first > t[v + v + 1].first )

	{

	    t[v] = t[v + v + 1];

	}

	if( t[v + v].first == t[v + v + 1].first )

	{

	    t[v] = {t[v + v].first, t[v + v].second + t[v + v + 1].second};

	}

}



pair<int, int>sum( int v, int tl, int tr, int l, int r ) 

{

    if( l > tr || tl > r ) 

    {

        pair <int, int> zero;

        zero = make_pair(1e9, 0);

        return zero;

    }

    else if( tl >= l && r >= tr ) return t[v];

    

    int tm = (tl + tr) / 2;

    

    pair <int, int> s1 = sum( v + v, tl, tm, l, r );

    pair <int, int> s2 = sum( v + v + 1, tm + 1, tr, l, r );

    

    if( s1.first < s2.first )

    {

        return s1;

    }

    else if(s2.first < s1.first) 

    {

        return s2;

    }

    else

    {

        pair <int, int> res;

        

        res.first = s1.first;

        res.second = s2.second + s1.second;

        

        return res;

    }

}



void update( int v, int tl, int tr, int pos, int new_val ) 

{

	if( tl == tr ) t[v] = {new_val, 1};

	

	else 

	{

		int tm = ( tl + tr ) / 2;

		

		if( pos <= tm ) update ( v * 2, tl, tm, pos, new_val );

		else update ( v * 2 + 1, tm + 1, tr, pos, new_val );

		

		if( t[v + v].first < t[v + v + 1].first )

     	{

	        t[v] = t[v + v];

    	}

    	if( t[v + v].first > t[v + v + 1].first )

    	{

    	    t[v] = t[v + v + 1];

    	}

    	if( t[v + v].first == t[v + v + 1].first )

    	{

    	    t[v] = {t[v + v].first, t[v + v].second + t[v + v + 1].second};

    	}

	}

}



/////////////////////////////////////////////////////////////



signed main() 

{

    Shrek_Crash228

    

    int t;

    

    cin >> t;

    

    for( int i = 1; i <= t; i ++ )

    {

        int n, m, x, y, d;

        

        int sum1n = 0, sum1m = 0, sum2n = 0, sum2m = 0;

        

        cin >> n >> m;

        cin >> x >> y;

        cin >> d;

        

        for( int j = 1; j <= n; j ++ )

        {

            if( abs( j - x ) + abs( 1 - y ) <= d ) sum1n ++;

            

            if( abs( j - x ) + abs( m - y ) <= d ) sum2n ++;

        }

        for( int j = 1; j <= m; j ++ )

        {

            if( abs( n - x ) + abs( j - y ) <= d ) sum1m ++;

            

            if( abs( 1 - x ) + abs( j - y ) <= d ) sum2m ++;

        }

        if( ( sum1n > 0 || sum1m > 0 ) && ( sum2n > 0 || sum2m > 0 ) ) cout << -1 << '\n';

        

        else cout << n + m - 2 << '\n';

    }

    return 0;

}