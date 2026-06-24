#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int k;
    cin >> k;
    int A, maxi = 0;
    for (int i = 0; i < k; i++) {
        cin >> A;
        if (A > maxi)
            maxi = A;
    }
    cout << max(0, maxi - 25);
}