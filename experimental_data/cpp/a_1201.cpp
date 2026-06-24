#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define f(i,a,b)  for(ll i=a;i<b;i++)
int main() 
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    int l[m][5]={0};
    for(int i=0;i<n;i++)
    {
	
	    string s;
	    cin>>s;
	    
	    for(int j=0;j<m;j++)
	    {
	    	l[j][s[j]-65]++;
		}
	}
	int l1[m]={};
	ll ans=0;
	
	f(i,0,m)
	{	cin>>l1[i];	
		/*f(j,0,5)
		cout<<l[i][j]<<" ";
		cout<<"\n";*/
	
	sort(l[i],l[i]+5);
	
		
		ans+=l[i][4]*l1[i];
		
	}
	cout<<ans<<"\n";
}