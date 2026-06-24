#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long a,b,c,d;
	cin>>a>>b;
	for(int i=1;;i++)
	{
		if(i*i > a)
		{
			c = i-1;
			break;
		}
	} 
	for(int i=1;;i++)
	{
		if(i*(i+1) > b)
		{
			d = i-1;
			break;
		}
	} 
	if(c<=d)
		cout<<"Vladik"<<endl;
	else
		cout<<"Valera"<<endl;
	return 0;
}