#include <set>
#include <map>
#include <queue>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <cctype>
#include <bitset>
#include <cstring>
#include <cstdlib>
#include <utility>
#include <iostream>
#include <algorithm>
#define REP(i,a,b) for(int i=(a);i<=(b);i++)
#define PER(i,a,b) for(int i=(a);i>=(b);i--)
#define RVC(i,S) for(int i=0;i<(S).size();i++)
#define RAL(i,u) for(int i=fr[u];i!=-1;i=e[i].next)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
     
template<class T> inline
void read(T& num) {
    bool start=false,neg=false;
    char c;
    num=0;
    while((c=getchar())!=EOF) {
        if(c=='-') start=neg=true;
        else if(c>='0' && c<='9') {
            start=true;
            num=num*10+c-'0';
        } else if(start) break;
    }
    if(neg) num=-num;
}
/*============ Header Template ============*/

struct edge {
    int next,to,dist;
};

const int maxn=(int)(1e5)+5;
int fr[maxn];
int siz[maxn];
int a[maxn];
edge e[maxn<<1];
int tote=0;

inline void addone(int u,int v,int d) {
    ++tote;
    e[tote].next=fr[u];fr[u]=tote;e[tote].to=v;e[tote].dist=d;
}
inline void addedge(int u,int v,int d) {
    addone(u,v,d);addone(v,u,d);
}

int res=0;
void dfs(int x,int f,LL v,int fl) {
    siz[x]=1;
    int c=fl;
    if(v>a[x]) c=0;
    RAL(i,x) if(e[i].to!=f) {
        dfs(e[i].to,x,max(e[i].dist*1LL,v+e[i].dist),c);
        siz[x]+=siz[e[i].to];
    }
    if(fl && !c) res+=siz[x];
}

int main() {
    int n;
    read(n);
    if(n==1) {
        printf("0\n");
        return 0;
    }
    REP(i,1,n) read(a[i]);
    memset(fr,-1,sizeof(fr));
    REP(i,2,n) {
        int p,c;
        read(p);read(c);
        addedge(p,i,c);
    }
    dfs(1,0,0,1);
    printf("%d\n",res);
    return 0;
}