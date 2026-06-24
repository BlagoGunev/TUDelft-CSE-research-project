#include<cstdio>

#include<iostream>

#include<algorithm>

#include<string.h>

#include<vector>

#include<map>

using namespace std;

typedef long long ll;

struct p{

	int x, y;

}s[5010];

bool cmp(p a, p b)

{

	return a.x < b.x || (a.x == b.x && a.y < b.y);

}

int n;

int main()

{

//	freopen("input.txt", "r", stdin);

	scanf("%d", &n);

	for(int i = 0; i < n; i++)

		scanf("%d%d", &s[i].x, &s[i].y);

	sort(s, s + n, cmp);

	int t = s[0].y;

	for(int i = 1; i < n; i++){

		if(s[i].x > t && s[i].y > t)

			t = min(s[i].x, s[i].y);

		else if(s[i].y >= t)

			t = s[i].y;

		else t = s[i].x;

	}

	printf("%d", t);

	return 0;

}