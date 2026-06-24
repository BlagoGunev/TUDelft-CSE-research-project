#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
lli p=0;

void recfunction1(lli n,lli k)
{
	if(n<=0)
	{
		return;
	}
	else
	{
		recfunction1((n-k)-(n-k)/10,k);
		if(n<k)
		{
			p+=n;
		}
		else
		p+=k;
		return;
	}
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli n,half;
    cin>>n;
    if(n%2==0)
    {
    	half=n/2;
	}
	else
	{
		half=n/2+1;
	}
    lli l=1,r=n,k;
    while(l<r)
    {
    	if(l==r)
    	break;
    	k=(l+r)/2;
    	p=0;
    	recfunction1(n,k);
    	if(p>half)
    	{
    		r=k;
		}
		else if(p<half)
		{
			l=k+1;
		}
		else
		{
			l=k;
			break;
		}
	}
//	cout<<p<<endl;
	cout<<l<<endl;
	return 0;
}