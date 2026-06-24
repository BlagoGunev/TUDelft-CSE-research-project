/*
 *  Created on: 9-June-2019
 *      Author: ankur314
 */
#include<bits/stdc++.h>
#define lli long long int 
#define li long int
#define db double 
#define ldb long double
#define vr vector 
#define it iterator
#define fi(i,a,n) for(int i=a;i<n;i++)
#define fli(i,a,n) for(long int i=a;i<n;i++)
#define flli(i,a,n) for(long long int i=a;i<n;i++)
#define pb(n) push_back(n)
#define ppf() pop_front()
#define pii pair<int,int>
#define MOD 1000000007

#define debug1(x) cout<<x<<"\n"
#define debug2(x,y) cout<<x<<" "<<y<<"\n"
#define debug3(x,y,z) cout<<x<<" "<<y<<" "<<z<<"\n"
#define debug4(x,y,z,w) cout<<x<<" "<<y<<" "<<z<<" "<<w<<"\n"

using namespace std;

bool prime[3000000];
vector <int> pr;

void sieve() 
{ 
    memset(prime, true, sizeof(prime)); 
    lli n = 3000000;
    for (lli p=2; p*p<=n; p++) 
    { 
        if (prime[p] == true) 
        { 
            for (lli i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
    for (int p=2; p<=n; p++) 
       if (prime[p]) 
          pr.pb(p); 
}
int gfact[300000];
void build()
{
    lli n=300000;
    memset(gfact,0,sizeof(gfact));
    fi(i,1,n)
    {
        if(gfact[i]==0) gfact[i]=1;
        for(int j=2*i;j<n;j+=i)
        {
            gfact[j]=i;
        }
    }
}
int cnt[3000000];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    /*freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);*/
    sieve();
    build();
    int n;cin>>n;
    memset(cnt,0,sizeof(cnt));
    int b[2*n];
    fi(i,0,2*n) {cin>>b[i];cnt[b[i]]++;}
    sort(b,b+2*n);
    bool vis[2*n];
    memset(vis,false,sizeof(vis));
    vector <int> a;
    for(int i=2*n-1;i>=0;i--)
    {
        if(cnt[b[i]]>0)
        {
            if(!prime[b[i]])
            {
                int val=gfact[b[i]];
                cnt[val]--;
                a.pb(b[i]);
                cnt[b[i]]--;
                //vis[i]=true;
            }
        }
    }
    for(int i=0;i<2*n;i++)
    {
    	//cout<<b[i]<<"\n";
    	if(cnt[b[i]]>0)
    	{
    		if(prime[b[i]])
    		{
    			//cout<<b[i]<<"\n";
    			int val=pr[b[i]-1];
    			a.pb(b[i]);
    			cnt[val]--;
    			cnt[b[i]]--;
    		}
    	}
    }
    for(int i:a) cout<<i<<" ";
    return 0;
}