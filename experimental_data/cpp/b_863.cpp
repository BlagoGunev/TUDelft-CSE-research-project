#include<bits/stdc++.h>
#define ll long long int 
using namespace std;

int ff(int a[],int n,int k,int l)
{
	int i=0,sum=0,j=1;
	while(j<n)
	{
		if(i == k || i==l)
		{
			i++;
			j++;
		}
		else if(j == l || j == k)
		{
			j++;
		}
		else
		{
			sum += abs(a[i]-a[j]);
			i = j+1;
			j = i+1;
		}
	}
	return sum;
}

int main()
{
	int n;
	cin>>n;
	n *=2;
	int a[n];
	for(int i=0;i<n;i++)
	cin>>a[i];
	sort(a,a+n);
	int ans = INT_MAX;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			ans = min( ans ,ff(a,n,i,j) );
		}
	}
	cout<<ans;
}