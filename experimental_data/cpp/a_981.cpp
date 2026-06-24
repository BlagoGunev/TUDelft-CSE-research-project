#include <bits/stdc++.h>
#define LL long long
using namespace std;

const int P = 313;
const int M = 1e4 + 7;

LL hshOne[52];
LL hshTwo[52];
LL pot[52];

string str;
int n, k;

LL mod(LL a){
    LL ret = a%M;
    if(ret < 0) ret += M;
    return ret;

}
void calc(){
    pot[0] = 1;
    pot[1] = P;
    for(int i = 2; i <= 51; i++)
        pot[i] = mod( pot[i-1] * P );
}

bool pal(int q){
    LL h1 = hshOne[q];
    LL h2 = mod( hshTwo[1] - hshTwo[q+1] );
    h2 = mod(h2 * pot[n - q]);
    return (h1 == h2);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> str;
    n = str.size();
    str = '#' + str;
    calc();

    for(int i = 1; i <= n; i++){
        hshOne[i] = mod( str[i] * pot[n - i + 1] );
        hshOne[i] = mod( hshOne[i-1] + hshOne[i] );
    }
    for(int i = n; i > 0; i--){
        hshTwo[i] = mod( str[i] * pot[i] );
        hshTwo[i] = mod( hshTwo[i+1] + hshTwo[i] );
    }

    for(int i = n; i > 0; i--){
        if(pal(i) == 0){
            cout << i << "\n";
            return 0;
        }
    }

    cout << "0\n";
}