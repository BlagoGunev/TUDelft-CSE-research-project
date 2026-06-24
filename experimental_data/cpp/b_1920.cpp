#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n,k,x;
        cin>>n>>k>>x;

        vector<int> arr(n);

        for(int i=0;i<n;i++)
        cin>>arr[i];

        sort(arr.begin(),arr.end());

        vector<int> pref(n);
        pref[0]=arr[0];
        for(int i=1;i<n;i++)
        pref[i]=pref[i-1]+arr[i];

        int ans=INT_MIN;

        for(int i=0;i<=k;i++)
        {
            if(n-1-i < 0)
            ans=max(0,ans);

            else if(n-1-x-i < 0)
            {
                ans=max(ans,-pref[n-1-i]);
            }
            else
            ans=max(ans,2*pref[n-1-x-i]-pref[n-1-i]);
        }

        cout<<ans<<endl;

    }
}