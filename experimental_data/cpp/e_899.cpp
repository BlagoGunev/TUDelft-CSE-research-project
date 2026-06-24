# include <iostream>
# include <sstream>
# include <cstdio>
# include <cstdlib>
# include <algorithm>
# include <string>
# include <cstring>
# include <cmath>
# include <stack>
# include <queue>
# include <vector>
# include <list>
# include <map>
# include <set>
# include <deque>
# include <iterator>
# include <functional>
# include <bitset>
# include <climits>
# include <ctime>
using namespace std;
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define odd(x) ((x)&1)
#define sqr(x) ((x)*(x))
#define mp make_pair
#define pb push_back
#define fir first
#define sec second
#define all(x) (x).begin(),(x).end()
#define mem(a,x) memset(a,x,sizeof(a))
#define rep(i,a,b) for (int i=(a); i<=(b); ++i)
#define per(i,a,b) for (int i=(a); i>=(b); --i)
#define rep_it(it,x) for (__typeof((x).begin()) it=(x).begin(); it!=(x).end(); it++)
#define ____ puts("\n_______________\n\n")
#define debug(x) ____; cout<< #x << " => " << (x) << endl
#define debug_pair(x) cout<<"\n{ "<<(x).fir<<" , "<<(x).sec<<" }\n"
#define debug_arr(x,n) ____; cout<<#x<<":\n"; rep(i,0,n) cout<<#x<<"["<<(i)<<"] => "<<x[i]<<endl
#define debug_arr2(x,n,m) ____; cout<<#x<<":\n"; rep(i,0,n) rep(j,0,m) cout<<#x<<"["<<(i)<<"]["<<(j)<<"]= "<<x[i][j]<<((j==m)?"\n\n":"    ")
#define debug_set(x) ____; cout<<#x<<": \n"; rep_it(it,x) cout<<(*it)<<" "; cout<<endl
#define debug_map(x) ____; cout<<#x<<": \n"; rep_it(it,x) debug_pair(*it)
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;
const int oo = /*2 * 1000 * 1000 * 1000*/0x3f3f3f3f;
const ll ooo=9223372036854775807ll;
const int _cnt = 1000 * 1000 + 7;
const int _p = 1000 * 1000 * 1000 + 7;
const int N=1000105;
const double PI=acos(-1.0);
const double eps=1e-6;
int o(int x) { return x%_p; }
int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }
int lcm(int a, int b) { return a / gcd(a, b)*b; }

void file_put() {
    freopen("filename.in", "r", stdin);
    freopen("filename.out", "w", stdout);
}

int n,a[N],b[N],cnt[N],L[N],R[N],tot=0;

void D(int x) { R[L[x]]=R[x],L[R[x]]=L[x]; }

struct ttype{
    int x,len;
    friend bool operator < (const ttype &p,const ttype &q) {
        return p.len<q.len || p.len==q.len && p.x>q.x;
    }
};

priority_queue <ttype> Q;
ttype t;

int pp[N],ans=0;

int main() {
    //file_put();

    scanf("%d",&n);
    rep(i,1,n) scanf("%d",&a[i]);
    rep(i,1,n) if (a[i]!=a[i-1]) b[++tot]=a[i],cnt[tot]=1; else cnt[tot]++;
    rep(i,0,tot) R[i]=i+1;
    rep(i,1,tot+1) L[i]=i-1;
    R[tot+1]=tot+1,L[0]=0;
    rep(i,1,tot) pp[i]=cnt[i];
    rep(i,1,tot) Q.push(ttype{i,cnt[i]});
    //while (!Q.empty()) { t=Q.top(); printf("%d %d\n",t.x,t.len); Q.pop(); }
    //debug_arr(pp,tot);
    //debug_arr(cnt,tot);
    while (!Q.empty()) {
        t=Q.top();
        Q.pop();
        if (pp[t.x]!=t.len) continue;
        ans++;
        int p=L[t.x],q=R[t.x];
        pp[t.x]=-1;
        D(t.x);
        if (p!=0 && q!=tot+1 && b[p]==b[q]) {
            D(q);
            pp[p]+=pp[q];
            pp[q]=-1;
            Q.push(ttype{p,pp[p]});
        }
    }
    printf("%d\n",ans);

    return 0;
}