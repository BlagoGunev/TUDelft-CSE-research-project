#include <iostream>



using namespace std;



int main()

{

    long long n, a, b, c;

    cin >> n >> a >> b >> c;

    if(a <= b-c)

    {

        cout << n/a;

        return 0;

    }

    long long ans = ((n-b)/(b-c))+1;

    if(n < b)

        ans = 0;

    ans += (n - ans*b + ans*c)/a;

    cout << ans;

}