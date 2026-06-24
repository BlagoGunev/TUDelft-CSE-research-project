#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int Maxn = 1510;
char s[Maxn]; int n, m;
int f[26][Maxn];
int val[Maxn], st[Maxn], len;
int t[Maxn], tl, o[Maxn];
int _max(int x, int y) { return x > y ? x : y; }
int _min(int x, int y) { return x < y ? x : y; }
int main() {
	int i, j, k;
	scanf("%d", &n);
	scanf("%s", s+1);
	len = 0;
	for(i = 1; i <= n; i++){
		if(s[i] == s[i-1]) val[len]++;
		else st[++len] = s[i]-'a', val[len] = 1;
	}
	for(i = 0; i < 26; i++){
		tl = 0;
		for(j = 1; j <= len; j++){
			if(st[j] == i){
				tl++;
				t[tl] = 0; o[tl] = val[j];
			} else t[tl] += val[j];
		}
		for(j = 1; j <= tl; j++){
			int p = 0, u = o[j];
			for(k = j; k <= tl; k++){
				f[i][p] = _max(u, f[i][p]);
				p += t[k]; u += t[k]+o[k+1];
			}
		}
		for(j = 0; j < n; j++) f[i][j+1] = _max(f[i][j+1], _min(f[i][j]+1, n));
	}
	scanf("%d", &m);
	for(i = 1; i <= m; i++){
		int x; char c;
		scanf("%d %c", &x, &c);
		printf("%d\n", f[c-'a'][x]);
	}
	return 0;
}