#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
inline int Read() {
	int ret = 0, flag = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {
		if(ch == '-') flag = -1;
		ch = getchar();
	}
	while('0' <= ch && ch <= '9') {
		ret = ret*10 + (ch-'0');
		ch = getchar();
	}
	return ret*flag;
}

const int maxn = 2e5 + 7;
int a[maxn];
char Str[maxn];
priority_queue <int, vector<int>, greater<int> > que;

int main() {
	int n = Read(), k = Read(), cnt = 1;
	for(int i = 1; i <= n; i ++) a[i] = Read();
	scanf("%s", Str + 1);
	LL ans = 0; que.push(a[1]);
	for(int i = 2; i <= n; i ++) {
		if(Str[i] != Str[i-1]) {
			while(!que.empty()) {
				ans += que.top();
				que.pop();
			}
			que.push(a[i]);
			cnt = 1;
		}
		else {
			if(cnt + 1 <= k) {
				que.push(a[i]);
				cnt ++;
			}
			else {
				que.push(a[i]);
				que.pop();
			}
		}
	}
	while(!que.empty()) {
		ans += que.top();
		que.pop();
	}
	cout << ans << endl;
	return 0;
}