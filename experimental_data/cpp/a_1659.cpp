#include <bits/stdc++.h>

using namespace std;

#define ll long long int

#define ull unsigned long long int

#define M 1000000007

#define pb push_back

#define forn(i, n) for (int i = 0; i < n; i++)

#define all(x) x.begin(), x.end()

int main()

{

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    int t;cin>>t;

    while(t--)

    {

       int n,r,b;

       cin>>n>>r>>b;

       string s="";

        int f=r/(b+1);

        int c=r%(b+1);

        for(int i=1;i<=b+1;i++)

        {

            if(i!=b+1)

            {

                for(int j=1;j<=f;j++)

                {

                    s+='R';

                }

                if(c>0)

                {

                    s+='R';

                    c--;

                }

                s+='B';

            }

            else

            {

                for(int j=1;j<=f;j++)

                {

                    s+='R';

                }

                if(c>0)

                {

                    s+='R';

                }

            }

        }

        cout<<s<<"\n";

    }



}