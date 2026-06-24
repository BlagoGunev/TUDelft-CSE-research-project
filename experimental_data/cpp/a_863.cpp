#include <bits/stdc++.h>
using namespace std;
string s;
bool check()
{
	for(int i = 0; i < s.length() / 2 ; ++i)
	{
		if(s[i] != s[s.length() - (i + 1)])
			return false;
	}
	return true;
}
int main()
{
	cin>>s;
	if(check())
	{
		puts("YES");
		return 0;
	}
	for(int  i = 0 ;i < 9 ; ++i)
	{
		s.insert(s.begin(),'0');
		if(check())
		{
			puts("YES");
			return 0;
		}
	}
	puts("NO");
	return 0;
}