#include<bits/stdc++.h>
using namespace std;
string op;
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	int n,i,c=0,x;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>op>>x;
		if(op[0]=='B')
		{
			if(c<x)cout<<"YES\n";
			else cout<<"NO\n";
			c-=x;
			c=max(c,0);
		}
		else c+=x;
	}
	return 0;
}