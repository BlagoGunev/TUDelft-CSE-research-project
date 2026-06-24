#include <queue>
#include <string>
#include <cstdio>
#include <limits>
#include <climits>
#include <cstring>
#include <vector>
#include <stack>
#include <utility>
#include <algorithm>
#include <numeric>
#include <ciso646>
#include <type_traits>
#include <functional>
#include <cassert>
#include <cmath>
#include <cstddef>


using ll = long long ;

static constexpr size_t N = 1 << 19 ;
static constexpr size_t M = 1 << 19 ;


struct grid
{
    int n;
    char c[12][12];
};

grid rotate90(grid g)
{
    grid r;
    r.n = g.n;
    for(int i = 0; i < g.n; ++i)
    {
        for(int j= 0 ;j < g.n; ++j)
        {
            r.c[ j ][ g.n - i -1 ] = g.c[ i ][ j ];
        }
    }
    return r;
}

grid flip_h(grid g)
{
    grid r;
    r.n = g.n;
    for(int i = 0; i < g.n; ++i)
    {
        for(int j= 0; j < g.n; ++j)
        {
            r.c[  g.n - i -1 ][j] = g.c[i][j];
        }
    }
    return r;
}

grid flip_w(grid g)
{
    grid r;
    r.n = g.n;
    for(int i = 0; i < g.n; ++i)
    {
        for(int j= 0 ; j< g.n; ++j)
        {
            r.c[ i ][g.n - j -1] = g.c[i][j];
        }
    }
    return r;
}

bool equal( grid a, grid b)
{
    for(int i = 0; i < a.n; ++i)
    {
        for(int j = 0; j < a.n; ++j)
        {
            if (a.c[i][j] != b.c[i][j] )
                return false;
        }
    }
    return true;
}

int yes(){  puts("Yes"); return 0; };
int no(){ puts("No"); return 0; }

int solve()
{
    
    grid a ,b ;
    int  n;
    scanf("%d\n", &n);
    a.n = b.n = n;
    for(int i = 0; i < n; ++i )
    {
        scanf("%s",  a.c[i]);
    }
    for(int i = 0; i < n; ++i)
    {
        scanf("%s", b.c[i]);
    }
    
    for(int i = 0; i < 4; ++i){
        if (equal(a,b)) return yes();
        b = rotate90(b);
    }
    
    b = flip_h( b );
   for(int i = 0; i < 4; ++i){
        if (equal(a,b)) return yes();
        b = rotate90(b);
    }
    
    b = flip_h(b);
    
    b = flip_w(b);
    for(int i = 0; i < 4; ++i){
        if (equal(a,b)) return yes();
        b = rotate90(b);
    }
    
    b = flip_h(b);
    
    for(int i = 0; i < 4; ++i){
        if (equal(a,b)) return yes();
        b = rotate90(b);
    }
    
    return no();
    
}



int main(int arc, char * argv[])
{

    solve();
}