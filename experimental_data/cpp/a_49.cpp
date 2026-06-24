#include <bits/stdc++.h>
//#pragma comment(linker, "/STACK:64000000")
#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <cstdio>
#include <string>
#include <stack>
#include <deque>
#define sf scanf
#define pf printf
#define ve vector
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define FOR(i,n) for(int i = 0; i < (n); i++)
#define FOR1(i,n) for(int i = 1; i <= (n); i++)
#define all(x) (x).begin(),(x).end()
#define sqr(x) (x)*(x)
using namespace std;
bool iss(char ch)
{
	char d = tolower(ch);
	return d == 'a' || d == 'e' || d == 'i' || d == 'o' || d == 'u' || d == 'y';
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	int n;
	char str[101] = {0};
	cin.getline(str,101);
	int sz = strlen(str);
	while(!isalpha(str[sz - 1])) sz--; 
	if(iss(str[sz - 1]))
		pf("YES");
	else
		pf("NO");
	return 0;
}