#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
    ios_base::sync_with_stdio(false);
#ifdef IN_FILE
    ifstream in_file(argv[1]);
    auto sbuf = cin.rdbuf(in_file.rdbuf());
#endif

    string cf("CODEFORCES"), s;
    cin >> s;
    int i = 0, l1 = cf.length(), l2 = s.length(), j1 = l1 - 1, j2 = l2 - 1;
    while (i < l1 && i < l2 && cf[i] == s[i]) {
        ++i;
    }

    while (j1 >= 0 && j2 >= 0 && cf[j1] == s[j2]) {
        --j1, --j2;
    }

    cout << (i > j1? "YES" : "NO") << endl;

#ifdef IN_FILE
    cin.rdbuf(sbuf);
    in_file.close();
#endif

    return 0;
}