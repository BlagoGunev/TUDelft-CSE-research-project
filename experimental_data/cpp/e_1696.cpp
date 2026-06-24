#include<bits/stdc++.h>

#define ll long long int

using namespace std;

int gcdExtended(int a, int b, int* x, int* y);

int modInverse(int a, int m)

{

    int x, y;

    int g = gcdExtended(a, m, &x, &y);

    int res = (x % m + m) % m;

    return res;

}

int gcdExtended(int a, int b, int* x, int* y)

{

    if (a == 0)

    {

        *x = 0, *y = 1;

        return b;

    }

    int x1, y1;

    int gcd = gcdExtended(b % a, a, &x1, &y1);

    *x = y1 - (b / a) * x1;

    *y = x1;

    return gcd;

}

int main(){

ios_base::sync_with_stdio(false);

cin.tie(NULL);

cout.tie(NULL);

ll T, N;

ll M = 1000000007;

T = 1;

while(T--){

cin >> N;

ll x;

ll Sum = 0, Num1 = 0, Num2 = 0, Num = 0;

cin >> x;

if(x != 0){Sum += x;}

cin >> x;

if(x != 0){

    Sum += ((x+1)*(x))/2;

    Sum %= M;

}

Num1 = x+1;

Num2 = 2;

Num = (((x+1)*(x))/2)%M;

for(int aa = 2; aa < N+1; aa++){

    cin >> x;

    if(x == 0){continue;}

    for(int bb = Num1; bb >= x+aa; bb--){

    Num *= (Num1-Num2);

    Num %= M;

    Num *= modInverse(Num1, M);

    Num %= M;

    Num1 --;

    }

    Num *= Num1+1;

    Num %= M;

    Num *= modInverse(Num2+1, M);

    Num %= M;

    Sum += Num;

    Sum %= M;

    Num2 ++;

    Num1 ++;

}cout << Sum << endl;

}

return 0;

}