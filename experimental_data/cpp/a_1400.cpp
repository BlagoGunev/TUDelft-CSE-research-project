#include<bits/stdc++.h>
using namespace std;
#include <numeric>
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define int long long
#define mod 1000000007
#define pb push_back

int32_t main()
{
    fast
    //#ifndef ONLINE_JUDGE
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //#endif

    int t;
    cin>>t;
    while(t--)
    {
    	bool ans=true;
    	int n,m,i,j,k,a,b,x,y;

    	cin>>n;
    	string s;
    	cin>>s;

    	string w;
    	//while(n--)
    		//w+='0';

    	int u=0;
    	int v=n;
    	for(i=0;i<n;i++)
        {
    	    int c=0;
            for(j=u;j<v;j++)
    		{
    			if(s[j]=='0')
                    break;
                else
                    c++;
    		}
    		  if(c==n)
                    w+='1';
              else
                    w+='0';

              u++;v++;
        }

    	cout<<w<<endl;
    }

}