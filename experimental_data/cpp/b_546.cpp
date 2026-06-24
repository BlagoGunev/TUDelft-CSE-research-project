#include <iostream>

#include <algorithm>

#include <vector>



using namespace std;



int main()

{

    int n = 0;

    int x = 0;

    int ans = 0;

    vector<int> cool;



    cin >> n;



    for (int i = 0; i < n; ++i) {

	cin >> x;

	cool.push_back(x);

    }



    sort(cool.begin(), cool.end());



    for (int i = 0; i < n - 1; ++i) {

	if (cool[i] >= cool[i + 1]) {

	    ans += cool[i] - cool[i + 1] + 1;

	    cool[i + 1] += cool[i] - cool[i + 1] + 1;

	}

    }

	

    cout << ans << '\n';

    return 0;

}