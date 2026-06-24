#include <bits/stdc++.h>

using namespace std;

#define ll long long



int main()

{

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    ll t, a,b, n;

    cin >> t;

    while (t--)

    {

        cin >> n;

        vector<ll>nums(n);

        vector<ll>revme(n);

        int last;

        cin>>nums[0];

        last=nums[0];

        int isit=-1;

        for (ll i = 1; i < n; i++)

        {

            cin>>nums[i];

            if(nums[i]>=last){

                isit=1;

            }

            last=nums[i];

        }

        if(isit==-1){

            cout<<"NO"<<endl;

        }

        else{

            cout<<"YES"<<endl;

        }

    }

    return 0;

}