#include<bits/stdc++.h>
using namespace std;
#define int long long int
 

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout<<setprecision(10)<<fixed;
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	int t;
	cin>>t;
	while(t--)
	{
		string p,h;
		cin>>p>>h;
		int l=h.length();
		int l1=p.length();
		int a[l+1][26];
		memset(a,0,sizeof(a));
		int m[26];
		memset(m,0,sizeof(m));
		for(int i=0;i<l1;i++)
			m[p[i]-'a']++;
		int f=0;
		for(int i=0;i<l;i++)
		{
			a[i+1][h[i]-'a']++;
			for(int j=0;j<26;j++)
				a[i+1][j]+=a[i][j];
			if(i>=(l1-1))
			{
				int f1=0;
				for(int j=0;j<26;j++)
				{
					int t1=a[i+1][j]-a[i+1-l1][j];
					if(t1!=m[j])
					{
						f1=1;
						break;
					}

				}
				if(f1==0)
				{
					f=1;
					break;
				}
			}
		}
		if(f==1)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;

	}
	return 0;
}