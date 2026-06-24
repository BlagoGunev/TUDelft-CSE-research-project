#include <vector>
#include <list>
#include <map>
#include <set>
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
#include <cstring>
#include <ctime>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define sz(c) (c).size()
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define tr(c, x) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define present(c, x) ((c).find(x) != (c).end())
#define cpresent(c, x) (find(all(c), x) != (c).end())
#define REP(i, n) for(int i = 0; i < (n); i++)
#define REPD(i, n) for(int i = (n)-1; i >= 0; i--)
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORD(i, a, b) for(int i = (a); i >= (b); i--)

int main(){
    int n, k;
    cin >> n >> k;
    if(n == k){
        cout << -1;
        return 0;
    }
    int swaps = n-k;
    if(swaps%2 == 0){
        for(int i = 1; i <= swaps/2; i++)
            cout << 2*i << " " << 2*i-1 << " ";
        for(int i = swaps+1; i <= n; i++)
            cout << i << " ";
    }else{
        cout << swaps << " ";
        for(int i = 1; i <= n; i++)
            if(i != swaps)
                cout << i << " ";
    }
    return 0;
}