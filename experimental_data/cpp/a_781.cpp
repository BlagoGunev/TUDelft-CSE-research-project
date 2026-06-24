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
    int next,to;
};

const int maxn=(int)(2e5)+5;
int fr[maxn];
int in[maxn];
int a[maxn];
edge e[maxn<<1];
int tote=0;

inline void addone(int u,int v) {
    ++tote;
    e[tote].next=fr[u];fr[u]=tote;e[tote].to=v;
}

inline void addedge(int u,int v) {
    addone(u,v);addone(v,u);
}

void _dfs(int x,int f) {
    int ai=a[x],bi=a[f];
    int now=1;
    RAL(i,x) if(e[i].to!=f) {
        while(now==ai || now==bi) now++;
        a[e[i].to]=now++;_dfs(e[i].to,x);
    }
}

int main() {
    int n;
    read(n);
    memset(fr,-1,sizeof(fr));
    REP(i,1,n-1) {
        int u,v;
        read(u);read(v);
        addedge(u,v);++in[u];++in[v];
    } 
    int res=0;
    REP(i,1,n) res=max(res,in[i]);
    printf("%d\n",res+1);a[1]=1;_dfs(1,0);
    REP(i,1,n) printf("%d ",a[i]);putchar('\n');
    return 0;
}