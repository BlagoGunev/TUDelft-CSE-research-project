#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;

int val(char c)
{
    if (c == '-')
        return 0;
    if (c == 'M')
        return 1;
    if (c == 'C')
        return 2;

    assert(false);
}

bool check(vector<int> freq)
{

    freq[0 + 3 * 0] = 0;
    freq[1 + 3 * 0] = 0;
    freq[2 + 3 * 0] = 0;
    freq[1 + 3 * 1] = 0;
    freq[2 + 3 * 2] = 0;

    bool ok = true;
    for (auto v : freq)
        if (v != 0)
            ok = false;

    return ok;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    const int PICKUP = 0;
    const int DROPOFF = 1;
    const int DRIVE = 2;

    int n;
    cin >> n;

    string a, b;
    cin >> a >> b;

    vector<int> freq(9);
    vector<vector<int>> where(9);

    for (int i = 0; i < n; ++i)
    {
        int u = val(a[i]);
        int v = val(b[i]);
        int id = u * 3 + v;
        freq[id]++;
        where[id].push_back(i + 1);
    }


    for (int s = 1; s <= 2; ++s)
    {
        for (int e = 1; e <= 2; ++e)
        {

            auto n_freq = freq;
            auto n_where = where;
            vector<pair<int, int>> path;

            auto get = [&](int id)
            {
                int u = n_where[id].back();
                n_freq[id]--;
                n_where[id].pop_back();
                return u;
            };

            auto drive = [&](int s)
            {
                path.push_back({DRIVE, get(s)});
            };

            auto pickup = [&]()
            {
                path.push_back({PICKUP, -1});
            };

            auto dropoff = [&]()
            {
                path.push_back({DROPOFF, -1});
            };

            auto greedy = [&]()
            {
                for (int x = 1; x <= 2; ++x)
                {
                    int y = 3 - x;
                    int tot = min(n_freq[x], n_freq[y + x * 3]);

                    for (int i = 0; i < tot; ++i)
                    {
                        drive(x);
                        pickup();
                        drive(y + x * 3);
                        dropoff();

                        if (n_freq[3 * y] >= 1)
                        {
                            pickup();
                            drive(3 * y);
                            dropoff();
                        }
                    }
                }

                for (int x = 1; x <= 2; ++x)
                {
                    int tot = min(n_freq[x], n_freq[3 * x]);

                    for (int i = 0; i < tot; ++i)
                    {
                        drive(x);
                        pickup();
                        drive(3 * x);
                        dropoff();
                    }
                }

                if (check(n_freq))
                {
                    cout << path.size() << endl;

                    for (auto [type, id] : path)
                    {
                        if (type == PICKUP)
                            cout << "PICKUP" << endl;
                        else if (type == DROPOFF)
                            cout << "DROPOFF" << endl;
                        else
                            cout << "DRIVE " << id << endl;
                    }

                    exit(0);
                }
            };

            if (s == e)
            {
                int x = 3 - s;
                int tot = min({1, n_freq[s], n_freq[x + s * 3], n_freq[s + x * 3]});

                bool debug = s == 2 && e == 2;

                if (tot == 1)
                {
                    drive(s);
                    pickup();
                    drive(x + s * 3);
                    dropoff();
                    pickup();
                    drive(s + x * 3);
                    dropoff();

                    int tot = min(n_freq[s + x * 3], n_freq[x + s * 3]);
                    for (int i = 0; i <= tot; ++i)
                    {
                        auto c_freq = n_freq;
                        auto c_where = n_where;
                        auto c_path = path;

                        if (n_freq[3 * s] >= 1)
                        {
                            pickup();
                            drive(3 * s);
                            dropoff();
                        }

                        greedy();

                        n_freq = c_freq;
                        n_where = c_where;
                        path = c_path;

                        pickup();
                        drive(x + s * 3);
                        dropoff();
                        pickup();
                        drive(s + x * 3);
                        dropoff();
                    }
                }
                else
                {
                    greedy();
                }
            }
            else
            {
                int tot = min({1, n_freq[s], n_freq[e + s * 3]});

                if (tot == 1)
                {
                    drive(s);
                    pickup();
                    drive(e + s * 3);
                    dropoff();

                    int tot = min(n_freq[s + e * 3], n_freq[e + s * 3]);

                    for (int i = 0; i <= tot; ++i)
                    {
                        auto c_freq = n_freq;
                        auto c_where = n_where;
                        auto c_path = path;

                        if (n_freq[3 * e] >= 1)
                        {
                            pickup();
                            drive(3 * e);
                            dropoff();
                        }

                        greedy();

                        n_freq = c_freq;
                        n_where = c_where;
                        path = c_path;

                        pickup();
                        drive(s + e * 3);
                        dropoff();
                        pickup();
                        drive(e + s * 3);
                        dropoff();

                    }

                }
                else
                {
                    greedy();
                }

            }

        }
    }

    assert(check(freq));
    cout << 0 << endl;

    return 0;
}