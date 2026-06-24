#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>

#define ll long long

using namespace std;

ll n,a,b,c,k,ans=0;

int main () {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> a >> b >> c;

/*	for (int i=0;i<=4;i++)
	{
		if ((n+i)%4 == 0) 
		{
			k = i;
			break;
		}
	}
*/
/*	n = n % 4;

	if (n==0)
	{
		cout << 0;
		return 0;
	}
	
	if (n==1)
	{
		ans = min (3*a, min (b+a,c));
	}

	else if (n==2)
	{
		ans = min (2*a, min (b,c*2));
	}

	else if (n == 3)
	{
		ans = min (a, min(c , c+b) );
	}
	
	cout << ans;
*/  if(n%4==0)
		cout << 0;
	else
	if(n%4==1)
		cout << min(3*a,min (a+b,c));
	else
	if(n%4==2)
		cout << min(2*a,min (b,2*c));
	else
		cout << min(a,min(3*c,b+c));

	return 0;
}