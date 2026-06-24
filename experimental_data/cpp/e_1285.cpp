#include <iostream>

#include <set>

#include <algorithm>

using namespace std;



typedef pair<int, int> pii;

const int N = 2 * 100 * 1000 +10;



pii seg[N];

int dp_last, dp, big, cmp;



void Solve()

{

    int n; cin>>n;

    for(int i=1; i<=n; i++)

        cin>>seg[i].first>>seg[i].second;

    sort(seg+1, seg+n+1);



    /// Base

    set<pii> s;

    s.insert({seg[1].second, 1});

    cmp = big = 1;

    dp = -1;

    dp_last = 0;



    /// Solve

    for(int i=2; i<=n; i++)

    {

        if(seg[i].second <= seg[big].second)

        {

            if(i == 2)

                dp = 1;

            s.erase({seg[big].second, big});

            dp_last += (s.empty() || s.rbegin() -> first < seg[i].first);

            s.insert({seg[big].second, big});

        }

        else if(seg[big].second < seg[i].first)

        {

            dp = max(dp, dp_last) + 1;

            dp_last = cmp ++;

            big = i;

        }

        else

        {

            /// DP LAST

            int new_dp_last = cmp;



            /// DP

            int dp1 = dp, dp2 = dp_last;

            s.erase({seg[big].second, big});

            dp2 += (s.empty() || s.rbegin() -> first < seg[i].first);

            s.insert({seg[big].second, big});



            /// UPD

            dp_last = new_dp_last;

            dp = max(dp1, dp2);

            big = i;

        }

        s.insert({seg[i].second, i});

    }

    cout<<max(dp, dp_last)<<'\n';

}



int main()

{

    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t; cin>>t;

    while(t --)

        Solve();

    return 0;

}