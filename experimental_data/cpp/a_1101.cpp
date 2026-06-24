// Example program
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    int q;
    cin >> q;
    
    int l[q], r[q], d[q], a[q];
    for (int i=0; i<q; i++) {
        cin >> l[i] >> r[i] >> d[i];
    }
    
    for (int i=0; i<q; i++) {
        if (d[i] < l[i]) {
            a[i] = d[i];
        } else {
            int j = r[i]+1;
            if ((j % d[i]) == 0) {
                a[i] = j;
            } else {
                a[i] = j + d[i] - (j % d[i]);
            }
        }
    }
    
    for (int i=0; i<q; i++) {
        cout << a[i] << endl;
    }
    return 0;
}