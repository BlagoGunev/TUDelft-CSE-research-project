#include<bits/stdc++.h>
using namespace std;
bool check(long long n)
{
    long long h=cbrt(n);
    long long l=1;
    while(h>=l)
    {
    	long long p = (h*h*h)+(l*l*l);
        if(p<n)
        {
            l++;
            continue;
        }
        else if(p>n)
        {
            h--;
            continue;
        }
        return 1;
    }
	return 0;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
    	long long n;
    	cin>>n;
		if(check(n)) 
		{
			cout<<"YES"<<"\n";
		}
		else 
		{
			cout<<"NO"<<"\n";
		}
	}
	return 0;
}