#include <iostream>



using namespace std;



int main()

{

    long long k,n,w;

    cin >> k >> n >> w;



    long long sum = (w*(w+1))/2;

    long long ans = (k*sum) - n;



    if(ans<=0)

        cout << 0 << endl;

    else

        cout << ans << endl;



}