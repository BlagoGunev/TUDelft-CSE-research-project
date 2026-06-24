#include <bits/stdc++.h>



using namespace std;



void A() {

    int T;

    cin >> T;

    while (T--) {

        int N, R, B;

        cin >> N >> R >> B;

        assert(N == R + B);

        assert(R > B);

        int u = R / (B + 1);

        int cnt1 = R % (B + 1), cnt2 = B + 1 - cnt1;

        for (int i = 0; i <= B; i++) {

            if (cnt1 > 0) {

                for (int j = 0; j < u + 1; j++)

                    cout << "R";

                cnt1--;

            }

            else if (cnt2 > 0) {

                for (int j = 0; j < u; j++)

                    cout << "R";

                cnt2--;

            }

            if (i < B)

                cout << "B";

        }

        cout << "\n";

    }

}



void B() {

    int T;

    cin >> T;

    while (T--) {

        int N, K;

        cin >> N >> K;

        string S;

        cin >> S;

        vector<int> change(N);

        int hv = K;

        for (int i = 0; i < N - 1; i++) {

            if (S[i] == '1' && K % 2 == 0) {

                S[i] = '1';

                continue;

            }

            if (S[i] == '1' && K % 2 == 1 && hv > 0) {

                change[i] = 1;

                S[i] = '1';

                hv--;

                continue;

            }

            if (S[i] == '0' && K % 2 == 1) {

                S[i] = '1';

                continue;

            }

            if (S[i] == '0' && K % 2 == 0 && hv > 0) {

                change[i] = 1;

                S[i] = '1';

                hv--;

                continue;

            }

            else {

                S[i] = '0';

            }

        }

        change[N - 1] = hv;

        if (change[N - 1] % 2 != K % 2 && S[N - 1] == '0') {

            S[N - 1] = '1';

        }

        else if (change[N - 1] % 2 == K % 2 && S[N - 1] == '1') {

            S[N - 1] = '1';

        }

        else {

            S[N - 1] = '0';

        }

        cout << S << "\n";

        for (auto it : change) {

            cout << it << " ";

        }

        cout << "\n";

    }

}



int main() {

    ios_base::sync_with_stdio(false);

    cin.tie(nullptr);

    // A();

    B();

    return 0;

}