/*
 NOTE:
*/
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#define MP make_pair
#define F first
#define S second
#define TIME (double)clock()/CLOCKS_PER_SEC
using namespace std;
typedef long long ll;

namespace Input
{
	const int BUF = 65536;
	char buf[BUF + 1];
	char *head = buf, *tail = buf;
}
inline char inputchar()
{
	using namespace Input;
	if(head == tail)
		*(tail = (head = buf) + fread(buf, 1, BUF, stdin)) = 0;
	return *head++;
}
inline void inputnum(int &ret)
{
	char ch = inputchar();
	while(ch < '0' || ch > '9')
		ch = inputchar();
	ret = ch - '0';
	ch = inputchar();
	while(ch >= '0' && ch <= '9')
	{
		ret = ret * 10 + ch - '0';
		ch = inputchar();
	}
}

int n, m, k;

int mp[1000010], l[1000010], r[1000010], v[1000010];

int main()
{
//	freopen("test.in", "r", stdin);
//	freopen("test.out", "w", stdout);
 	ios::sync_with_stdio(false);
	inputnum(n);
	inputnum(m);
	inputnum(k);
	for (int v, i = 1; i <= m; i ++) {
		inputnum(v);
		mp[v] = -1;
	}
	for (int i = 1; i <= k; i ++) {
		inputnum(v[i]);
	}
	if (mp[0] == -1) {
		cout << -1 << endl;
		return 0;
	}
	
	int low = 1; 
	
	int last = 0;
	for (int i = 1; i < n; i ++) {
		if (mp[i] == -1)
			l[i] = last;
		else
			low = max(low, i - last), last = i;
	}
	
	ll fans = 1e14;
	for (int dis = low; dis <= k; dis ++) {
		int last = 0, cur = 0, num = 0, ok = 1;
		do {
			num ++;
			cur = last + dis;
			if (cur >= n)
				break;
			if (mp[cur] == -1)
				cur = l[cur];
			if (cur == last) {
				ok = 0;
				break;
			}
			last = cur;
//			cout << cur << endl;
		} while (true);
//		cout << dis << " pans = " << num << "  " << ok << endl;
		if (!ok)
			continue ;
		fans = min(fans, (ll)num * v[dis]);
	}
	if (fans == 1e14)
		cout << -1 << endl;
	else
		cout << fans << endl;
	return 0;
}
/*
*/