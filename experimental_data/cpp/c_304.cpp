#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <limits>
#include <string>
#include <functional>
#include <algorithm>
using namespace std;

typedef long long ll;
#define MOD 1000000007

int main(void)
{
    std::ios_base::sync_with_stdio(false);

    int n, i;
    cin >> n;

    if(n%2==0)
        cout << "-1";
    else{
        for(i=0; i<n; ++i)
            cout << i << " ";
        cout << endl;
        for(i=0; i<n; ++i)
            cout << (i+1)%n << " ";
        cout << endl;
        for(i=0; i<n; ++i)
            cout << (2*i+1)%n << " ";
    }

    return 0;
}