#include <iostream>

#include <algorithm>



using namespace std;



int main() {

    ios_base::sync_with_stdio(false);

    cin.tie(nullptr);

    cout.tie(nullptr);



    int setsTotal;

    cin >> setsTotal;



    for (int setIndex = 1; setIndex <= setsTotal; setIndex++) {

        int n, k;

        cin >> n >> k;



        string s;

        cin >> s;



        bool isPossible = true;

        for (int i = 0; i < k; i++) {

            bool has0 = false;

            bool has1 = false;

            bool hasq = false;

            int j = i;

            while (j < s.size()) {

                has0 |= s[j] == '0';

                has1 |= s[j] == '1';

                hasq |= s[j] == '?';

                j += k;

            }

            if (has0 && has1) {

                isPossible = false;

                break;

            }

            char needChar;

            if (has0)

                needChar = '0';

            else if (has1)

                needChar = '1';

            else

                needChar = '?';

            j = i;

            while (j < s.size()) {

                s[j] = needChar;

                j += k;

            }

        }



        int n1 = count(begin(s), begin(s) + k, '1');

        int n0 = count(begin(s), begin(s) + k, '0');

        isPossible &= (k / 2 - n1 >= 0) && (k / 2 - n0 >= 0);



        cout << (isPossible ? "YES" : "NO") << '\n';

    }



    return 0;

}