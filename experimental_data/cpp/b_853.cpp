#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int MAXB = 1e7;
char buf[MAXB], *cp = buf;
inline void rd(int &x){
	x = 0; int f = 1;
	while(*cp < '0' || '9' < *cp){if(*cp == '-') f = -1; cp++;}
	while('0' <= *cp && *cp <= '9') x = (x << 3) + (x << 1) + *cp - 48, cp++;
	x *= f;
}
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
const int MAXN = 100010;
int n, m, k;
struct F{
	int d, f, t, c;
}a[MAXN];
bool operator <(F a, F b){
	return a.d < b.d;
}
int minc[MAXN], tmp;
LL mintot[MAXN][2], tot;
LL ans;
int main(){
	//freopen("in.txt", "r", stdin);
	fread(buf, 1, MAXB, stdin);
	rd(n); rd(m); rd(k);
	for(int i = 0; i < m; i++){
		rd(a[i].d);
		rd(a[i].f);
		rd(a[i].t);
		rd(a[i].c);
	}
	sort(a, a + m);
	for(int i = 1; i <= n; i++) minc[i] = -1;
	tmp = n;
	tot = 0;
	for(int i = 0; i < m; i++){
		if(a[i].t == 0){
			int x = a[i].f;
			if(minc[x] == -1){
				tmp--;
				tot += a[i].c;
				minc[x] = a[i].c;
			}
			else if(minc[x] > a[i].c){
				tot -= minc[x] - a[i].c;
				minc[x] = a[i].c;
			}
		}
		mintot[i][0] = !tmp ? tot : INF;
	}
	
	for(int i = 1; i <= n; i++) minc[i] = -1;
	tmp = n;
	tot = 0;
	for(int i = m - 1; ~i; i--){
		if(a[i].f == 0){
			int x = a[i].t;
			if(minc[x] == -1){
				tmp--;
				tot += a[i].c;
				minc[x] = a[i].c;
			}
			else if(minc[x] > a[i].c){
				tot -= minc[x] - a[i].c;
				minc[x] = a[i].c;
			}
		}
		mintot[i][1] = !tmp ? tot : INF;
	}
	mintot[m][1] = INF;
	ans = INF;
	int R = 0;
	for(int i = 0; i < m; i++){
		int l = a[i].d + 1, r = l + k - 1;
		if(i < m - 1 && a[i].d == a[i + 1].d) continue;
		while(R < m && a[R].d <= r) R++;
		ans = min(ans, mintot[i][0] + mintot[R][1]);
	}
	cout << (ans >= INF ? -1 : ans) << endl;
	return 0;	
}