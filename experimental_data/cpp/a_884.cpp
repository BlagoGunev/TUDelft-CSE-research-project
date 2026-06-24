#include "bits/stdc++.h" 
#include <unordered_map>
#include <deque>
using namespace std;
typedef long long int Int;
#define setbits(x) __builtin_popcount(x)
#define fast cin.sync_with_stdio(0);cin.tie(0)

Int fexpo(Int a,Int b)
{
    if(b == 0)      return 1LL;
    if(b == 1)      return a;
    if(b == 2)      return ((a) * (a));
    if(b%2 == 0)    return fexpo(fexpo(a,b/2),2);
    else          return ((a) * (fexpo(fexpo(a,(b-1)/2),2)));
}


int main()
{
	
	// This is WAY.
	int n, k;
	cin >> n >> k;
	int sum = 0;
	int ans = 0;
	bool t = false;
	for(int i = 0 ; i < n ;i++)
	{
		int x;
		cin >> x;
		sum += (86400 - x);
		if(sum >= k and t == false)
		{
			ans = i;
			t = true;
		}

	}
	cout << ans + 1 << endl;
	return 0;
}