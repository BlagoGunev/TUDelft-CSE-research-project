#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int main()
{
    
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        ll n,k;
        ll cnt=0;
        ll i,j=1;
        cin>>n>>k;
        
        
        while(cnt<k)
        {
            cnt+=j;
            j++;
        }
        j--;
        cnt-=j;
        k-=cnt;
        for(i=1;i<=n;i++)
        {
            if(i == n-k+1)
                cout<<'b';
            else if(i == n-j)
                cout<<'b';
            else
                cout<<'a';
        }
        cout<<"\n";
    }
 
}