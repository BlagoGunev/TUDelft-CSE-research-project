#include <bits/stdc++.h>



using namespace std;



int main() {



    int t;



    cin >> t;



    while (t--) {



        vector <int> odds , evens;



        int n;



        cin >> n;



        for (int i = 0 ; i < n ; i++) {



            int a;



            cin >> a;



            if (a % 2)



                odds.push_back(a);



            else



                evens.push_back(a);



        }



        for (auto a: odds)



            cout << a << " ";



        for (auto a: evens)



            cout << a << " ";



        cout << endl;



    }



    return 0;

}