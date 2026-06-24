#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<queue>
#include<cstring>
#include<algorithm>
#include<set>
#include<string>
#include<map>
#include<cmath>
#include<vector>
#include<time.h>
#define fori(l,r) for( int i = l ; i <= r ; i++ )
#define forj(l,r) for( int j = l ; j <= r ; j++ )
#define fork(l,r) for( int k = l ; k <= r ; k++ )
#define mem(a,val) memset(a,val,sizeof a)
#define lef rt<<1
#define rig rt<<1|1
#define mid (l+r)>>1
#define inf 0x3f3f3f3f
#define llinf 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
const int maxn = 1e3+4;
char s[maxn][maxn];
int row,col;
char ss[5][5]={"0000","0###","0#.#","0###"};

bool check( int r,int c )
{
    int rr = r-2;
    rr = max(1,rr);
    int cc = c-2;
    cc = max(1,cc);

    fori(rr,r)
        forj(cc,c)
        {
            if( i == r-1 && j == c-1 )
                continue;
            bool flag = true;
            fork(1,3)
                for( int z = 1 ; z <= 3 ; z++ )
                {
                    if( i+k-1 > row || j+z-1 > col )
                    {

                        flag = false;
                        break;
                    }
                    if( (k==2&&z==2) == false&&s[i+k-1][j+z-1] != ss[k][z] )
                    {
                        flag = false;
                        break;
                    }
                }
            if( flag )
            {
                fork(1,3)
                    for( int z = 1 ; z <= 3 ; z++ )
                    {
                        if( (k==2&&z==2 )==false )
                            s[i+k-1][j+z-1] = ss[k][z];
                    }
                return true;
            }
        }
    return false;
}
int main()
{

    scanf("%d %d",&row,&col);
    fori(1,row)
        scanf("%s",s[i]+1);
    bool ans = true;
    fori(1,row)
        forj(1,col)
        {
            if( s[i][j] == '#' )
            {
                if( check(i,j) == false )
                {
                    ans = false;
                    goto there;
                }
            }
        }
    there:
        if( ans )
            puts("YES");
        else puts("NO");
    return 0;
}

/*
//freopen("E:\\problem list\\codeblocks\\A\\input.txt","r",stdin);
//freopen("E:\\problem list\\codeblocks\\A\\standardoutput.txt","w",stdout);

1 4
10000 3 2
2 8000
3 5000
1000 2 1
4 200
3000 1 1
4 200
50 2 0


*/