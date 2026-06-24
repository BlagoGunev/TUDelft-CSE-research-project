#include <bits/stdc++.h>
using namespace std;

long long n,m;
vector<int>v;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin>>t;
    while(t > 0)
    {
        cin>>n>>m;

        long long xr = n ^ m;
        if(xr < n)
        {
            cout<<"1\n";
            //cout<<xr<<"\n";
            cout<<n<<" "<<m<<"\n";
        }
        else
        {
            /*int ministo = 63;
            int br11 = 0;
            for(int i = 63;i>=0;i--)
            {
                if((1ll << i) & m == (1ll < i) & n)
                {
                    if((1ll << i) & m)
                    {
                        br11++;
                    }
                    ministo = i;
                }
                else
                {
                    break;
                }
            }*/

            int maxbit = 0;
            for(int i = 0; i < 63;i++)
            {
                if((1ll << i) & m)
                {
                    maxbit = i;
                }
            }

            long long levo = 0;
            v.clear();
            for(int i=maxbit+1;i<63;i++)
            {
                if((1ll << i) & n)
                {
                    levo += (1ll << i);
                    v.push_back(i);
                }
            }

            if(v.size()==1)
            {
                cout<<"-1\n";
            }
            else
            {
                long long br1 = (1ll << v[0]) + ((n - levo) ^ m);
                long long br2 = levo - (1ll << v[0]);
                cout<<"2\n";
                cout<<n<<" "<<(n ^ br1)<<" "<<((n ^ br1) ^ br2)<<"\n";
            }
        }

        t--;
    }
    return 0;
}