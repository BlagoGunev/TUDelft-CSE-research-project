#include<iostream>
#include<algorithm>
#include<map>
#include<cstring>
#include<math.h>
using namespace std;
typedef long long ll;
const int N=103; 
ll qm(ll a,ll b,ll p)
{
    ll sum=1;
    while(b)
    {
        if(b&1) sum=sum*a%p;
        b>>=1;
        a=a*a%p;
    }
    return sum%p;
}
int a[N][N];
int main()
{ 
		ios::sync_with_stdio(false);
		cin.tie(0);cout.tie(0);
         int T;
		 cin>>T;
		 while(T--)
		 {
		 	int b,w;
			 cin>>b>>w;
			 for(int i=1;i<=b;i++)
			 	for(int j=1;j<=w;j++)
			 	{
			 		a[i][j]=0;
				 }
			 for(int i=1;i<=b;i++)
			 {
			 	for(int j=1;j<=w;j++)
				 {
				    if(i==1&&j==1)
					{
						cout<<"W";	 
					}
					else  
					{
						cout<<"B";
					} 
		        }
		        cout<<endl;
		    }
	}
        
}