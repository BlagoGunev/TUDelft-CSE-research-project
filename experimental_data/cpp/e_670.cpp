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

const int maxn=(int)(5e5)+5;
int lt[maxn],rt[maxn];
int pr[maxn];
int stk[maxn],top=0;
char br[maxn];
char opt[maxn];

int main() {
    int n,m,p;
    read(n);read(m);read(p);
    scanf("%s",br+1);
    REP(i,1,n) {
        if(br[i]=='(') stk[++top]=i;
        else pr[stk[top]]=i,pr[i]=stk[top],top--;
    }
    REP(i,1,n) lt[i]=i-1,rt[i]=i+1;
    rt[0]=1;
    scanf("%s",opt+1);
    REP(i,1,m) {
        if(opt[i]=='L') p=lt[p];
        else if(opt[i]=='R') p=rt[p];
        else if(opt[i]=='D') {
            int l=pr[p],r=p;
            if(l>r) swap(l,r);
            rt[lt[l]]=rt[r];lt[rt[r]]=lt[l];
            if(rt[r]!=n+1) p=rt[r];
            else p=lt[l];
        }
    }
    for(int i=0;i!=n+1;i=rt[i]) if(i!=0) putchar(br[i]);
    putchar('\n');
    return 0;
}