//  Created by Sengxian on 4/25/16.
//  Copyright (c) 2016年 Sengxian. All rights reserved.
//  
#include <algorithm>
#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

inline int ReadInt() {
	static int n, ch;
	n = 0, ch = getchar();
	while (!isdigit(ch)) ch = getchar();
	while (isdigit(ch)) n = (n << 3) + (n << 1) + ch - '0', ch = getchar();
	return n;
}
typedef long long ll;
const int maxn = 100000 + 3;
int n, dir[maxn], dis[maxn];
bool vis[maxn];

void go(int p) {
	while (true) { 
		if (p < 0 || p >= n) {
			puts("FINITE");
			break;
		}
		if (vis[p]) {
			puts("INFINITE");
			break;
		}
		vis[p] = true;
		p += dir[p] * dis[p];
	}
}

char str[maxn];
int main() {
	n = ReadInt();
	scanf("%s", str);
	for (int i = 0; i < n; ++i)
		if (str[i] == '>') dir[i] = 1;
		else dir[i] = -1;
	for (int i = 0; i < n; ++i)
		dis[i] = ReadInt();
	go(0);
	return 0;
}