#include <bits/stdc++.h>

/**

 _      _          _          _ _ _ _     _        _     _ _ _ _   _     _      __              __         _________

|_|    |_|       |_|_|       |_|_|_|_|   |_|     ||_|   |_|_|_|_| |_|   |_|    |__|            |__|       |_|_|_|_|_|

 |_|  |_|       |_| |_|      |_|_ _ _    |_|   |_||_|   |_|_ _ _   |_|_|_|    |_||_|          |_||_|      |_|     |_|

  |_||_|       |_|   |_|     |_|_|_|_|   |_|  |_| |_|   |_|_|_|_|   |___|    |_|  |_|        |_|  |_|     |_|     |_|

 |_|  |_|     |_|_____|_|    |_|   |_|   |_| |_|  |_|   |_|   |_|    |_|    |_|    |_|      |_|    |_|    |_|     |_|

|_|    |_|   |_|_|_|_|_|_|   |_|   |_|   |_||_|   |_|   |_|   |_|    |_|   |_|      |_|    |_|      |_|   |_|     |_|

|_|    |_|  |_|         |_|  |_|_|_|_|   |_||     |_|   |_|_|_|_|    |_|  |_|        |_|  |_|        |_|  |_|_|_|_|_|



**/



#define ll long long

#define ld long double

#define ok cout << "YES\n";

#define no cout << "NO\n";

#define kor(i, x, y, k) for(i = x; i < y; i+=k)



ll i, j;

using namespace std;



void vivod(){

    ll n, c0, c1, h, a0 = 0, a1 = 0;

    cin >> n >> c0 >> c1 >> h;

    string s;

    cin >> s;

    for(ll i=0;i<n;i++){

        a0 += s[i] == '0';

        a1 += s[i] == '1';

    }

    if(c0 < c1 && h + c0 < c1){

        cout << c0 * n + a1 * h << endl;

        return;

    }

    if(c0 > c1 && h + c1 < c0){

        cout << c1 * n + a0 * h << endl;

        return;

    }

    cout << c0 * a0 + c1 * a1 << endl;

}



int main(){

    ll n = 1;

    cin >> n;

    while(n--)vivod();

    return 0;

}