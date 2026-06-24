/*
*	ID : pallab81
* 	PROG : A
* 	LANG : C++
* 	2013-05-05-22.08.47 Sunday
*
* 	"I have not failed, I have just found 10000 ways that won't work.
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <numeric>
#include <stack>
#include <functional>
#include <bitset>
#include <iomanip>

#include <ctime>
#include <cassert>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <climits>
#include <cstring>
#include <cstdlib>

using namespace std;


#define foR(i,frm,upto) for( int i=(frm),_i=(upto);(i) < (_i) ; ++i )
#define foD(i,frm,upto) for( int i=(frm),_i=(upto);(i) >= (_i) ; --i )
#define foit(i, x) for (typeof((x).begin()) i = (x).begin(); i != (x).end(); i++)
#define Int long long
#define pb push_back
#define SZ(X) (int)(X).size()
#define LN(X) (int)(X).length()
#define mk make_pair
#define dbg(...)       printf(__VA_ARGS__)
#define SET( ARRAY , VALUE ) memset( ARRAY , VALUE , sizeof(ARRAY) )
#define line puts("")

inline void wait ( double seconds ) {
    double endtime = clock() + ( seconds * CLOCKS_PER_SEC );
    while ( clock() < endtime ) {
        ;
    }
}
template<class T>
    inline T fastIn() {
    register char c=0;
    register T a=0;
    bool neg=false;
    while ( c<33 ) c=getchar();
    while ( c>33 ) {
        if ( c=='-' ) {
            neg=true;
        } else {
            a= ( a*10 ) + ( c-'0' );
        }
        c=getchar();
    }
    return neg?-a:a;
}
int number_count,query_count;
int neg_count,pos_count;
inline void read(){
    number_count=fastIn<int>(),query_count=fastIn<int>();
    for(int i=1;i<=number_count;++i){
        int const tmp=fastIn<int>();
        ( tmp==1 ? ++pos_count : ++neg_count );
    }
}
inline void proc(){
    foR(i,0,query_count){
        int const f=fastIn<int>(),s=fastIn<int>();
        int const tmp = (s-f)+1;
        puts( tmp&1 ? "0": (tmp <= (pos_count<<1) && tmp<=(neg_count<<1) ? "1" : "0" ) );
    }

}
int main() {
        int kase = 1;
#if defined( xerxes_pc )
        if (!freopen("in1.txt", "r", stdin))
                puts("error opening file in "), assert(0);
        kase = 1;
#endif
        foR(i,0,kase){
                read();
                proc();
        }
        return 0;
}