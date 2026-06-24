//By Don4ick 
//#define _GLIBCXX_DEBUG

#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;
typedef unsigned int ui;

#define forn(i, n) for (int i = 1; i <= n; i++)
#define pb push_back
#define all(x) x.begin(), x.end()
#define y1 qewr1234

const double PI = acos(-1.0);
const int DIR = 4;
const int X[] = {1, 0, -1, 0};
const int Y[] = {0, 1, 0, -1};

const int N = (int)1e5 + 228;

using namespace std;

int n;
ll a[N];

ll Sqrt(ll x)
{	
	ll y = sqrt(x);
	while(y * y < x)
		y++;
	while(y * y > x)
		y--;
	return y;	
}

bool check(ll x)
{
	ll y = Sqrt(x);
	return y * y == x;
}

int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie();
	//cout.tie();		

	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);

	scanf("%d", &n);
	for (int i = 2; i <= n; i += 2)
	{
		scanf("%lld", &a[i]);		
	}
	ll cur = 0;
	for (int i = 1; i <= n; i += 2)
    {
		ll ptr = cur + 1;
		while(ptr + 1 <= a[i + 1] && !check(ptr * ptr + a[i + 1]))
			ptr++;           	
		if (!check(ptr * ptr + a[i + 1]))
		{
			cout << "No" << endl;
			return 0;
		}    		
		a[i] = ptr * ptr - cur * cur;	
		cur = Sqrt(ptr * ptr + a[i + 1]);
    }
    printf("Yes\n");
    forn(i, n)
    {
    	printf("%lld ", a[i]);
	}                        
	return 0;
}