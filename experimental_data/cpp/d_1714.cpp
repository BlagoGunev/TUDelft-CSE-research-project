#include<bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int kmp[121];

int l[111];

int r[111];

int dp[111];

int pre[111];

int main(){

    ios_base::sync_with_stdio(0);cin.tie(nullptr);cout.tie(nullptr);

    int q;

    cin>>q;

    while (q--){

        string t;

        string s;

        int n;

        cin>>t>>n;

        for (int i = 0;i < t.size();i ++){

            l[i] = INF;

            dp[i] = INF;

        }

        for (int i = 1;i <= n;i ++){

            cin>>s;

            int bruh = s.size();

            s += "&" + t;

            kmp[0] = 0;

            for (int j = 1;j < s.size();j ++){

                int cur = j - 1;

                while (cur != -1 && s[kmp[cur]] != s[j]){

                    cur = kmp[cur] - 1;

                }

                if (cur == -1)kmp[j] = 0;

                else kmp[j] = kmp[cur] + 1;

            }

            /*for (int j = 0;j < s.size();j ++){

                cout<<kmp[j]<<' ';

            }

            cout<<'\n';*/

            for (int j = 0;j < t.size();j++){

                int cur = kmp[j + bruh + 1];

                //cout<<cur<<' ';

                if (cur == bruh){

                    if (l[j] > j - cur){

                        l[j] = j - cur;

                        r[j] = i;

                    }

                }

            }

            //cout<<'\n';

        }

        for (int i = 0;i < t.size();i ++){

            if (l[i] == -1){

                dp[i] = 1;

                pre[i] = -1;

            }

            else{

                for (int j = l[i];j < i;j ++){

                    if (dp[j] < dp[i]){

                        dp[i] = dp[j];

                        pre[i] = j;

                    }

                }

                dp[i]++;

            }

        }

        if (dp[t.size() - 1] < INF){

            cout<<dp[t.size() - 1]<<'\n';

            int cur = t.size() - 1;

            while (cur != -1){

                cout<<r[cur]<<' '<<l[cur]+2<<'\n';

                if (cur == 0)break;

                cur = pre[cur];

            }

        }

        else{

            cout<<-1<<'\n';

        }

    }

    return 0;

}