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

char opt[20];
priority_queue<int,vector<int>,greater<int> > Q;

const int maxn=(int)(1e6)+5;
const int INF=(int)(1e9);
int id[maxn],xs[maxn];
int tot=0;

inline void addopt(int x,int a=0) {
    ++tot;id[tot]=x;xs[tot]=a;
}
int main() {
    int n,x;
    read(n);
    REP(i,1,n) {
        scanf("%s",opt);
        if(opt[0]=='i') {
            read(x); 
            addopt(0,x);
            Q.push(x);
        } else if(opt[0]=='g') {
            read(x);
            while(!Q.empty() && Q.top()<x) addopt(2),Q.pop();
            if(Q.empty() || Q.top()!=x) addopt(0,x),Q.push(x);
            addopt(1,x);
        } else {
            if(Q.empty()) addopt(0,-INF),Q.push(-INF);
            addopt(2);Q.pop();
        }
    }
    printf("%d\n",tot);
    REP(i,1,tot) {
        if(id[i]==0) {
            printf("insert %d\n",xs[i]);
        } else if(id[i]==1) {
            printf("getMin %d\n",xs[i]);
        } else printf("removeMin\n");
    }
    return 0;
}