#include<bits/stdc++.h>

using namespace std;



const int N = 1e3 + 5;



int n , m;

int a[N][N][3] , ans[N][N];

int cur[5] , pos[5];



void solve()

{

    cin >> n >> m;

    for (int i = 1 ; i <= n ; ++i)

    {

        for (int j = 1 ; j <= n ; ++j)

        {

            cin >> a[i][j][2];

            a[i][j][0] = i;

            a[i][j][1] = j;

        }

    }



    cur[0] = 0 , cur[1] = 0 , cur[2] = 0;

    pos[0] = 0 , pos[1] = 1 , pos[2] = 2;    

    while(m--)

    {

        char opt;

        cin >> opt;



        if (opt == 'R') cur[1] = (cur[1] + 1) % n;

        if (opt == 'L') cur[1] = (cur[1] - 1 + n) % n;

        if (opt == 'U') cur[0] = (cur[0] - 1 + n) % n;

        if (opt == 'D') cur[0] = (cur[0] + 1) % n;



        if (opt == 'I')

        {

            swap(pos[1] , pos[2]);

            swap(cur[1] , cur[2]);

        }



        if (opt == 'C')

        {

            swap(pos[0] , pos[2]);

            swap(cur[0] , cur[2]);

        }

    }



    for (int i = 1 ; i <= n ; ++i)

    {

        for (int j = 1 ; j <= n ; ++j)

        {

            int x = (a[i][j][pos[0]] + cur[0] - 1) % n + 1;

            int y = (a[i][j][pos[1]] + cur[1] - 1) % n + 1;

            int v = (a[i][j][pos[2]] + cur[2] - 1) % n + 1;

            ans[x][y] = v;

        }

    }



    for (int i = 1 ; i <= n ; ++i)

    {

        for (int j = 1 ; j <= n ; ++j)

        {

            cout << ans[i][j] << " ";

        }

        cout << "\n";

    }

}



int main()

{

    // freopen(".inp","r",stdin);

    // freopen(".out","w",stdout);

    ios_base::sync_with_stdio(0);

    cin.tie(0);

    cout.tie(0);



    int T;

    cin >> T;

    while(T--)

    {

        solve();

    }

}