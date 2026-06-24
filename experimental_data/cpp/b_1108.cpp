#include <bits/stdc++.h>
#include <vector>
#include<math.h>

using namespace std;

int main()
{
	int n;
	cin>>n;
	int a[n];
	int product=1;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		product*=a[i];
	}
	sort(a,a+n);
	int ans1=a[n-1];
	int ans2=0;
	for(int i=0;i<n;i++)
	{
		if(ans1%a[i]!=0)
			ans2=a[i];
	}
	if(ans2==0)
	{
		for(int i=0;i<n;i++)
		{
			if(a[i]==a[i+1])
			ans2=a[i];
		
		}
	}
	
	 
	cout<<ans1<<" "<<ans2;

}