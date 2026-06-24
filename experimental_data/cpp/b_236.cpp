#include <iostream>

using namespace std;

int ans[1000001];

long long divisors(int num) {
    if(ans[num] != 0)
        return ans[num];
    long long res = 1;
    int x, n = num;
    for(int i=2; i*i<=n; ++i)
        if(n%i==0) {
            x = 0;
            while(n%i==0) { 
                n /= i;
                ++x;
            }
            res *= x+1;
        }
    if(n!=1) {
        res *= 2;
    }
    ans[num] = res;
    return res;
}

int solve(int a, int b, int c) {
    long long sum = 0;
    for(int i=1; i<=a; ++i) {
        for(int j=1; j<=b; ++j) {
            for(int k=1; k<=c; ++k) {
                sum = (sum + divisors(i*j*k)) % 1073741824LL;
            }
        }
    }
    return sum;
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    cout << solve(a, b, c) << endl;
    return 0;
}