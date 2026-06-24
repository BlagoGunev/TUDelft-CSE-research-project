#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<vector>
#include<sstream>
#include<ctime>
#include<cassert>
#define LL long long
const int N = 100010;
int cnt, vis[444];
int g[444][444];
int n, m;
int gcd(int a, int b)
{
        return !b ? a : gcd(b, a % b);
}
int fa[N], a[N];
int find(int x)
{
        return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void Unio(int a,int b)
{
	int x = find(a);
	int y = find(b);
	if(x != y) {
                fa[y] = x;
        }
}
int suffix_gcd[N];
bool read (int &x) 
{
        int c = getchar (); int sign = 1;
        while (~c && c < '0' || c > '9') { if (c == '-') sign = -1; c = getchar (); }
        for (x = 0; ~c && '0' <= c && c <= '9'; c = getchar ()) x = x * 10 + c - '0';
        x *= sign;
        return ~c;
}
int main()
{
	int n, q;
	while(scanf("%d", &n) == 1){
		for(int i = 1; i <= n;i++){
                        read(a[i]);
		}
                fa[n + 1] = n + 1;
                std::map<int, LL>mp;
		for(int i = n; i >= 1; i--){
                        fa[i] = i;
			int head = i, tail = i;
			suffix_gcd[i] = a[i];
			for(int j = find(i + 1); j <= n; j = find(j + 1) ){
				suffix_gcd[j] = gcd(a[i], suffix_gcd[j]);
				if(suffix_gcd[j] != suffix_gcd[tail]){
                                        mp[suffix_gcd[tail]] += tail - head + 1;
					head = tail + 1;
				}
				else {
                                        Unio(j, tail);
                                }
				tail = j;
			}
                        mp[suffix_gcd[n]] += n - head + 1;
		}
                read(q);
                while(q--) {
                        int a;
                        read(a);
                        printf("%I64d\n", mp[a]);
                }
	}
    return 0;
}