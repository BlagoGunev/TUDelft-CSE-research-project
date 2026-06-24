#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    double tmp = sqrt(n);
    double tmp2 = tmp - (int)tmp;
//    cout << tmp2 << endl;
//    cout << (int)tmp << endl;
//    cout << ceil(tmp) << endl;
    if(tmp == (int)tmp) cout << 4 * sqrt(n) << "\n";
    else if(tmp2 >= .5000) cout << 2 * (int)tmp + 2 * ((int)tmp + 1) + 2 << "\n";
    else cout << 2 * (int)tmp + 2 * ((int)tmp + 1) << "\n";
    return 0;
}