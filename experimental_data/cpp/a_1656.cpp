#include <iostream>



using namespace std;



typedef long long ll;



int main()

{

    ios_base::sync_with_stdio(false);

    cin.tie(nullptr);



    int t;

    cin >> t;

    for (; t > 0; --t)

    {

        int n;

        cin >> n;

        int max_val = INT32_MIN;

        int max_ind = 1;

        int min_val = INT32_MAX;

        int min_ind = 1;

        for (int i = 1; i <= n; ++i)

        {

            int a;

            cin >> a;

            if (a > max_val)

            {

                max_val = a;

                max_ind = i;

            }

            if (a < min_val)

            {

                min_val = a;

                min_ind = i;

            }

        }

        cout << min_ind << " " << max_ind << "\n";

    }



    return 0;

}