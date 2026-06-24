#include <iostream>
using namespace std;
int main() {
    int t, a[] = {3,1,4,1,5,9,2,6,5,3,5,8,9,7,9,3,2,3,8,4,6,2,6,4,3,3,8,3,2,7,9,5,0,2,8,8,4,1,9,7,1};
    cin >> t;
    for (int i = 0; i < t; i++) {
        int x = 1, y;
        while (a[i]--) {
            cin >> y;
            x *= y;
        }
        cout << x << endl;
    }
}