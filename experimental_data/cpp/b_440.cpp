#include <vector>
#include <list>
#include <map>
#include <set>
#include "queue"
#include <deque>
#include <stack>
#include <numeric>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <complex>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <climits>
#include <cassert>
#include <iostream>
using namespace std;
#define MOD1 1000000007
inline void inp( long long int  &n ){n=0;int ch=getchar();int sign=1;while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar();}while( ch >= '0' && ch <= '9' )n = (n<<3)+(n<<1) + ch-'0', ch=getchar();n=n*sign;}
#define pi acos(-1)
#define pii pair<int,int>
#define vii vector<pii>
#define ll  long long int
#define loop(i,n) for(ll i=0;i<n;i++)
#define ll  long long int
#define LL long long int
#define loop2(i,n) for(ll i=1;i<=n;i++)
#define FOR(i,x,y) for(ll i = (x) ; i <= (y) ; ++i)
#define MIN(a,b) (a) < (b) ? (a) : (b)
#define MAX(a,b) (a) > (b) ? (a) : (b)
#define ABS(a) (a) > 0 ? (a) : -(a)
#define rep1(i,a,n) for(i=a;i<=(n);i++)
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define OUT_RT cerr << (float(clock()) / CLOCKS_PER_SEC) << endl
#define EPS 1e-9
#define ld long double
#define REP(i,n) for(int i=0;i<n;i++)
#define si(x)           do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
//using namespace std;
// JAI SHREE KRISHNA
//Winning is my right
//Triumph against the odds



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    ll sum = 0 ;
    cin>>n;
    ll arr[n];
    loop(i, n){
        cin>>arr[i];
        sum+=arr[i];
    }
    ll ans1 = 0 ;
    sum/=n;
    ll now = 0 ;
    
    loop(i, n){
        now+=arr[i]-sum;
        if(now>0){
            ans1+=now;
        }
        else{
            ans1-=now;
        }
        
    }

    cout<<ans1;
    return 0;
}