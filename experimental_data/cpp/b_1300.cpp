#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        n *= 2;
        ll arr[n];
        for(ll i = 0; i < n; i++)
        {
            cin>>arr[i];
        }
        sort(arr, arr + n);
        cout<<arr[n / 2] - arr[(n / 2) - 1]<<"\n";
    }
}