#include <bits/stdc++.h>



using namespace std;

typedef long long ll;



int main()

{

    ios::sync_with_stdio(0);

    cin.tie(0);

    int t;

    cin >> t;

    while(t--)

    {

        int n;

        cin >> n;

        vector<array<int,2>> v(n);

        for(int i=0;i<n;i++)

        {

            cin >> v[i][0];

            v[i][1]=i+1;

        }

        ranges::sort(v);

        cout << n << "\n";

        int b=1;

        for(auto [a,i]:v)

        {

            cout << i << " " << b-(a%b) << "\n";

            b=a+(b-(a%b));

        }

    }

    return 0;

}