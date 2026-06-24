#include <bits/stdc++.h>



using namespace std;



bool triangle(long long x)

{



    long long root = (int)sqrtl(x);

    if (root * (root + 1) == x)

        return true;



    return false;

}



void yes()

{

    cout << "YES";

    exit(0);

}



int main()

{



    long long n; cin >> n;

    for (int a = 1; a <= (int)sqrtl(n); a ++)

        if (a * (a + 1) < 2 * n)

            if (triangle(2 * n - a * (a + 1)))

                yes();



    cout << "NO";

}