#include <bits/stdc++.h>



using namespace std;



int solve()

{

    int n;

    cin >> n;



    int counter = 0;



    while (n > 1) {

        int cards = 0;

        int i = 1;

        while (n >= cards) {

            cards = (3 * (i * i) + i) / 2;

            i++;

        }



        counter++;

        i -= 2;

        n -= (3 * (i * i) + i) / 2;

    }



    cout << counter << "\n";





    return 0;

}



int main()

{

    ios::sync_with_stdio(0);

    cin.tie(0);

    

    int t;

    cin >> t;



    for (int i = 0; i < t; i++) {

        solve();

    }

}