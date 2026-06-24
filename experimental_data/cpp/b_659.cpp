#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <ctime>
#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>
#include <algorithm>
#include <set>
#include <complex>
#include <map>
#include <bitset>
#define LL long long
#define ULL unsigned long long 
#define INF 1<<30 
#define INFL 0x3f3f3f3f3f3f3f3f
#define Mod 1000000007 
#define PII pair<int,int>
#define mk make_pair
#define mt make_tuple
#define Min(a,b) ((a)>(b)?(b):(a))
#define Max(a,b) ((a)<(b)?(b):(a))
using namespace std; 
const double PI=acos(-1.0);
const double EPS=1e-10;

inline int read() {
    static char ch;
    bool sgn = false;
    while (ch = getchar(), ch < '0' || ch > '9') if (ch == '-') sgn = true;
    int res = ch - 48;
    while (ch = getchar(), ch >= '0' && ch <= '9') res = res * 10 + ch - 48;
    return sgn ? -res : res;
}

char s[100001][12];
int p[100001];
vector<int> E[10001];

bool cmp(int i,int j) {
	return p[i]>p[j];	
}

int main() {
	int n=read(),m=read();
	for(int i=1;i<=n;i++) {
		scanf("%s",s[i]);
		int x=read();
		p[i]=read();
		E[x].push_back(i);
	}
	for(int i=1;i<=m;i++) {
		sort(E[i].begin(),E[i].end(),cmp);
		if(E[i].size()>2&&p[E[i][2]]==p[E[i][1]]) puts("?");
		else printf("%s %s\n",s[E[i][0]],s[E[i][1]]);
	}
}