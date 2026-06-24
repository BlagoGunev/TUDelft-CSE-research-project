#include <iostream>
#include <cmath>
#include <set>
#include <map>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <string.h>
#include <fstream>
#include <iomanip>
#include <valarray>
#include <typeinfo>
#include <sstream>
#include <bitset>
using namespace std;





int main() {
    int t = 1;
    cin >> t;
    for (int tt = 0; tt < t; tt++) {
        int a, b;
        cin >> a >> b;
        if (a % 2 == 0) {
            if (a == 0 && b % 2 == 1) {
                cout << "NO" << endl;
            } else {
                cout << "YES" << endl;
            }
        } else {
            cout << "NO" << endl;
        }
    }
}