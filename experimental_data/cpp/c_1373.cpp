#include<bits/stdc++.h>

#define endl '\n'

using namespace std;

typedef long long i64;

typedef int i32;

typedef long double ld;



void like(void)

{

	string s;

	cin>>s;

	s='i'+s;

	i64 ans=0;

	int t=0;

	for(int i=1;i<s.size();i++)

	{

		if(s[i]=='+')

		t++;

		else t--;

		if(t<0)

		ans+=i,t=0;

	}

	ans+=s.size()-1;

	cout<<ans<<endl;

}



int main()

{

	ios::sync_with_stdio(false);

	cin.tie(nullptr);

	cout.tie(nullptr);

	int t;

	cin>>t;

	while(t--)

   		like();

	return 0;

}