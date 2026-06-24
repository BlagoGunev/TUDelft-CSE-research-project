#include<iostream>
using namespace std;
const int N=1e6;
int a[N];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		int k=0;
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=n;i>=3;i--)
		{
			if(a[i]==0) continue;
			else if(a[i]>0) 
			{
				a[i-1]-=2*a[i];
				a[i-2]-=a[i];
				a[i]=0;
			}
			else break;
		}
		for(int i=1;i<=n;i++)
		{
			if(a[i]!=0)
			{
				k=-1;
				break;
			}
		}
		if(k==-1) cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
	return 0;
}