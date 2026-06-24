#include <map>

#include <set>

#include <queue>

#include <stack>

#include <deque>

#include <cmath>

#include <vector>

#include <sstream>

#include <cstring>

#include <iostream>

#include <algorithm>

#include <unordered_map>

#include <unordered_set>



using namespace std;



const int N = 5e5 + 10, mod = 1e9 + 7, maxv = 1e7, INF = 0x3f3f3f3f, P = 131;



#define int long long

// unsigned

#define x first

#define y second

#define pb push_back

#define PII pair<int, int>

#define INF 0x3f3f3f3f

#define lowbit(x) (x & (-x))

#define mem(a, b) memset((a), (b), sizeof(a))

#define io ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)

#define NO cout << "NO" << endl

#define YES cout << "YES" << endl



int qmi(int a, int b, int p)

{

    a %= p;

    int res = 1;

    while (b)

    {

        if (b & 1)

            res = (res * a) % p;

        a = (a * a) % p;

        b >>= 1;

    }

    return res;

}



bool cmp(int aaa, int bbb)

{

    return aaa > bbb;

}



int n, m;

vector<int> v[N], ans[N];

int pos[N];



void print(vector<int> ans)

{

    YES;

    for (int i = 1; i < ans.size(); i++)

    {

        if (ans[i] == -1)

            cout << 1 << " ";

        else

            cout << ans[i] << " ";

    }

}



bool check(vector<int> &ans)

{

    

    for (int i = 1; i <= n; i++)

    {

        int cnt = 0, p = -1;

        for (int j = 1; j <= m; j++)

        {

            if (ans[j] != v[i][j])

                cnt++;

            if (ans[j] == -1)

                p = j;

        }



        if (cnt > 3)

        {

            return false;

        }

        else if(cnt == 3)

        {



            if (p != -1)

                ans[p] = v[i][p];

            else

            {

                return false;

            }

        }

    }

    return true;

}



void solve()

{

    cin >> n >> m;

    for (int i = 1; i <= n; i++)

        v[i].pb(0);



    for (int i = 1; i <= n; i++)

    {

        for (int j = 1; j <= m; j++)

        {

            int x;

            cin >> x;

            v[i].pb(x);

        }

    }



    int flag = 0, p = 0;

    for (int i = 2; i <= n; i++)

    {

        int k = 0;

        for (int j = 1; j <= m; j++)

            if (v[1][j] != v[i][j])

                pos[k++] = j;

        if (flag < k)

            p = i, flag = k;

    }



    if (flag <= 2)

    {

        YES;

        for (int i = 1; i <= m; i++)

            cout << v[1][i] << " ";

        return;

    }

    else if (flag > 4)

    {

        NO;

        return;

    }



    int k = 0;

    for (int i = 1; i <= m; i++)

    {

        if (v[1][i] != v[p][i])

            pos[k++] = i;

    }



    for (int i = 0; i < flag; i++)

        for (int j = i + 1; j < flag; j++)

        {

            vector<int> ans;

            ans = v[p];



            ans[pos[i]] = v[1][pos[i]], ans[pos[j]] = -1;

           

            if (check(ans))

            {

                print(ans);

                return;

            }

            ans = v[p];

            ans[pos[i]] = -1, ans[pos[j]] = v[1][pos[j]];

            if (check(ans))

            {

                print(ans);

                return;

            } // print(ans);

        }

    NO;

}



signed main()

{

    io;

    int T;

    T = 1;

    // cin >> T;

    while (T--)

        solve();

    return 0;

}