#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<string>
#define int long long
using namespace std;
int T, n;
// bool check(){
    
// }
int arr[105];
signed main(){
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i){
            cin >> arr[i];
        }
        if (n & 1){
            cout << 4 << "\n";
            cout << 1 << " " << n - 1 << "\n";
            cout << 1 << " " << n - 1 << "\n";
            cout << n - 1 << " " << n << "\n";
            cout << n - 1 << " " << n << "\n";
        }
        else{
            cout << 2 << "\n";
            cout << 1 << " " << n << "\n";
            cout << 1 << " " << n << "\n";
        }
        cout << "\n";
    }
    return 0;
}