#include <bits/stdc++.h>

#define loop(x,n) for(int x = 0; x < n; ++x)

#define ll long long



using namespace std;





int main(){

    int t, k = 1, num = 1, inp;

    cin >> t;

    int arr[1001] = {0};

    while (k <= 1000) {

        if (num % 3 == 0 || num % 10 == 3) {

            num++;

        }

        else {

            arr[k] = num;

            k++;num++;

        }



    }

    loop(i, t) {

        cin >> inp;

        cout << arr[inp] << endl;

    }

    return 0;

}