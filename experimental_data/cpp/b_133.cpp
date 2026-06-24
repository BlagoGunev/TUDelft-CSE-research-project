#include<bits/stdc++.h>

using namespace std;

long long int x,ans;

long long int mod=1000003;

int main()

{

	string s;

	cin>>s;

	for(int i=0 ; i<s.size() ; i++)

	{

		if(s[i]=='>')

		{

			x=8;

		}

		if(s[i]=='<')

		{

			x=9;

		}

		if(s[i]=='+')

		{

			x=10;

		}

		if(s[i]=='-')

		{

			x=11;

		}

		if(s[i]=='.')

			x=12;

		if(s[i]== ',')

			x=13;

		if(s[i]=='[')

			x=14;

		if(s[i]==']')

			x=15;

		

		ans*=16;

		ans+=x;

		ans%=mod;

	}

	cout<<ans;

}