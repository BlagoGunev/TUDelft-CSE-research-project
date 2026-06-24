#include <bits/stdc++.h>

#define fi first
#define se second
#define forn(i,n) for(int i=0; i< (int)n; ++i)
#define for1(i,n) for(int i=1; i<= (int)n; ++i)
#define fore(i,l,r) for(int i=(int)l; i<= (int)r; ++i)
#define ford(i,n) for(int i=(int)(n) - 1; i>= 0; --i)
#define fored(i,l,r) for(int i=(int)r; i>= (int)l; --i)
#define pb push_back
#define el '\n'
#define d(x) cout<< #x<< " " << x<<el
#define ri(n) scanf("%d",&n)
#define sz(v) ((int)v.size())
#define all(v) v.begin(),v.end()
#define allr(v) v.rbegin(),v.rend()

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int,int> ii;
typedef pair<char,int> pci;
typedef tuple<int, int, int> tiii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ii> vii;

const int inf = 1e9+9;
const int nax = 2e5+200;
const ld pi = acos(-1);
const ld eps= 1e-9;
const int mod=998244353;
 
int dr[] = {1,-1,0, 0,1,-1,-1, 1};
int dc[] = {0, 0,1,-1,1, 1,-1,-1};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  cout << setprecision(20)<< fixed;
  ll t,n,x,a,b,m;
  cin >> t;
  forn(w,t){
    cin >> a >> b;
    cin >> n >> m;
    if(b*(m+1)<=a*m){
      cout << b*n << el;
    }else{
      ll ans=0;
      ans+=a*m*(n/(m+1));
      n=n%(m+1);
      if(a<b){
        ans+=n*a;
      }else{
        ans+=n*b;
      }
      cout << ans << el;
    }
  }
}