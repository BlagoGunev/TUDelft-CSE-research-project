#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        for (int i = 0; i < n; i++){
            cout << "()";
        }
        cout << '\n';
        if (n == 1){
            continue;
        }
        n--;
        int t =n-1;
        int i = n; int j = n - i + 1;
        while (t--){
            int ii = i ;int jj = j;
            while (ii--){
                cout << '(';
            }
            ii = i;
            while (ii--){
                cout << ')';
            }
            while (jj--){
                cout << "()";
            }
            i--;j++;
            cout << '\n';
        }
        for (int m = 0; m <= n; m++){
            cout << '(';
        }
        for (int m = 0; m <= n; m++){
            cout << ')';
        }cout << '\n';


    }
    return 0;
}