#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;



int main(int argc, const char * argv[])
{

    // insert code here...
    int n;
    cin >> n;
    
    int wires[n];
    
    for (int i = 0; i < n; ++i) {
        cin >> wires[i];
    }
    
    
    int m ;
    cin >> m;
    
    vector<pair<int, int> > shots;
    int a , b;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        shots.push_back(make_pair(a, b));
    }
    
    for (int i = 0; i < m; ++i) {
        int ith = shots[i].first -1;
        int poshot = shots[i].second ;
        
        int right = wires[ith] - poshot;
        int left  = poshot -1;
        wires[ith] = 0;
        
        if (ith >  0) {
            wires[ith - 1]+= left;
            
        }
        if (ith < (n-1)) {
            wires[ith +1]+= right;
        }
        
        
    }
    
    for (int i = 0; i < n; ++i) {
        cout << wires[i] << endl;
    }
    return 0;
}