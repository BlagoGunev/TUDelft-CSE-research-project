#include <iostream>

#include <iomanip>

#include <vector>

#include <algorithm>

#include <cmath>

#include <stack>

#include <queue>

#include <set>

#include <map>

#include <numeric>



using namespace std;



#define int long long

#define double long double

#define pii pair<int, int>



#define JODSPEED ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(15);



const int MAX = 105;

const int INF = 1e18;

const int MOD = 998244353;

int n, m, k;

char B[MAX][MAX];



bool in_bounds(int x, int y) {

    return x >= 0 && x < n && y >= 0 && y < m;

}



void fill_board() {

    for(int i = 0; i < n; i++) {

        for(int j = 0; j < m; j++) {

            if(B[i][j] == '*') {

                set<char> occ;

                if(in_bounds(i, j-1)) { occ.insert(B[i][j-1]); }

                if(in_bounds(i-1, j)) { occ.insert(B[i-1][j]); }

                if(in_bounds(i, j+1)) { occ.insert(B[i][j+1]); }

                if(in_bounds(i+1, j-1)) { occ.insert(B[i+1][j-1]); }

                if(in_bounds(i+1, j+1)) { occ.insert(B[i+1][j+1]); }

                if(in_bounds(i+2, j)) { occ.insert(B[i+2][j]); }



                for(int k = 0; k < 7; k++) {

                    if(occ.find('a' + k) == occ.end()) {

                        B[i][j] = 'a' + k;

                        B[i+1][j] = 'a' + k;

                        break;

                    }

                }

            }

            else if(B[i][j] == '.') {

                set<char> occ;

                if(in_bounds(i, j-1)) { occ.insert(B[i][j-1]); }

                if(in_bounds(i-1, j)) { occ.insert(B[i-1][j]); }

                if(in_bounds(i+1, j)) { occ.insert(B[i+1][j]); }

                if(in_bounds(i+1, j+1)) { occ.insert(B[i+1][j+1]); }

                if(in_bounds(i-1, j+1)) { occ.insert(B[i-1][j+1]); }

                if(in_bounds(i, j+2)) { occ.insert(B[i][j+2]); }



                for(int k = 0; k < 7; k++) {

                    if(occ.find('a' + k) == occ.end()) {

                        B[i][j] = 'a' + k;

                        B[i][j+1] = 'a' + k;

                        break;

                    }

                }

            }

        }

    }

}



signed main() {

    JODSPEED;

    int T;

    cin >> T;

    while(T--) {

        bool flag = false;

        cin >> n >> m >> k;

        for(int i = 0; i < n; i++) {

            for(int j = 0; j < m; j++) {

                B[i][j] = '*';

            }

        }

        if((n % 2) == 1) {

            k -= (m >> 1);

            if(k < 0) { flag = true; }

            else if((k % 2) == 1) { flag = true; }

            else {

                for(int i = 0; i < m; i++) {

                    B[0][i] = '.';

                }

                for(int i = 1; i < n && k > 0; i += 2) {

                    for(int j = 0; j < m && k > 0; j += 2) {

                        B[i][j] = '.';

                        B[i][j+1] = '.';

                        B[i+1][j] = '.';

                        B[i+1][j+1] = '.';

                        k -= 2;

                    }

                }

            }

        }

        else if((m % 2) == 1) {

            if((k % 2) == 1) { flag = true; }

            else if(k > ((n * m) >> 1) - (n >> 1)) { flag = true; }

            else {

                for(int i = 0; i < n && k > 0; i += 2) {

                    for(int j = 0; j < (m-1) && k > 0; j += 2) {

                        B[i][j] = '.';

                        B[i][j+1] = '.';

                        B[i+1][j] = '.';

                        B[i+1][j+1] = '.';

                        k -= 2;

                    }

                }

            }

        }

        else {

            if((k % 2) == 1) { flag = true; }

            for(int i = 0; i < n && k > 0; i += 2) {

                for(int j = 0; j < m && k > 0; j += 2) {

                    B[i][j] = '.';

                    B[i][j+1] = '.';

                    B[i+1][j] = '.';

                    B[i+1][j+1] = '.';

                    k -= 2;

                }

            }

        }



        if(flag) {

            cout << "NO" << endl;

        }

        else {

            fill_board();

            cout << "YES" << endl;

            for(int i = 0; i < n; i++) {

                for(int j = 0; j < m; j++)  {

                    cout << B[i][j];

                }

                cout << endl;

            }

        }

    }



    return 0;

}