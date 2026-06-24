#include <iostream>

#include <algorithm>

#include <stdio.h>

#include <set>

#include <string.h>

#include <string>

#include <vector>

#include <unordered_map>

#include <queue>

#include <iomanip>

#include <fstream>

#include <map>



using namespace std;

typedef vector<int> vi;

typedef pair<int,int> ii;

typedef long long ll;

typedef long double ld;

typedef pair<double,double> dd;

typedef pair<ll, ll> l4;

typedef vector<ii> vii;

int n,m;

char g[410][410];

int row[410][410];

int col[410][410];

int dig1[810][410];

int dig2[810][410];

int main() {

    scanf("%d%d",&n,&m);

    for (int i = 1; i <= n; i++) {

        scanf("%s",&g[i][1]);

    }

    // int t = max(n,m);

    for (int i = 1; i <= n; i++) {

        for (int j = 1; j <= m; j++) {

            row[i][j] = row[i][j-1]+g[i][j]-'0';

            dig1[i-j+m][i] = dig1[i-j+m][i-1]+g[i][j]-'0';

            dig2[i+j][i] = dig2[i+j][i-1]+g[i][j]-'0';

            col[j][i] = col[j][i-1]+g[i][j]-'0';

        }

    }

    ll ans = 0;

    for (int i = 1; i <= n; i++) {

        for (int j = 1; j <= m; j++) {

            if (g[i][j] == '1') continue;

            for (int k = 1; k < min(n,m); k++) {

                if (i-k>=1 && j-k>=1 && row[i][j]-row[i][j-k-1]==0 && col[j][i]-col[j][i-k-1]==0) {

                    if (dig2[i+j-k][i]-dig2[i+j-k][i-k-1] == 0) ans++;         

                } else {

                    break;

                }

            }

            for (int k = 1; k < min(n,m); k++) {

                if (i-k>=1 && j+k<=m && row[i][j+k]-row[i][j-1]==0 && col[j][i]-col[j][i-k-1]==0) {

                    if (dig1[i-j-k+m][i]-dig1[i-j-k+m][i-k-1] == 0) ans++;                    

                } else {

                    break;

                }

            }

            for (int k = 1; k < min(n,m); k++) {

                if (i+k<=n && j-k>=1 && row[i][j]-row[i][j-k-1]==0 && col[j][i+k]-col[j][i-1]==0) {

                    if (dig1[i-j+k+m][i+k]-dig1[i-j+k+m][i-1] == 0) ans++;                    

                } else {

                    break;

                }

            }

            for (int k = 1; k < min(n,m); k++) {

                if (i+k<=n && j+k<=m && row[i][j+k]-row[i][j-1]==0 && col[j][i+k]-col[j][i-1]==0) {

                    if (dig2[i+j+k][i+k]-dig2[i+j+k][i-1] == 0) ans++;                    

                } else {

                    break;

                }

            }

            for (int k = 1; k < min(n,m); k++) {

                if (i-k>=1 && j+k<=m && j-k>=1 && dig1[i-j+m][i]-dig1[i-j+m][i-k-1]==0 && dig2[i+j][i]-dig2[i+j][i-k-1]==0) {

                    if (row[i-k][j+k]-row[i-k][j-k-1] == 0) ans++;                    

                } else {

                    break;

                }

            }

            for (int k = 1; k < min(n,m); k++) {

                if (i+k<=n && i-k>=1 && j+k<=m && dig1[i-j+m][i+k]-dig1[i-j+m][i-1]==0 && dig2[i+j][i]-dig2[i+j][i-k-1]==0) {

                    if (col[j+k][i+k]-col[j+k][i-k-1] == 0) ans++;                    

                } else {

                    break;

                }

            }

            for (int k = 1; k < min(n,m); k++) {

                if (i+k<=n && j+k<=m && j-k>=1 && dig1[i-j+m][i+k]-dig1[i-j+m][i-1]==0 && dig2[i+j][i+k]-dig2[i+j][i-1]==0) {

                    if (row[i+k][j+k]-row[i+k][j-k-1] == 0) ans++;                    

                } else {

                    break;

                }

            }

            for (int k = 1; k < min(n,m); k++) {

                if (i-k>=1 && i+k<=n && j-k>=1 && dig1[i-j+m][i]-dig1[i-j+m][i-k-1]==0 && dig2[i+j][i+k]-dig2[i+j][i-1]==0) {

                    if (col[j-k][i+k]-col[j-k][i-k-1] == 0) ans++;                    

                } else {

                    break;

                }

            }

        }

    }

    cout << ans;

    return 0;

}