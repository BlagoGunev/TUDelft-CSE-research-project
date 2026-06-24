#include <cstdio>
#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>
#include <utility>
#include <string>
#include <cmath>
#include <vector>
#include <functional>
#include <ctime>
#include <map>
#include <set>
#include <list>
#include <unordered_set>
#include <unordered_map>
//#include <bits/stdc++.h>
using namespace std;

#define SWAP(a, b, type) do{type x;x=b, b=a, a=x;}while(0)
#define MOD 1000000007
#define v(type) vector<type>
#define sz(x) (int)(x).size()

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pint;
typedef pair<ull, ull> pull;
typedef struct node
{
	int a;
	int b;
}node;

char atemp[100000][2], btemp[100000][2];
int n;
ll ans;
int getnum(int n);

int main()
{
	ios::sync_with_stdio(false), cin.tie(0);
	int i;
	string a, b;
	cin >> n >> a >> b;
	for (i = 0;i < n / 2;i++)
		atemp[i][0] = a[i], btemp[i][0] = b[i];
	if (n % 2)
	{
		atemp[i][0] = a[i], btemp[i][0] = b[i];
		i++;
	}
	for (;i < n;i++)
		atemp[n - 1 - i][1] = a[i], btemp[n - 1 - i][1] = b[i];
	for (i = 0;i < n / 2;i++)
		ans += getnum(i);
	if (n % 2)
		ans += getnum(i);

	cout << ans;
	return 0;
}

int getnum(int n)
{
	if (atemp[n][0] == atemp[n][1])
	{
		if (btemp[n][0] == btemp[n][1])
			return 0;
		else
		{
			if (atemp[n][0] == btemp[n][0] || atemp[n][0] == btemp[n][1])
				return 1;
			else
				return 2;
		}
	}
	else
	{
		if (btemp[n][0] == btemp[n][1])
			return 1;
		else
		{
			if (min(atemp[n][0], atemp[n][1]) == min(btemp[n][0], btemp[n][1]) && max(atemp[n][0], atemp[n][1]) == max(btemp[n][0], btemp[n][1]))
				return 0;
			else if (atemp[n][0] == btemp[n][0] || atemp[n][0] == btemp[n][1] || atemp[n][1] == btemp[n][0] || atemp[n][1] == btemp[n][1])
				return 1;
			else
				return 2;	
		}
	}
}