/*
 *************************
 Id  : Matrix.code
 Task:
 Date: 2016-02-10

 **************************
 */


#include <bits/stdc++.h>
using namespace std;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


/*------- Constants---- */

#define Long                    long long
#define ull                     unsigned long long
#define mod                     1000000007
#define MEMSET_INF              63
#define MEM_VAL                 1061109567
#define forn(i,n)               for( int i=0 ; i < n ; i++ )
#define mp(i,j)                 make_pair(i,j)
#define lop(i,a,b)              for( int i = (a) ; i < (b) ; i++)
#define pb(a)                   push_back((a))
#define SZ(a)                   (int) a.size()
#define all(x)                  (x).begin(),(x).end()
#define gc                      getchar_unlocked
#define PI                      acos(-1.0)
#define INF                     1<<29
#define EPS                     1e-9
#define Fr                      first
#define Sc                      second
#define Sz                      size()
#define lc                      ((n)<<1)
#define rc                      ((n)<<1|1)
#define db(x)                   cout << #x << " -> " << x << endl;
#define Di(n)                   int n;si(n)
#define Dii(a,b)                int a,b;si(a);si(b)
#define Diii(a,b,c)             int a,b,c;si(a);si(b);si(c)
#define Si(n)                   si(n)
#define Sii(a,b)                si(a);si(b)
#define Siii(a,b,c)             si(a);si(b);si(c)
#define min(a,b)                ((a)>(b) ? (b) : (a) )
#define max(a,b)                ((a)>(b) ? (a):(b))
/*---- short Cuts ------- */
#define ms(ara_name,value) memset(ara_name,value,sizeof(ara_name))
typedef pair<int, int> ii;
typedef vector<int > vi ;
typedef vector<Long> vl;
/*------ template functions ------ */
#ifndef getchar_unlocked
#define getchar_unlocked getchar
#endif
template<class T> inline void si(T &x){register int c = gc();x = 0;int neg = 0;for(;((c<48 | c>57) && c != '-');c = gc());
      if(c=='-') {neg=1;c=gc();}for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}if(neg) x=-x;}
Long bigmod(Long p,Long e,Long M){Long ret = 1;for(; e > 0; e >>= 1){if(e & 1) ret = (ret * p) % M;p = (p * p) % M;} return ret;}
Long gcd(Long a,Long b){if(b==0)return a;return gcd(b,a%b);}
Long modinverse(Long a,Long M){return bigmod(a,M-2,M);}
void io(){freopen("/Users/MyMac/Desktop/in.txt","r",stdin);}

/*************************** END OF TEMPLATE ****************************/

const int N = 4e5+5;
int a[N],p[N];



int main()
{
      //freopen("in.txt","r",stdin);
      int n,q;
      Sii(n,q);
      for(int i = 0; i < n; i++ ) {
            Si(a[i]);
      }
      a[n] = -1;
      for(int i=  n-1;i >= 0;  i --) {
            int j = i+1;
            while(j <= n && a[j] == a[i] ) j = p[j];
            p[i] = j;
      }
      for(int i= 0; i < q;i ++ ) {
            Diii(l,r,x);
            l--,r--;
            int nxt = -1;
            if(a[l] == x) {
                  nxt = p[l];
            }else nxt = l;
            if(nxt <= r) printf("%d\n",nxt+1);
            else printf("-1\n");
      }
      return 0;

}