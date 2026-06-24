#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<queue>
#include<cstdio>
#include<cmath>
#include<string>
#include<set>
#include<complex>
#include<cstdio>
#include<cstring>
#include<stack>
#include<iomanip>
#include<bitset>
#include<typeinfo>
#include<random>
#include<unordered_map>
#include<unordered_set>

using namespace std;

int t;
int a, b, c;

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d %d %d", &a, &b, &c);
        int ans = 0;
        while(b >= 1 && c >= 2){
            ans += 3;
            b--;
            c -= 2;
        }
        while(a >= 1 && b >= 2){
            ans += 3;
            a--;
            b -= 2;
        }
        printf("%d\n", ans);
    }
    return 0;
}