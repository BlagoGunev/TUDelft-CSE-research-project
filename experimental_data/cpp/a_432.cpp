#include <bits/stdc++.h>

#define pb push_back

#define mp make_pair

using namespace std;

typedef long long ll;

typedef pair <int,int> pii;



int32_t main()

{

    ios_base::sync_with_stdio(false); cin.tie(0);

    int n,k;

    cin >> n >> k;

    int res = 0;

    for (int i = 0 ; i < n ; i++)

    {

        int a;

        cin >> a;

        if (a + k <= 5)

            res++;

    }

    cout << res / 3 << endl;

    return 0;

}