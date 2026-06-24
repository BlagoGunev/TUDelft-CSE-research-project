#include <bits/stdc++.h>

using namespace std;



int main()
{
    int cnt;
	string s;
	cin>>s;
    cnt=s.size()/2;
    if (s.size()%2)
    {
        for (int i=1;i<s.size();i++)
            if (s[i]=='1')
            {
                cout<<cnt+1<<endl;
                return 0;
            }
    }
    cout<<cnt<<endl;
	return 0;
}