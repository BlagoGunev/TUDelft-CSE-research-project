#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[15];
long long ans;

int main()
{
	ans=0;
	cin>>n;
	int tot=0;
	while(n!=0)
	{
		a[++tot]=n%10;
		n/=10;
	}
	for(int i=1;i<=tot;i++)
	{
		if(i!=tot&&a[i]<9)
		{
			ans+=a[i]+10;
			a[i+1]--;
		}
		else ans+=a[i];
	}
	cout<<ans;
	return 0;
}