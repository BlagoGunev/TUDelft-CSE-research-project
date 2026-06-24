#include <bits/stdc++.h>
using namespace std;


int isprime(int n){
    int i = 2;
    while (i * i <= n){
        if (n % i == 0) return 1;
        i++;
    }
    return 0;
}

int main()
{
    std::ios::sync_with_stdio(false);
    int n;
    cin >> n;
    if(n == 1 || n == 2){
        cout << 1;
    } else{
        cout << 2;
    }
    cout << "\n";
    for(int i = 2; i <= n + 1; ++i){
        cout << isprime(i) + 1 << " ";
    }
}