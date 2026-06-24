#include <bits/stdc++.h>



using namespace std;



typedef long long ll;



int main()

{

    ll cnt1, cnt2, x, y;

    cin >> cnt1 >> cnt2 >> x >> y;



    ll hi = 1e16, lo = 0;



    while (hi != lo) {

        ll mid = (hi + lo) >> 1LL;

        ll cx = mid - (mid/x);

        ll cy = mid - (mid/y);

        ll cxy = mid - (mid/x/y);



        if (cnt1 > cx || cnt2 > cy || cnt1 + cnt2 > cxy)

            lo = mid + 1;

        else

            hi = mid;

    }



    cout << hi;

    return 0;

}