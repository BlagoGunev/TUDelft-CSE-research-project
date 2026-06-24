//tonynater - CodeForces 2014

#include <algorithm>
#include <assert.h>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <complex>
#include <ctime>
#include <ctype.h>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

using namespace std;

#define sz(x) ((int) x.size())

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

const double pi = acos(-1);
const double tau = 2*pi;
const double epsilon = 1e-9;

const int S = 1000000;

int N;

bool used[S+1];

stack<int> res;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
    cin >> N;
    
    for(int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        
        used[x] = true;
    }
    
    for(int i = 1; i <= S; i++)
        if(used[i] && !used[S-i+1])
        {
            res.push(S-i+1);
            --N;
        }
    
    for(int i = 1; i <= S && N > 0; i++)
        if(!used[i] && !used[S-i+1])
        {
            res.push(i);
            res.push(S-i+1);
            
            used[i] = true;
            used[S-i+1] = true;
            N -= 2;
        }
    
    cout << sz(res) << '\n';
    while(!res.empty())
    {
        cout << res.top() << '\n';
        res.pop();
    }
    
    return 0;
}