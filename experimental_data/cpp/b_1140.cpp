#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    string s;
	    cin>>n;
	    cin>>s;
	    int lc=0;
	    int rc=0;
	    if(s[0]=='<' && s[n-1]=='>')
	    {
	           for(int i=1;i<n;i++)
	           {
	               if(s[i]=='<')
	               {
	                   lc++;
	               }
	               else 
	               {
	                   break;
	               }
	           }
	           
	           for(int i=n-2;i>0;i--)
	           {
	               if(s[i]=='>')
	               {
	                   rc++;
	               }
	               else
	               {
	                   break;
	               }
	           }
	           
	           int ans=min(lc,rc);
	           cout<<ans+1<<endl;
	    }
	    else
	    {
	        cout<<"0"<<endl;
	    }
	}
	
	return 0;
}