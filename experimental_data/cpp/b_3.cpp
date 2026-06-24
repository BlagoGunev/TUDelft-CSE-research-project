#include <stdio.h>
#include <vector>
#include <algorithm>

struct CPlav
{
    int id;
    int p;

    CPlav( int id_ = 0, int p_ = 0 ) : id( id_ ), p( p_ ) {}

    bool operator < ( CPlav const & t ) const
    {
        return p > t.p;
    }
};

typedef std::vector< CPlav > CPlavs;
typedef std::vector< int > CIntVec;

CPlavs p1, p2;
CIntVec sol;
int main()
{
    int N, V;
    scanf( "%d %d", &N, &V );

    for( int i = 0; i != N; ++ i )
    {
        int t, p;
        scanf( "%d %d", &t, &p );
        if( t == 1 ) p1.push_back( CPlav( i+1, p ) ); else p2.push_back( CPlav( i+1, p ) );
    }

    std::sort( p1.begin(), p1.end() );
    std::sort( p2.begin(), p2.end() );


    int i1 = 0;
    int i2 = 0;
    int max = 0;

    if( V%2 == 1 )
    {
        if( i1 < p1.size() )
        {
            max += p1[i1].p;
            sol.push_back( p1[i1].id );
            V--; i1 ++;
        }
        else
        {
            V  --;
        }
    }

    while( V > 0 )
    {
        int s1 = 0;
        if( i1 < p1.size() ) s1 += p1[i1].p;
        if( i1 + 1 < p1.size() ) s1 += p1[i1+1].p;
        
        int s2 = 0;
        if( i2 < p2.size() ) s2 += p2[i2].p;

        if( s1 == 0 && s2 == 0 ) break;

        if( s1 > s2 )
        {
            max += s1;
            if( i1 < p1.size() ) { sol.push_back( p1[i1++].id ); }
            if( i1 < p1.size() ) { sol.push_back( p1[i1++].id ); }
        }
        else
        {
            max += s2;
            if( i2 < p2.size() ) { sol.push_back( p2[i2++].id ); }
        }
        V -= 2;
    }

    printf( "%d\n", max );
    for( int i = 0; i != sol.size(); ++ i )
    {
        printf( "%d\n", sol[i] );
    }

    return 0;
}