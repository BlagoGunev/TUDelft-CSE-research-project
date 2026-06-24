#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int t,dis;
	
	cin>>t;
	
	double a,b,c,x;
	while(t--)
	{
		cin>>dis;
		x=(dis*dis-4*dis);
		if(x<0)
		{
			printf("N\n");
		}
		else
		{
			c=sqrt(x);
			b=(dis+c)/2;
			a=(abs)(b/(b-1));
			printf("Y %.9f %.9f\n",b,a);
		}
	}
}