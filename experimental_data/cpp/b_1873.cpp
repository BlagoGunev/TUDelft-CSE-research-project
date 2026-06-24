#include <bits/stdc++.h>
using namespace std;
long long n,i,m,sum=1; 
long long a[19];
int main ()
{
cin >>m;
while(m--)
{
	cin >>n;
	for (i=1;i<=n;i++)
	{
		cin >>a[i];
	}
	sort(a+1,a+n+1);
	for (i=n;i>=2;i--)
	{
	sum*=a[i];	
	}
	sum*=(a[1]+1);
	cout <<sum<<endl;
	sum=1;
}

	 return 0;
 }