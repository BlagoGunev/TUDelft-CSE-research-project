#include <bits/stdc++.h>

using namespace std;



typedef long long ll;



const int N = 4e5 + 8;



int T, n, a[N], cnt[N];

ll px[N], ans;



int main(){

    ios::sync_with_stdio(0), cin.tie(0);

    cin >> T;

    while (T --) {

        cin >> n;

        for (int i = 0; i < n; i ++)

            cin >> a[i];



        cnt[0]++;



        for (int i = 0; i < n; i ++) {

            px[i + 1] = px[i] ^ a[i];

                

            int res = i + 1;



            for (int j = 0; j * j <= N; j ++)

                if ((px[i + 1] ^ (j * j)) < N)

                    res -= cnt[px[i + 1] ^ (j * j)];

            

            ans += res;



            cnt[px[i + 1]]++;

        }



        cout << ans << '\n';



        ans = 0;

        for (int i = 0; i <= n; i ++)

            cnt[px[i]] = 0, a[i] = 0;

        for (int i = 0; i <= n; i ++)

            px[i] = 0;

    }

    return 0;

}