#include <cstdio>

#include <cstdlib>

#include <bits/stdc++.h>



/// Constants

#define ll long long

#define MOD 1000000007

#define EPS 1e-7

#define INF 2000000007

#define LINF 9000000000000000007



/// Definitions

#define pb push_back

#define mp make_pair

#define mem(a,b) memset(a,b,sizeof(a))

#define READ(f) freopen(f, "r", stdin)

#define WRITE(f) freopen(f, "w", stdout)

#define in(n) scanf("%d",&n)

#define out(n) printf("%d",n)

#define ios std::ios::sync_with_stdio(false);



using namespace std;



int n, arr[2001], bigTarget = -1;

vector < pair<int, int> > vec;

bool validGiven = false, before = false;



int main()

{

    scanf("%d", &n);

    for (int i = 0; i < n; i++)

    {

        int x;

        scanf("%d", &x);

        arr[x]++;

        if (arr[x] > 2)

            validGiven = true, bigTarget = x;

        else if (arr[x] == 2)

        {

            if (before)

                validGiven = true;

            before = true;

        }

        vec.pb(mp(x, i+1));

    }



    if (!validGiven)

    {

        cout << "NO";

        return 0;

    }

    cout << "YES" << endl;

    sort(vec.begin(), vec.end());

    if (bigTarget != -1)

    {

        for (int i = 0; i < n; i++)

            cout << vec[i].second << " ";

        cout << endl;

        bool done = false;

        for (int i = 0; i < n; i++)

        {

            if (vec[i].first == bigTarget && !done)

            {

                cout << vec[i+1].second << " " << vec[i].second << " ";

                i++, done = true;

            }

            else

                cout << vec[i].second << " ";

        }

        cout << endl;

        done = false;

        for (int i = 0; i < n; i++)

        {

            if (vec[i].first == bigTarget && !done)

            {

                cout << vec[i].second << " " << vec[i+2].second << " " << vec[i+1].second << " ";

                i+=2, done = true;

            }

            else

                cout << vec[i].second << " ";

        }

    }

    else

    {

        for (int i = 0; i < n; i++)

            cout << vec[i].second << " ";

        cout << endl;

        bool f = false;

        int used = -1;

        for (int i = 0; i < n; i++)

        {

            if (vec[i+1].first == vec[i].first && !f)

            {

                cout << vec[i+1].second << " " << vec[i].second << " ";

                i++, f = true;

                used = vec[i].first;

            }

            else

                cout << vec[i].second << " ";

        }

        cout << endl;

        f = false;

        for (int i = 0; i < n; i++)

        {

            if (vec[i+1].first == vec[i].first && !f && vec[i].first != used)

            {

                cout << vec[i+1].second << " " << vec[i].second << " ";

                i++, f = true;

                used = vec[i].first;

            }

            else

                cout << vec[i].second << " ";

        }

    }

    /// That's all folks.

    return 0;

}