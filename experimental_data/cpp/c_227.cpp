#include <iostream>



using namespace std;



long long modPow(long long b, long long e, long long m) {

    long long ans = 1;

    while (e) {

        if (e & 1) {

            ans = (ans * b) % m;

        }

        b = (b * b) % m;

        e >>= 1;

    }

    return ans;

}



int main() {

    std::ios::sync_with_stdio(false);

    

    long long N, M;



    cin >> N >> M;

    

    cout << (modPow(3, N, M) + M - 1) % M << endl;

    

    return 0;

}