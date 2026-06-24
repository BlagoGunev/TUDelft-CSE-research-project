#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string str;
	cin>>str;
	int i=0,n=0,p=0;
	while(i<2)
		n = n*10 + str[i] - '0',i++;
	i=3;
	p = p*10 + str[3] - '0';
	p = p*10 + str[4] - '0';
	int cnt=0;
	// cout<<n<<"  "<<p;
	while(1)
	{
		int flag=1,i,j;
		for(i=0,j=4;i<5;i++,j--)
		{
			if(str[i] != str[j])
			{
				flag = 0;
				break;
			}
		}
		if(flag)
			break;
		p = p + 1;
		if(p>59)
		{
			p = 0;
			n++;
		}
		if(n>23)
			n=0;
		if(n<9)
		{
			str[0] = '0';
			str[1] = n + '0';
		}
		else
		{
			str[0] = n/10 + '0';
			str[1] = n%10 + '0';
		}
		if(p<9)
		{
			str[3] = '0';
			str[4]  = p + '0';
		}
		else
		{
			str[3] = p/10 + '0';
			str[4] = p%10 + '0';
		}
		cnt++;
	}
	cout<<cnt;
	return 0;
}