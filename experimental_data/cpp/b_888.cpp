#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;


int main() {
    int n,
            L = 0,
            D = 0,
            U = 0,
            R = 0;
    int k = 0;
    cin >> n;
    string a;
    cin >> a;
    for(int i = 0; i < n; i++){
        if(a[i] == 'L'){
            L++;
        }
        if(a[i] == 'U'){
            U++;
        }
        if(a[i] == 'D'){
            D++;
        }
        if(a[i] == 'R'){
            R++;
        }
    }

    k = 2*(abs(min(U, D))) + 2*(abs(min(L, R)));
    cout << k;
    return 0;
}