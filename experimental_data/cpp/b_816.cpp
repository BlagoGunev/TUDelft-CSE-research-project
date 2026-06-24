#include <cassert>
#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <streambuf>
#include <string>
#include <utility>
#include <valarray>
#include <vector>
#define INL __attribute((always_inline)) inline
#define getstr(s) (~scanf("%[^\n]%*c",(s)))
#define rco(i,l,r) for(i=(l);i<(r);++i)
#define rcc(i,l,r) for(i=(l);i<=(r);++i)
#define roo(i,l,r) for(i=(l);++i<(r);)
#define roc(i,l,r) for(i=(l);++i<=(r);)
#define lco(i,l,r) for(i=(r);(l)<=--i;)
#define lcc(i,l,r) for(i=(r);(l)<=i;--i)
#define loo(i,l,r) for(i=(r);(l)<--i;)
#define loc(i,l,r) for(i=(r);(l)<i;--i)
#define lcz(i,r) for(i=(r);~i;--i)
const char newl='\n';
typedef long double ld;
typedef long long ll;
typedef unsigned int dw;
typedef unsigned long long qw;
using namespace std;
namespace AERIX{

enum cin_t{ceof=0,cin};
template< class T >INL cin_t operator>>(cin_t c, T &x){
    x=0;
    if(!c)return c;
    char ch; bool neg=0;
    while((unsigned char)(ch=getchar())<'-'){}
    if(!~ch)return ceof;
    if(ch=='-'){neg=1;ch=getchar();}
    x=ch-'0';
    while((ch=getchar())>='0')
        x=x*10+ch-'0';
    if(neg)x=-x;
    return c;
}
INL cin_t operator>>(cin_t c, ld &x){
    if(!c)return c;
    double x0;
    if(~scanf("%lf",&x0)){
        x=ld(x0); return c;
    }
    return ceof;
}
void endl(){};
struct cout_t{
    template< class T >void putnum(T x){
        if(x>9)putnum(x/10);
        putchar(x%10+'0');
    }
    template< class T >INL cout_t &operator<<(T x){
        if(x<0){putchar('-');putnum(-x);}
        else putnum(x);
        return *this;
    }
    INL cout_t &operator<<(char x){
        putchar(x); return *this;
    }
    INL cout_t &operator<<(void endl()){
        putchar(newl); fflush(stdout); return *this;
    }
}cout;

/*****************************************************************************/
const int N=200000;
const int NA=N+20;
ll a[NA];
void main(){
    int n, nq, i, x, y;
    ll limit;
    rcc(i,0,N)a[i]=0;
    cin>>n>>limit>>nq;
    while(n--){
        cin>>x>>y;
        --a[y+1];
        ++a[x];
    }
    rcc(i,1,N)a[i]+=a[i-1];
    rcc(i,1,N){
        if(a[i]<limit)a[i]=0;
        else a[i]=1;
    }
    rcc(i,1,N)a[i]+=a[i-1];
    while(nq--){
        cin>>x>>y;
        cout<< (a[y]-a[x-1]) <<newl;
    }
}
/*****************************************************************************/

}
int main(){
#ifdef USEFILE
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif //USEFILE
    AERIX::main();
    return 0;
}