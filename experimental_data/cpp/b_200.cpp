#include <iostream>

#include <string>

#include <cstdio>

#include <map>

using namespace std;



long long sum1,sum2;

int main()

{

    cout.precision(6);

    cout.setf(std::ios::fixed);

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    

    int n;

    cin >> n;

    

    sum1 = n * 100;

    

    for(int i = 1; i <= n; i++)

    {

        int t;

        cin >> t;

        sum2 += t;    

    }

    

    double ans = (double(sum2)/(double)(sum1))*100;

    cout << ans;

    return 0;   

}