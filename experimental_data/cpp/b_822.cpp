#include <bits/stdc++.h>
using namespace std;
int main ()
{
	int n, k, l = 0, o = 0, cnt = 0, max=-1;
	string a, s;
	cin>>n>>k;
	cin>>a>>s;
	int u[n], y[n];
	for(int i = 0; i < k - n + 1; i++)
	{
		l = 0;
		for(int j = 0; j < n; j++)
		{
			y[j] = 0;
			if(a[j] == s[i+j])
			{
				l++;
			//cout<<j<<" test "<<i<<endl;
			}
			else
				y[j] = j+1;//,	cout<<y[j]<<" array "<<i<<endl;
		}
		if(l > max)
		{
			max = l;
			for(int j = 0; j < n; j++)
			{
			u[j] = 0;
			u[j] = y[j];
			}
		}
	}
	cout<<n-max<<endl;
	for(int j = 0; j < n; j++)
	{
		if(u[j] != 0)
			cout<<u[j]<<' ';
	}
	return 0;
}