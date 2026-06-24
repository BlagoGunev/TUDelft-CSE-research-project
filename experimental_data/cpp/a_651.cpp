#include <bits/stdc++.h>



using namespace std;



int n , m , ans = 0;

int main(){

    cin >> n >> m;

    if(n == 1 && m == 1){

        cout << 0;

        return 0;

    }

    while(n > 0 && m > 0){

        if(n < m){

            n++;

            m -= 2;

        }else{

            m++;

            n -= 2;

        }

        ans++;

    }

    cout << ans;

    return 0;

}