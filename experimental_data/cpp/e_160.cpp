#include <bits/stdc++.h>
//#define int long long
#define hash hashhash
#define X first
#define Y second
#define endl "\n"
#define Mp make_pair
using namespace std;
inline int in(){int32_t x ; scanf("%d",&x) ; return x ; }
inline long long lin(){long long x ; scanf("%lld",&x) ; return x ;}
char ch[4000010];
inline string get(){ scanf("%s",ch) ; return string(ch) ; }
inline void read(int *a , int n ) { for (int i = 0 ; i < n ; i ++) a[i] = in() ; }
template <class blank> inline void out(blank x) {cout << x << endl ; exit(0) ;}
template <class blank> inline void smin(blank &a , blank b) {a = min(a , b) ;}
template <class blank> inline void smax(blank &a , blank b) {a = max(a , b) ; }
typedef pair<int , int > pii;
typedef long double ld;
typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<pii> vii;
const int maxn  = 1e5  + 10;
const int maxm = 2e6 + 10;
const int maxlg = 21;
const int base = 29;
const int mod = 1e9 + 7;
const int inf = 1e9 + 10;
int start[maxn],finish[maxn],t[maxn],id[maxn],id2[maxn],res[maxn],l[maxn],r[maxn],b[maxn],n,m,cmp[maxn],treeSize;
vii shit;
map<int,int> mp;
int maxR[4*maxn],maxT[4*maxn];
inline void update(int x , int val , int p = 0 , int l = 0 , int r = treeSize - 1)
{
    if (l > x || r < x) return ;
    smax(maxR[p],val);
    smax(maxT[p],shit[x].first);
    
    if (l == r) return ;
    int mid = (l + r) >> 1;
    update(x,val,2*p+1,l,mid);
    update(x,val,2*p+2,mid+1,r);
}
inline void add(int busid)
{
    update(cmp[busid],finish[busid]);
}
inline int get(int val , int tm , int p = 0 , int l = 0 , int r = treeSize - 1)
{
    if (maxR[p] < val || maxT[p] < tm) return -1;
    if (l == r) return l;
    int mid = (l + r) >> 1;
    int a = get(val,tm,2*p+1,l,mid);
    if (a + 1) return a;
    return get(val,tm,2*p+2,mid+1,r);
}
int32_t main()
{
    n = in() , m = in();
    for (int i = 0 ; i < n ; i ++){
        start[i] = in() , finish[i] = in() , t[i] = in();
        shit.push_back({t[i],i});
    }
    sort(shit.begin(),shit.end());
    for (int i = 0 ; i < shit.size() ; i ++) cmp[shit[i].second] = i && shit[i].first == shit[i-1].first ? cmp[shit[i-1].second] : treeSize ++;
    iota(id,id+n,0);
    sort(id,id+n,[](const int &a , const int &b) {return start[a] < start[b] ; });
    for (int i = 0 ; i < m ; i ++)
    {
        l[i] = in() , r[i] = in() , b[i] = in();
    }
    iota(id2,id2+m,0);
    sort(id2,id2+m,[](const int &a , const int &b) {return l[a] < l[b] ; });
    int cur = 0;
    for (int i = 0 ; i < m ; i ++)
    {
        while (cur < n && start[id[cur]] <= l[id2[i]])
            add(id[cur ++ ]);
        res[id2[i]] = get(r[id2[i]],b[id2[i]]);
    }
    for (int i = 0 ; i < m ; i ++){
        printf("%d ",res[i] == -1 ? res[i] : shit[res[i]].second + 1) ;
    }
}