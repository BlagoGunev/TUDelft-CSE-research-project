//B: 
#include<bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define all(x) x.begin(), x.end()
#define loop(i, a, b) for(int i = a; i < b; i++)
using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;

int t, a, b;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin >> t;
    while(t--) {
        cin >> a >> b;
        if(a < b) {
            swap(a, b);
        }
        if(b < (a / 2)) {
            cout << "NO\n";
        } else if((a + b) % 3 == 0) {
           cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}