#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int MOD = 1e9 + 7;



int main()

{

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    cout.tie(NULL);



    ll t;

    cin >> t;

    while (t--)

    {

        bool ans = true;

        ll n;

        cin >> n;

        vector<ll> nums(n);

        for (ll i = 0; i < n; i++)

        {

            cin >> nums[i];

        }

        

        vector<ll> lcmVect(n+1);

        lcmVect[0] = nums[0];

        lcmVect[n] = nums[n-1];

        for (ll i = 1; i <= n-1; i++)

        {

            lcmVect[i] = lcm(nums[i-1], nums[i]);

        }

        for (ll i = 0; i < n; i++)

        {

            if(__gcd(lcmVect[i], lcmVect[i+1]) != nums[i])

            {

                ans = false;

                break;

            }

        }

        cout << ((ans)? "YES" : "NO") << endl;

    }



    return 0;

}