#include <bits/stdc++.h>
#define pb push_back
#define li long long int

using namespace std;

void FAST()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
}

int main()
{
    FAST();
    int t;
    cin>>t;
    while(t--)
    {
    	li n,i,ma,mb,ans=0,x,y,z;
    	cin>>n;
    	li a[n],b[n];
    	for(i=0;i<n;i++)	cin>>a[i];
    	for(i=0;i<n;i++)	cin>>b[i];
    	ma=*min_element(a,a+n);
    	mb=*min_element(b,b+n);
    	for(i=0;i<n;i++)
    		ans+=a[i]-ma+b[i]-mb;	
    	for(i=0;i<n;i++)
    	{
    		x=a[i]-ma;
    		y=b[i]-mb;
    		z=min(x,y);
    		ans-=z;
		}
		cout<<ans<<"\n";
	}
}