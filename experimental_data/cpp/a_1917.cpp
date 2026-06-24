#include<bits/stdc++.h>

using namespace std;

void solve()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int ng=0;
	int z=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]<0)
		{
			ng++;
		}
		if(a[i]==0)
		{
			z++;
		}
	}
	if(ng%2==0 && z==0)
	{
		cout<<1<<endl;
		cout<<1<<" "<<0<<endl;
	}
	else{
		cout<<0<<endl;
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
	 // for getting input for input1.txt
		freopen("input1.txt","r",stdin);
	 // for writing output to output1.txt
		freopen("output1.txt","w",stdout);
	#endif
	
	
	
	
		
	int t;
	cin>>t;
	while(t>0)
	{
		solve();
		t--;
	}

	
		
}