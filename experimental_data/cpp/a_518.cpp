#include <bits/stdc++.h>



using namespace std;



string s, t;



int main() {

    ios_base::sync_with_stdio(false);

    cin.tie();

    cout.tie();



    cin >> s >> t;



    int i = s.length() - 1;

    while (s[i] == 'z') {

        s[i] = 'a';



        i--;

    }

    s[i]++;



    if (s < t) {

        cout << s << '\n';

    } else {

        cout << "No such string" << '\n';

    }



    return 0;

}