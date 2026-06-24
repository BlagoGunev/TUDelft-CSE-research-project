#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define TIME ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

const ll oo = 1e18, N = 1e9 + 1;

int t, n;

int main(){

    TIME

    cin >> t;

    while(t--){

        cin >> n;

        int a[n]{};

        for (int i = 0; i < n; i++){

            cin >> a[i];

        }

        ll sum(0), mn(INT_MAX);

        for (int i = 0; i < n; i++){

            sum += a[i];

            ll current(0), counter(0), mx(0);

            for (int j = 0; j < n; j++){

                current += a[j];

                counter++;

                if(current == sum){

                    mx = max(mx, counter);

                    current = 0;

                    counter = 0;

                }

                else if(current > sum)  break;

                // cout <<"i : " << i << ' ' << current <<  ' ' << counter << '\n';

            }

            if(!current)    mn = min(mn, mx);

        }

        cout << mn << '\n';

    }

}