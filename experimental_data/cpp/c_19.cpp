#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <functional>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <ctime>
#include <cassert>
#include <queue>
#include <stack>
#include <cstdarg>

using namespace std;

#define TASKNAME "c"
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define forn(i, n) for (int i=0; i<(int)n; i++)
#define all(a) a.begin(), a.end()

typedef long double ldb;
typedef long long lld;
typedef unsigned long long uld;
typedef vector<int> vi;
typedef complex<double> cd;

double const eps=1e-9;
int const inf=0x3fffffff;
lld const infl=0x3fffffffffffffffLL;

int const K=100003;

template <class T>
inline T sqr(const T &a) {
    return a*a;
}
int const N=1<<17;
int n, a[N], ne[N];
map<int,int> f; 
lld hs[N], pw[N];
int pv[N], q[N+N];

void add(int i) {
    i+=N;
    q[i]=i-N;
    for (i>>=1; i; i>>=1)
        if (pv[q[i+i]]<=pv[q[i+i+1]])
            q[i]=q[i+i];
        else
            q[i]=q[i+i+1];
}
int get(int x, int y) {
    int rs=0;
    x+=N, y+=N;
    for (; x<=y; x=(x+1)/2, y=(y-1)/2) {
        if (pv[q[x]]<pv[rs] || pv[q[x]]==pv[rs] && q[x]<rs)
            rs=q[x];
        if (pv[q[y]]<pv[rs] || pv[q[y]]==pv[rs] && q[y]<rs)
            rs=q[y];
    }
    return rs;
}

void mpv() {
    pv[0]=inf;
    for (int i=1; i<=n; i++) {
        pv[i]=inf;
        for (int j=ne[i]; j; j=ne[j])
            if (j+(j-i)-1<=n && (hs[j-1]-hs[i-1])*pw[j-i]==(hs[j+(j-i)-1]-hs[j-1])) {
                pv[i]=j-i;
                add(i);
                break;
            }
    }
}


int main () {
//  freopen (TASKNAME".in", "r", stdin);
//  freopen (TASKNAME".out", "w", stdout);
    scanf ("%d", &n);
    hs[0]=0, pw[0]=1;
    for (int i=1; i<=n; i++) {
        scanf ("%d", a+i);
        hs[i]=hs[i-1]+a[i]*pw[i-1];
        pw[i]=pw[i-1]*K;
        if (f.find(a[i])!=f.end())
            ne[f[a[i]]]=i;
        f[a[i]]=i;
    }
    mpv();

    int cr=1;
    for(;;) {
        int v=get(cr, n);
        if (!v) break;
        cr=v+pv[v];
    }
    cout << n-cr+1 << endl;
    for (int i=cr; i<=n; i++)
        printf ("%d ", a[i]);
    return 0;
}