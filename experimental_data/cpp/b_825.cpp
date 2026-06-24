//#define _GLIBCXX_DEBUG
#include <stdio.h>
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

vector<string> board(10);

inline bool valid(int i, int j) {
    return i >= 0 && i < 10 && j >= 0 && j < 10;
}

bool check(int i, int j) {
    if (valid(i + 4, j) && board[i + 1][j] == 'X' && board[i + 2][j] == 'X' && board[i + 3][j] == 'X' && board[i + 4][j] == 'X')
        return true;
    if (valid(i, j + 4) && board[i][j + 1] == 'X' && board[i][j + 2] == 'X' && board[i][j + 3] == 'X' && board[i][j + 4] == 'X')
        return true;

    if(valid(i + 4, j - 4) && board[i + 1][j - 1] == 'X' && board[i + 2][j - 2] == 'X' && board[i + 3][j - 3] == 'X' && board[i + 4][j - 4] == 'X')
        return true;
    if(valid(i + 4, j + 4) && board[i + 1][j + 1] == 'X' && board[i + 2][j + 2] == 'X' && board[i + 3][j + 3] == 'X' && board[i + 4][j + 4] == 'X')
        return true;
    return false;
}

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
    //    freopen("out", "w", stdout);
#endif
    ios::sync_with_stdio(false), cin.tie(nullptr);
    for (int i = 0; i < 10; i++) {
        cin >> board[i];
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (board[i][j] == '.') {
                board[i][j] = 'X';

                for (int x = 0; x < 10; x++)
                    for (int y = 0; y < 10; y++)
                        if (board[x][y] == 'X')
                            if (check(x, y)) {
                                cout << "YES\n";
                                return 0;
                            }

                board[i][j] = '.';
            }
        }
    }

    cout << "NO\n";

    return 0;
}