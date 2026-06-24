#include <bits/stdc++.h>

using namespace std;

bool valid(int *mass)
{
    bool r(true);
    int d(mass[0]), m(mass[1]), y(mass[2]);
    if (m > 12) r = false;
    if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) if (d > 31) r = false;
    if (m == 2) if (d > 28 + (y % 4 ? 0 : 1)) r = false;
    if (m == 4 || m == 6 || m == 9 || m == 11) if (d > 30) r = false;
    return r;
}

bool ans(int *m1, int *m2)
{
    if (m2[2] > m1[2] + 18) return true;
    else if (m2[2] == m1[2] + 18)
    {
        if (m2[1] > m1[1] || (m2[1] == m1[1] && m2[0] >= m1[0])) return true;
        return false;
    }
    return false;
}

int main()
{
    int contest[3], birth[3];
    char c;
    cin >> contest[0] >> c >> contest[1] >> c >> contest[2];
    cin >> birth[0] >> c >> birth[1] >> c >> birth[2];
    sort(birth, birth + 3);
    bool go(true);
    while (go)
    {
        if (valid(birth) && ans(birth, contest))
        {
            cout << "YES";
            return 0;
        }
        go = next_permutation(birth, birth + 3);
    }
    cout << "NO";
    return 0;
}