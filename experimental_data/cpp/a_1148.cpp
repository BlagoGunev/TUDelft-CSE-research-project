#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<deque>
#include<list>
#include<set>
#include<map>
#include<algorithm>
#include<climits>
#include<cmath>
#include<utility>
#define forn(i, n) for(int i=0; i<n; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
typedef long long li;
typedef pair<int, int> ii;
typedef pair<li, li> lii;
typedef vector<int> vi;
typedef vector<li> vli;
typedef vector<ii> vii;
typedef vector<lii> vlii;
int main()
{
	ios::sync_with_stdio(0); 
	cin.tie(0);
	li a, b, c;
	li ans=0;
	cin >> a >> b >> c;
	ans += 2*min(a, b);
	if(b!=a) ans++;
	ans += 2*c;
	cout << ans;
	return 0;
}