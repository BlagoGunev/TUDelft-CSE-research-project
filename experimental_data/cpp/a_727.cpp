#include <bits/stdc++.h>



using namespace std;



long long a, b;

vector <long long> ans;



int main() {

    #ifdef home

        freopen("1.in", "r", stdin);

        freopen("1.out", "w", stdout);

    #endif

    cin >> a >> b;

    ans.push_back(b);

    while (b > a) {

        if (b % 2 == 0) {

            ans.push_back(b / 2);

            b /= 2;

        }

        else {

            if (b % 10 == 1) {

                ans.push_back((b - 1) / 10);

                b = (b - 1) / 10;

            }

            else {

                puts("NO");

                return 0;

            }

        }

    }

    if (b != a) {

        puts("NO");

        return 0;

    }

    puts("YES");

    cout << ans.size() << endl;

    for (int i = ans.size() - 1; i >= 0; i--)

        cout << ans[i] << ' ';

    return 0;

}