#include<bits/stdc++.h>
using namespace std;
const int inf=1234567;
int a[20];
int main()
{
	string s;
	cin>>s;
	int l=s.length(),ans=inf;
	for(int i=0;i<l;i++) a[i]=s[i]-'0';
	for(int i=0;i<(1<<l);i++)
	{
		int num=0,k=1,ct=0;
		vector<int>v;
		for(int j=0;j<l;j++)
		{
			if(i&(1<<j))
			{
			   	num=num*10+a[j];
				v.push_back(a[j]);
				ct++;
			}
		}
		if(num>0)
		{
			int k=sqrt(num),kk=0;
			while(kk<v.size() && v[kk]==0) kk++;
			if(k*k==num)		
			ans=min(ans,l-(ct-kk));
		}
	}
	if(ans==inf)
	cout<<"-1";
	else
	cout<<ans;		
	return 0;
}