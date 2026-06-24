/**************************************************************

    Problem:

    User: byene

    Time:2016-11-04

****************************************************************/

#include<bits/stdc++.h>

#define pb push_back;

#define mp make_pair;

#define se second;

#define fs first;

#define lson l,m,rt<<1;

#define rson m+1,r,rt<<1|1;

#define pair<int,int> pii;

#define ll long long

using namespace std;



const double eps = 1e-9;

const int maxn = 300100;

const int mod = 1e9 + 7;

const int INF = 1e9;



int n, m, st, ed;



int cnt, head[ maxn * 2 ];



void init()

{

    cnt = 0;

    memset( head, -1 , sizeof( head ) );

}



struct Edge

{

    int u, v, nxt, w;

}edge[ maxn * 2 ];



void addEdge( int u, int v,int w )

{

    edge[ cnt ].u = u;

    edge[ cnt ].v = v;

    edge[ cnt ].w = w;

    edge[ cnt ].nxt = head[ u ];

    head[ u ] = cnt ++;

}







int dfs_clock,scc_number;

int pre[ maxn ], lowlink[ maxn ], sccno[ maxn ];

stack< int > s;



void Tarjan( int u, int fa )

{

    lowlink[ u ] = pre[ u ] = ++ dfs_clock;

    s. push( u );

    for( int i = head[ u ]; i != -1; i = edge[ i ].nxt )

    {

        int v = edge[ i ].v;

        if( v == fa ) continue;

        if( !pre[ v ] )

        {

            Tarjan( v, u );

            lowlink[ u ] = min( lowlink[ u ], lowlink[ v ] );

        }

        else if( !sccno[ v ] )  lowlink[ u ] = min( lowlink[ u ], lowlink[ v ] );

    }

    if( lowlink[ u ] == pre[ u ] )

    {

        scc_number ++;

        while(1)

        {

            int s_top = s.top();s.pop();

            sccno[ s_top ] = scc_number;

            if( s_top == u ) break;

        }

    }

}



void Find_scc()

{

    dfs_clock=scc_number=0;

    memset( sccno, 0, sizeof( sccno ) );

    memset( lowlink, 0, sizeof( lowlink ) );

    for( int i = 1; i <= n; i ++ )

    {

        if( !pre[i] ) Tarjan( i, -1 );

    }

}



int A[maxn];



int Dfs( int u, int fa, int goal, int sum )

{

    sum |= A[ u ];

    if( u == goal ) return sum;

    for( int i = head[ u ]; i != -1; i = edge[ i ].nxt )

    {

        int v = edge[ i ].v;

        if( v == fa ) continue;

        if( Dfs( v, u, goal, sum | edge[ i ].w ) ) return 1;

    }

    return 0;

}



void Input()

{

    scanf( "%d%d", &n, &m );

    init();

    for( int i = 1; i <= m; i ++ )

    {

          int u, v, w;

          scanf( "%d%d%d", &u, &v, &w );

          addEdge( u, v, w );

          addEdge( v, u, w );

    }

    scanf( "%d%d", &st, &ed );

}



int main()

{

    Input();

    Find_scc();

    int etot = cnt;

    init();

    //for( int i = 1; i <= n; i++ ) cout << sccno[ i ] << endl;

    for( int i = 0; i < etot ; i ++ )

    {

        int u = sccno[ edge[ i ].u ], v = sccno[ edge[ i ].v ];

        if( u == v ) A[u] |= edge[ i ].w;

        else addEdge( u, v, edge[ i ].w );

    }

    if( Dfs( sccno[ st ], -1, sccno[ ed ], 0 ) ) printf( "YES\n" );

    else                                         printf( "NO\n" );

    return 0;

}