#include <cstdio>
#include <iostream>
using namespace std;

int base;

string conv(int k) {
    string ans;
    while(k) {
        ans = (char)(k%base + '0') + ans;
        k /= base;
    }
    return ans;
}

int main() {
    cin >> base;
    for(int i = 1; i < base; i++) {
        for(int j = 1; j < base; j++) {
            if(i == 1) cout << j << " ";
            else {
                if(j == 1) cout << j*i << " ";
                else {
                    cout << conv(i*j) << " ";
                }
            }
        }
        cout << endl;
    }
    return 0;
}