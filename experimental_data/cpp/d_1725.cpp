#include <bits/stdc++.h>

using namespace std;

const uint64_t seed = std::chrono::system_clock::now().time_since_epoch().count();

mt19937_64 rnd(seed);

const char NL = '\n';

using LL = long long;



#ifdef VIPJML_LOCAL

#include <vipjml_debug.hpp>

#else

#define dbg(...)

#endif



void solve(int caseNum)

{

    int N, Q;

    cin >> N >> Q;



    LL sum = 0;

    LL ans = 0;

    LL cur = 0;

    int last, lastCnt;

    while (sum < N)

    {

        int cnt = (cur + 1) / 2;

        if (sum + cnt < N)

        {

            sum += cnt;

            ans += cur * cnt;

            cur++;

        }

        else

        {

            ans += cur * (N - sum);

            last = cur;

            lastCnt = N - sum;

            sum = N;

        }

    }



    cout << ans << NL;



    int fb;

    for (int i = 30; i >= 0; i--)

        if (last >> i & 1)

        {

            fb = i;

            break;

        }

    vector<int> ycnt(last + 21, 0);

    vector<int> yy(last + 1, 0);

    for (int i = 0; i <= last; i++)

    {

        LL e = last - i;

        if (i < last - (2 * lastCnt - 1))

            e--;

        yy[i] = (e + 1) / 2;

        // dbg(i, e, lastCnt, last);

        for (int j = 0; (1 << j) <= e; j++)

        {

            LL t1 = 1LL << j, t2 = min(1LL << (j + 1), e + 1);

            LL cnt = t2 / 2 - t1 / 2;

            ycnt[i + j] += max(cnt, 0LL);

        }

    }



    vector<LL> yc_sum(ycnt.size() + 1, 0);

    for (int i = 0; i < ycnt.size(); i++)

    {

        yc_sum[i + 1] = yc_sum[i] + ycnt[i];

    }

    vector<LL> syy(yy.size() + 1, 0);

    for (int i = 0; i < yy.size(); i++)

        syy[i + 1] = syy[i] + yy[i];

    // dbg(yy);

    for (int i = 0; i < Q; i++)

    {

        int p;

        cin >> p;

        int y = lower_bound(yc_sum.begin(), yc_sum.end(), p) - yc_sum.begin();

        y--;

        int xs = (1 << fb) - 1, xe = (1 << (fb + 1)) - 1;

        int ye = min(last, y);

        LL base = syy[ye + 1];

        // dbg(y, fb, xs, xe, base);

        while (xs + 1 < xe)

        {

            LL xm = (xs + xe) / 2;

            LL c = base;

            for (int j = max(0, y - 20); j <= ye; j++)

            {

                int d = j - (y - fb);

                c -= yy[j];

                if (d >= 0)

                {

                    LL a = xm >> d;

                    c += min((a + 1) / 2, (LL)yy[j]);

                }

                else

                {

                    LL a = xm << (-d);

                    c += min((a + 1) / 2, (LL)yy[j]);

                }

                // dbg(j, c);

            }

            // dbg(xm, c);

            if (c >= p)

                xe = xm;

            else

                xs = xm;

        }

        // dbg(y, fb, xe);

        int a = y - fb, x = xe;

        while (x % 2 == 0)

        {

            a++;

            x /= 2;

        }

        cout << a + x << NL;

    }

}



int main()

{

    std::ios::sync_with_stdio(false);

    cin.tie(NULL);

    cout.precision(20);

    int T = 1;

    // cin >> T;

    for (int i = 1; i <= T; i++)

    {

        solve(i);

    }

    cout.flush();

    return 0;

}