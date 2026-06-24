#include <bits/stdc++.h>



using namespace std;



int main()

{

    int n, p, k;

    cin>> n >> p >> k;

    if(p - k > 1){

        cout << "<< ";

    }

    for(int i = max(p - k, 1); i <= min(p + k, n); i++){

        if(i == p){

            cout << '(';

        }

        cout << i;

        if(i == p){

            cout << ')';

        }

        cout << ' ';

    }

    if(p + k < n){

        cout << ">>";

    }

    cout << endl;

    return 0;

}