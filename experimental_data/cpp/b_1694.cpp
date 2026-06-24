#include<iostream>

using namespace std;

const int N=2e5+10;



int main()

{

	int t;

	cin>>t;

	while(t--)

	{

		int n;

		cin>>n;

		string s;

		cin>>s;

		long long res=n;

		for(int i=1;i<n;i++)

		{

			if(s[i]!=s[i-1])res+=i;

		}

		cout<<res<<endl;

	}

	return 0;

}