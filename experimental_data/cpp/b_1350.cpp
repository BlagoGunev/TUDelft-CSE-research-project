#include <iostream>

#include <map>

#include <string>

#include <vector>

#include <set>

#include <algorithm>





#define ll long long 

#define pb push_back 



using namespace std;



const int N = 200005;



ll a[N];

int c[N];

ll pref[N];

pair<ll, ll> p[N];

vector<int> g[N];





int main() {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int tt;

    cin >> tt;

    while (tt--) {

        int n;

        cin >> n;

        for (int i = 1;i <= n;i++) {

            cin >> a[i];

        }

        int mx = 0, mx1 = 0;

        for (int i = 1;i <= n;i++) {

            c[i] = max(c[i], 1);

            mx = max(mx, c[i]);

            for (int j = 2 * i;j <= n;j += i) {

                if (a[j] > a[i]) {

                    c[j] = max(c[i] + 1, c[j]);

                    mx = max(mx, c[j]);

                }

            }

        }

        cout << mx << endl;

        for (int i = 0;i <= n;i++) {

            c[i] = 0;

        }

    }

}



/*



              %%           %%         %           %%      %%            %          %%     %%

               %%         %%        %% %%         %%      %%          %% %%        %%%%   %%

                %%       %%        %%   %%        %%      %%         %%   %%       %% %%  %%

                 %%     %%        %%%%%%%%%       %%%%%%%%%%        %%%%%%%%%      %%  %% %%

                  %%   %%        %%       %%      %%      %%       %%       %%     %%   %%%%

                   %% %%        %%         %%     %%      %%      %%         %%    %%    %%%

                     %         %%           %%    %%      %%     %%           %%   %%     %%





*/