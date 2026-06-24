#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <cmath>
#include <cstring>
#include <string>
#include <assert.h>
#include <ctime>
#include <cstdlib>
#define fi first
#define se second
#define pb push_back
#define ALL(x) (x).begin(),(x).end()

using namespace std;

typedef pair<int,int> pii;

const int N=500010,P=1e9+7;

inline char nc(){
  static char buf[100000],*p1=buf,*p2=buf;
  return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}

template<class T>
inline void read(T &x){
  char c=nc(); x=0; int f=1;
  for(;c>'9'||c<'0';c=nc())if(c=='-')f=-1;
  for(;c>='0'&&c<='9';x=x*10+c-'0',c=nc()); x*=f;
}

set<pii> S[N];

int n,m;

int main(){
#ifdef ljn
  freopen("1.in","r",stdin);
  freopen("1.out","w",stdout);
#endif
  read(n); read(m); int ans=0;
  for(int i=1;i<=m;i++){
    int x,y,w,lst; read(x); read(y); read(w);
    if(S[x].empty()) lst=0;
    else{
      set<pii>::iterator it=S[x].lower_bound(pii(w,0));
      if(it==S[x].begin()) lst=0;
      else{
	it--; lst=it->second;
      }
    }
    pii cur=pii(w,lst+1);
    if(!S[y].empty()){
      set<pii>::iterator it=S[y].lower_bound(pii(w+1,0));
      if(it!=S[y].begin()){
	it--;
	if(it->second>=lst+1) continue;
      }
    }
    set<pii>::iterator it=S[y].insert(cur).fi;
    while(1){
      it++; if(it==S[y].end()) break;
      if(it->second<=lst+1) S[y].erase(it);
      else break;
      it=S[y].lower_bound(cur);
    }
    ans=max(ans,lst+1);
  }
  printf("%d\n",ans);
  return 0;
}