#include <iostream>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string path;
        cin >> path;

        int coins = 0;
        for(int i = 0; i < n; ++i) {
            if(path[i] == '@') {
                coins++;
            }
            // Check if we've hit two or more consecutive thorns
            if(i < n-1 && path[i] == '*' && path[i+1] == '*') {
                break;
            }
        }

        cout << coins << endl;
    }
    return 0;
}