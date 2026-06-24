#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<map>
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
const int MAXN = 200010;
int n;
pair<int, int> a[MAXN];
int s1, s2;
int main(){
	//freopen("in.txt", "r", stdin);
	fread(buf, 1, MAXB, stdin);
	rd(n);
	for(int i = 0; i < n; i++) rd(a[i].first), rd(a[i].second);
	sort(a, a + n);
	s1 = s2 = -1;
	for(int i = 0; i < n; i++){
		if(s1 < a[i].first) s1 = a[i].second;
		else if(s2 < a[i].first) s2 = a[i].second;
		else return puts("NO"), 0;
	}
	puts("YES");
	return 0;
}