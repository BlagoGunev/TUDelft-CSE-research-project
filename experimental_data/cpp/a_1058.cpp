#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <utility>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <string.h>
#include <iomanip>
#include <string>
using namespace std;
#define inf 2147483647
#define mp make_pair
#define pb push_back
#define ll long long int
#define ull unsigned long long int
#define fast_io ios_base::sync_with_stdio(false), cin.tie(nullptr)
#define se second
#define fi first
typedef pair<int,int>ii;
typedef pair<int,pair<int,int> >iii;
typedef vector<int>vi;
typedef vector<ii>vii;
typedef vector<iii>viii;
typedef vector< vi >mi;
typedef vector<long long int>vlli;
typedef queue<int>qi;
typedef queue<ii>qii;
typedef queue<iii>qiii;
typedef priority_queue<int>pqi;
typedef priority_queue<ii>pqii;
typedef priority_queue<iii>pqiii;
typedef priority_queue<ii,vii,greater<ii> >ipqii;
typedef priority_queue<iii,viii,greater<iii> >ipqiii;
typedef stack<int>stki;
typedef stack<ii>stkii;
typedef stack<iii>stkiii;
const int maxn= 1e5+10;
long double error= 1e-9;
const int re = 1e9+7;
int main()
{
	int n;
	cin>>n;
	int x;
	int h=0;
	while(n--)
	{
		cin>>x;
		if(x)
		{
			h=1;
		}
	}
	if(h)
	{
		puts("HARD");
	}
	else
	{
		puts("EASY");
	}
}