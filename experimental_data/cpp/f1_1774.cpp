#include<bits/stdc++.h>

using namespace std;

const int MOD = 998244353;

const int MAXVAL = 1e9 + 5;

struct query{

    int type;

    int x;

};

query a[800100];

int main(){

    ios_base::sync_with_stdio(0);cin.tie(nullptr);cout.tie(nullptr);

    int n;

    cin>>n;

    int add = 0;

    for (int i = 1;i <= n;i ++){

        cin>>a[i].type;

        if (a[i].type != 3){

            cin>>a[i].x;

            if (a[i].type == 2){

                add += a[i].x;

            }

        }

        else{

            a[i].x = add;

            add *= 2;

            //cout<<a[i].x<<'\n';

        }

        add = min(add,MAXVAL);

    }

     add = 0;

    int zero = 1;

    vector <int> moms;

    int ans = 0;

    for (int i = n;i >= 1;i --){

        if (a[i].type == 2){

            add += a[i].x;

            add = min(add,MAXVAL);

        }

        if (a[i].type == 3){

            if (a[i].x == 0){zero = (zero<<1);if(zero >= MOD)zero -= MOD;}

            else if (a[i].x < MAXVAL)moms.push_back(a[i].x);

        }

        if (a[i].type == 1){

            if (add < a[i].x){

                a[i].x -= add;

            }

            else{

                continue;

            }

            int cnt = 1 << ((int)moms.size());

            for (int j = 0;j < (int)moms.size();j ++){

                if (a[i].x > moms[j]){

                    a[i].x -= moms[j];

                }

                else{

                    cnt -= (1 << ((int)moms.size() - 1 - j));

                }

            }

            cnt = 1LL * cnt * zero % MOD;

            ans += cnt;

            if (ans >= MOD)ans -= MOD;

        }

    }

    cout<<ans<<'\n';

    return 0;

}