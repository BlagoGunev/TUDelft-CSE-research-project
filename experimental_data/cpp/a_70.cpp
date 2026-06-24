#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <list>
#include <bitset>
#include <queue>
#include <stack>
#include <cmath>
#include <valarray>
#include <ctime>
#include <set>


using namespace std;

typedef pair<double, double> PDD;
typedef pair<int, int> PII;
typedef unsigned long long ULL;

int solve(int n){
    int res = 1;
    for(int i=1; i<n; i++){
        res*=3;
        res %= 1000000 + 3;
    }

    return res;
}

int main(){
    int n;
    scanf("%i", &n);

    printf("%i", solve(n));


    return 0;
}