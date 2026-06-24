#include <bits/stdc++.h>
using namespace std ;
#define read freopen("input.txt", "r", stdin);
#define write freopen("output5.txt", "w", stdout);
#define ll long long
#define ld long double
#define fast  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
int main ()
{
    fast
    bool f= true;
    int t;
    cin>>t;
    while (t--) {
        int n;
        cin >> n;
        if (n == 1 || n == 2)
            cout << n << '\n';

        else if (n % 3 == 0) {
            n = n / 3;
            while (n--) {
                cout << "21";
            }
            cout << '\n';
        } else if (n % 3 == 1) {
            n = n / 3;
            while (n--) {
                cout << "12";
            }
            cout << "1" << '\n';
        } else {
            n = n / 3;
            while (n--) {
                cout << "21";
            }
            cout << "2" << '\n';
        }


    }





    return 0;
}