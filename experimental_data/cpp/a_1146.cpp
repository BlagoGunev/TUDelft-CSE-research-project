#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin >> s;
	int a=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='a') a++;
	}
	cout << a + min((int)s.size()-a , a-1)<<endl;
}