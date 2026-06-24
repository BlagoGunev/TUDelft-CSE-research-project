#include <bits/stdc++.h>



using namespace std;



int main() {

    ios_base::sync_with_stdio(0);



    long long a, b, n, sqr, newa, newb, enough = 1e18, tota, totb;



    cin >> n >> a >> b;



    if(a * b >= 6 * n){

        cout << a * b << endl;

        cout << a << " " << b << endl;

    } else {

        bool sw = 0;

        n *= 6;

        if(a > b){

            swap(a, b);

            sw = 1;

        }

        for(newa = a; newa * newa <= n; newa += 1){

            newb = n / newa;

            if(newb * newa < n){

                newb ++;

            }

            if(newb >= b){

                if(newa * newb < enough){

                    enough = newa * newb;

                    tota = newa;

                    totb = newb;

                }

            }

        }

        if(sw){

            swap(tota, totb);

        }

        cout << enough << endl << tota << " " << totb << endl;

    }



    return 0;

}