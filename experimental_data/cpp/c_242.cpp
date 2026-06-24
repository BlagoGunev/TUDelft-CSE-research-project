#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <iterator>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdio>

using namespace std;

const int INF=0x3f3f3f3f;
const double D_INF=1e100;
const double eps= 1e-8;
const double C=0.577215664901532860606;
const double Pi=3.141592653589793238;
const double e=2.71828182845904523536;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int,int> pii;
typedef pair<pii,pii> pppii;

#define MP(x,y) make_pair(x,y)
#define CLR(x,k) memset(x,k,sizeof(x))
#define CPY(s,t) memcpy(s,t,sizeof(s))
#define MAX3(x,y,z) max(max(x,y),z)
#define MAX4(a,b,c,d) max(max(a,b),max(c,d))
#define SZI(a) int((a).size())
#define PB push_back
#define ALL(c) (c).begin(),(c).end()
#define TR(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define PRSNT(c,x) ((c).find(x) != (c).end())
#define CPRSNT(c,x) (find(all(c),x) != (c).end())

#define FOR(i,a,b) for (int i(a); i<=(b); i++)
#define FORR(i,a,b) for(int i(b); i>=(a); i--)
#define SORT(c)  sort((c).begin(), (c).end())
#define SORTR(c)  sort((c).begin(), (c).end(),greater<int>())

inline int lowbit(int x){return x&-x;}
inline int highbit(int x){while(x!=lowbit(x))x-=lowbit(x);return x;}
template<typename X> inline bool min_update(X&p,X q){if(p<=q)return 0;p=q;return 1;}
template<typename X> inline bool max_update(X&p,X q){if(p>=q)return 0;p=q;return 1;}
int toInt(string s){ istringstream sin(s); int t; sin>>t; return t; }
template<class T> string toString(T x){ ostringstream sout; sout<<x; return sout.str(); }

typedef pair<pii,int> piii;
int MAIN()
{
  int x0,y0,x1,y1;
  cin>>x0>>y0>>x1>>y1;
  int n;
  cin>>n;
  map<pii,int> edge;
  for(int i=0;i<n;i++)  {
    int r,a,b;
    cin>>r>>a>>b;
    for(int j=a;j<=b;j++)
      edge[MP(r,j)] = 1;
  }
  
//  map<pii,int> his;
  queue<piii> stq;
  stq.push(MP(MP(x0,y0),0));
  edge[MP(x0,y0)] = 2;
  while(!stq.empty()) {
    piii cur = stq.front(); stq.pop();
    int x=cur.first.first;
    int y=cur.first.second;
    int step=cur.second;
//    his[MP(x,y)] = 1;
//    edge[MP(x,y)] = 2;
    if(x==x1&&y==y1) {
      cout<<step<<endl;
      return 0;
    }
    
    for(int i=-1;i<=1;i++)
    for(int j=-1;j<=1;j++)  {
      if(i==0&&j==0) continue;
      int nx=x+i; 
      int ny=y+j;
      if(nx<1||nx>1e9||ny<1||ny>1e9) continue;
      pii nnode(nx,ny);
//      if(PRSNT(his,nnode)) continue;
      typeof(edge.begin()) iter = edge.find(nnode);
//      if(!PRSNT(edge,nnode)) continue;
      if(iter==edge.end()) continue;
      if(iter->second==2) continue;
      stq.push(MP(nnode,step+1));
      iter->second = 2;
    }
  }
  
  cout<<-1<<endl;
  return 0;
}

int main()
{
  //srand((unsigned)time(NULL));
  #ifdef LOCAL_TEST
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
  #endif
  ios :: sync_with_stdio(false);
  //cout << fixed << setprecision(16);
  return MAIN();
}