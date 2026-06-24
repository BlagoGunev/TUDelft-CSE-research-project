#include <bits/stdc++.h>
using namespace std;

using namespace std;

int main()
{
	string s;
	cin>>s;
	string temp = "";
	int max=0;
	vector<string> ans;
	int i;
	for(i=0 ;i<s.size(); i++)
	{
		if((s[i]-48)>max)
			max= s[i] - 48;
	}
	cout<<max<<endl;
	for(i=0; i<max; i++)
	{
		for(int j=0; j<s.size(); j++)
		{
			if(s[j]>48)
			{
				temp = temp + '1';
				s[j]--;
			}
			else
				temp = temp +'0';
		}
		ans.push_back(temp);
		temp = "";
	}
	for(i=0; i<max; i++)
	{
		cout<<stoi(ans[i])<<" ";
	}
	cout<<endl;
	return 0;
}