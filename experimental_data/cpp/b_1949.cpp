#include <bits/stdc++.h>
using namespace std;
/* Abhi-Atg */
#define ll long long
#define mod 1000000007
#define INDIA 1000000007
 


int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ll t=1;
    cin >> t;
    while(t--){
        int n;cin >> n;
        vector<int> a(n),b(n);
        for(int i=0;i<n;i++)cin >> a[i];
        for(int i=0;i<n;i++)cin >> b[i];
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        int ans=0;
        for(int i=0;i<n;i++){
            int res=INT_MAX;
            for(int j=0;j<n;j++){
                res=min(res,abs(a[j]-b[(j+i)%n]));
            }
            ans=max(ans,res);
        }
        cout<<ans<<"\n";
    }       



    return 0;
}