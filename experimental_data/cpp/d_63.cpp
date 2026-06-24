#include <iostream>

using namespace std;

char field[111][111];

int x, y;

void go(char p)
{
    field[x][y] = p;
    if (field[x + 1][y] == '*')
        ++x;
    else if (field[x - 1][y] == '*')
        --x;
    else
        ++y;
}

int main()
{
    ios_base::sync_with_stdio(false);
    int a, b, c, d, n;
    for (int i(0); i < 111; ++i)
        for (int j(0); j < 111; ++j)
            field[i][j] = '.';
    cin >> a >> b >> c >> d >> n;
    for (int i(1); i <= b; ++i)
        for (int j(1); j <= a; ++j)
            field[i][j] = '*';
    for (int i(1); i <= d; ++i)
        for (int j(a + 1); j <= a + c; ++j)
            field[i][j] = '*';
    y = 1;
    x = a % 2 ? b : 1;
    int cur;
    char p('a' - 1);
    while (n--)
    {
        ++p;
        cin >> cur;
        while (cur--)
            go(p);
    }
    cout << "YES\n";
    for (int i(1); i <= max(b, d); ++i)
    {
        for (int j(1); j <= a + c; ++j)
            cout << field[i][j];
        cout << '\n';
    }
}