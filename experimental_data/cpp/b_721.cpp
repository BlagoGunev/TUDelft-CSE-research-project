#include <bits/stdc++.h>



using namespace std;



typedef long long ll;

typedef double dou;

typedef string str;



int n, k;

vector<int> a;



int main()

{

    cin >> n >> k;

    str s;

    for (int i = 0; i < n; ++i)

    {

        cin >> s;

        a.push_back(s.size());

    }

    cin >> s;

    int cnt1 = count(a.begin(), a.end(), s.size());

    sort(a.begin(), a.end());

    int cnt2 = 0;

    for (int i = 0; i < n; ++i)

        if (a[i] < s.size())

            cnt2++;

        else

            break;

    cnt1 += cnt2;

    cout << cnt2 + (cnt2 / k) * 5 + 1 << ' ';

    cout << cnt1 + (cnt1 - 1) / k * 5;

    return 0;

}