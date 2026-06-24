#include <iostream>

#include <string>



const int SIZE = 2000; 





int main() {



    int t, n, a, odd_count;

    std::cin >> t;

    std::string arr[SIZE];

    std::string s;

    bool has_even, has_odd;

    int temp[300];

    

    for (int i = 0; i < t; i++) {

        std::cin >> n;

        odd_count = 0;

        bool has_even = false, has_odd = false;

        arr[i] = "NO";



        for (int j = 0; j < n; j++) {

            std::cin >> a;



            if (a % 2 == 0) {

                has_even = true;

            } else {

                has_odd = true;

                odd_count++;

            }

        }



        if (has_even && has_odd) {

            arr[i] = "YES";

            continue;

        }



        if (odd_count % 2 == 1) {

            arr[i] = "YES";

        }

    }



    for (int i = 0; i < t; i++) 

        std::cout << arr[i] << "\n";



    return 0;

}