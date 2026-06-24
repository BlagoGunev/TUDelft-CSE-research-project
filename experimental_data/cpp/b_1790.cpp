#include<bits/stdc++.h>



using namespace std;

#define IO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)

#define ll long long

#define ld long double

const int N = 2e5 +5;





int main() {



    IO;



    int t;

    cin>>t;

    while(t--)

    {

        int n, s, r;

        cin>>n>>s>>r;

        int cnt = r%(n-1), mx = s-r;

        for (int i = 0; i < n-1; i++)

        {

            if (cnt)

            {

                int cur = min(r/(n-1) + cnt, mx);

                cnt -= (cur- (r/(n-1)));

                cout<<cur<<' ';

            }

            else

                cout<<r/(n-1)<<' ';

        }

        cout<<mx<<'\n';

    }



}