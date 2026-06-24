#include <bits/stdc++.h>

#define ll long long

#define pb push_back

#define MOD 1000000007

#define MAX 1005



using namespace std;



struct A

{

    int ind1, ind2;

    char x, y;

};



int main()

{

    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    map < string, vector < int > > h;

    string s;

    vector < A > R;

    int TT, n, i, r;



    cin >> TT;

    while(TT--)

    {

        cin >> n, h.clear(), R.clear();

        for(i = 1; i <= n; i++)

        {

            cin >> s;

            sort(s.begin(), s.end()), s[0] -= 32, s[1] -= 32, s[2] -= 32;

            if(s != "INW") h[s].pb(i);

        }



        while(h["WWW"].empty() == 0 && h["NNN"].empty() == 0)

        {

            int x = h["WWW"].back(), y = h["NNN"].back();

            R.pb({x, y, 'w', 'n'});

            h["NWW"].pb(x), h["NNW"].pb(y);

            h["WWW"].pop_back(), h["NNN"].pop_back();

        }

        while(h["WWW"].empty() == 0 && h["III"].empty() == 0)

        {

            int x = h["WWW"].back(), y = h["III"].back();

            R.pb({x, y, 'w', 'i'});

            h["IWW"].pb(x), h["IIW"].pb(y);

            h["WWW"].pop_back(), h["III"].pop_back();

        }

        while(h["NNN"].empty() == 0 && h["III"].empty() == 0)

        {

            int x = h["NNN"].back(), y = h["III"].back();

            R.pb({x, y, 'n', 'i'});

            h["INN"].pb(x), h["IIN"].pb(y);

            h["NNN"].pop_back(), h["III"].pop_back();

        }

        bool ok = 1;

        while(ok == 1)

        {

            ok = 0;

            while(h["WWW"].empty() == 0 && h["INN"].empty() == 0)

            {

                int x = h["WWW"].back(), y = h["INN"].back();

                R.pb({x, y, 'w', 'n'});

                h["NWW"].pb(x);

                h["WWW"].pop_back(), h["INN"].pop_back();

                ok = 1;

            }

            while(h["WWW"].empty() == 0 && h["IIN"].empty() == 0)

            {

                int x = h["WWW"].back(), y = h["IIN"].back();

                R.pb({x, y, 'w', 'i'});

                h["IWW"].pb(x);

                h["WWW"].pop_back(), h["IIN"].pop_back();

                ok = 1;

            }

            while(h["NNN"].empty() == 0 && h["IWW"].empty() == 0)

            {

                int x = h["NNN"].back(), y = h["IWW"].back();

                R.pb({x, y, 'n', 'w'});

                h["NNW"].pb(x);

                h["NNN"].pop_back(), h["IWW"].pop_back();

                ok = 1;

            }

            while(h["NNN"].empty() == 0 && h["IIW"].empty() == 0)

            {

                int x = h["NNN"].back(), y = h["IIW"].back();

                R.pb({x, y, 'n', 'i'});

                h["INN"].pb(x);

                h["NNN"].pop_back(), h["IIW"].pop_back();

                ok = 1;

            }

            while(h["III"].empty() == 0 && h["NWW"].empty() == 0)

            {

                int x = h["III"].back(), y = h["NWW"].back();

                R.pb({x, y, 'i', 'w'});

                h["IIW"].pb(x);

                h["III"].pop_back(), h["NWW"].pop_back();

                ok = 1;

            }

            while(h["III"].empty() == 0 && h["NNW"].empty() == 0)

            {

                int x = h["III"].back(), y = h["NNW"].back();

                R.pb({x, y, 'i', 'n'});

                h["IIN"].pb(x);

                h["III"].pop_back(), h["NNW"].pop_back();

                ok = 1;

            }



            while(h["NWW"].empty() == 0 && h["IIN"].empty() == 0)

            {

                int x = h["NWW"].back(), y = h["IIN"].back();

                R.pb({x, y, 'w', 'i'});

                h["NWW"].pop_back(), h["IIN"].pop_back();

                ok = 1;

            }

            while(h["NNW"].empty() == 0 && h["IIW"].empty() == 0)

            {

                int x = h["NNW"].back(), y = h["IIW"].back();

                R.pb({x, y, 'n', 'i'});

                h["NNW"].pop_back(), h["IIW"].pop_back();

                ok = 1;

            }

            while(h["IWW"].empty() == 0 && h["INN"].empty() == 0)

            {

                int x = h["IWW"].back(), y = h["INN"].back();

                R.pb({x, y, 'w', 'n'});

                h["IWW"].pop_back(), h["INN"].pop_back();

                ok = 1;

            }



            if(ok == 0)

            {

                while(h["NWW"].empty() == 0 && h["IIW"].empty() == 0)

                {

                    int x = h["NWW"].back(), y = h["IIW"].back();

                    R.pb({x, y, 'w', 'i'});

                    h["IWW"].pb(y);

                    h["NWW"].pop_back(), h["IIW"].pop_back();

                    ok = 1;

                }

                while(h["IWW"].empty() == 0 && h["NNW"].empty() == 0)

                {

                    int x = h["IWW"].back(), y = h["NNW"].back();

                    R.pb({x, y, 'w', 'n'});

                    h["NWW"].pb(y);

                    h["IWW"].pop_back(), h["NNW"].pop_back();

                    ok = 1;

                }

            }

        }





        cout << R.size() << '\n';

        for(auto it:R) cout << it.ind1 << ' ' << it.x << ' ' << it.ind2 << ' ' << it.y << '\n';



    }



    return 0;

}