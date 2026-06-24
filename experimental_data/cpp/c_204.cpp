#include <bits/stdc++.h>

using namespace std;



long long inf = 1e9;



int main()

{

    //freopen("inp.in", "r", stdin);

    std::ios::sync_with_stdio(false);

    int n;

    cin >> n;

    long long noemer=0;

    for(long long i=1; i<=n; i++)

    {

        noemer += (n+1-i)*(n+1-i);

    }



    string s1, s2;

    cin >> s1;

    cin >> s2;

    double ans = 0.0;

    long long teller=0;

    for(char ch = 'A'; ch <= 'Z'; ch++)

    {

        long long x, y, z;

        x=0;

        y=0;

        z=0;

        for(int i=n-1; i>=0; i--)

        {

            if(s2[i]==ch)

            {

                z += n-i;

            }

        }

        x=z;

        if(s1[0]==ch)

        {

            if(teller >= inf)

            {

                ans += 1.0*teller/noemer;

                teller=0;

            }

            teller += x;

        }

        for(int i=1; i<n; i++)

        {

            if(s2[i-1]==ch)

            {

                y += i;

                z -= (n+1-i);

            }

            long long now = x-y+z;

            if(s1[i]==ch)

            {

                if(teller >= inf)

                {

                    ans += 1.0*teller/noemer;

                    teller=0;

                }

                teller += now;

            }

            x=now;

        }

    }

    ans += 1.0*teller/noemer;

    cout << fixed << setprecision(12) << ans << endl;

	return 0;

}