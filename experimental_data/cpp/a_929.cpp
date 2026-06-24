#include<bits/stdc++.h>
#define loop(i,a,b) for(int i=a;i<b;i++)
#define loopb(i,a,b) for(int i=a;i>=b;i--)
#define loopm(i,a,b,step) for(int i=a;i<b;i+=step)
#define loopbm(i,a,b,step) for(int i=a;i>=b;i-=step)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define init(arr,val) memset(arr,val,sizeof(arr))
#define INF 1000000007
#define MOD 1000000007
#define BINF 1000000000000000001
#define int long long int
#define double long double

using namespace std;

#undef int
int main()
{
#define int long long int
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,k;
    cin>>n>>k;
    int x[n];
    loop(i,0,n)
     cin>>x[i];
    int dist[n];
    int ncycles=1;
    int flag=0;
    int curr=0;
    int left=k;
    loop(i,0,n-1){
     dist[i]=x[i+1]-x[i];
     if(dist[i]>k) flag=1;
    }
    if(flag) cout<<-1;
    else{
        while(curr<n-1)
        {
            if(dist[curr]<=left)
            {
                left-=dist[curr];
                curr++;
            }
            else
            {
                ncycles++;
                left=k-dist[curr];
                curr++;
            }
        }
        
        cout<<ncycles;
    }
    
    
    
   
    
    return 0;
}