#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define prec(x)    \
    cout << fixed; \
    cout.precision(x);
#define mp make_pair
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<int, ll> pil;
typedef pair<ll, ll> pll;

int a[101010];
void SolveProblem() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int j = 1;
    for (int i = 1; i <= n; i++) {
        while (a[j] < i - j + 1) j++;
        cout << i - j + 1 << ' ';
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case = 1;
    cin >> test_case;
    for (int tc = 1; tc <= test_case; tc++) {
        // cout << "Case #" << tc << ": ";
        SolveProblem();
    }
}