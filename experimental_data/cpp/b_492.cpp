#include <iostream>

#include <iomanip>

#include <vector>

#include <string>

#include <string.h>

#include <algorithm>

#include <sstream>

#include <set>

#include <cmath>

using namespace std;



int n, l;

int arr[1003];

bool check(double d)

{

    if (arr[0] != 0) {

        if (arr[0] > d)

            return false;

    }

    if (arr[n - 1] != l) {

        if ((l - arr[n - 1]) > d)

            return false;

    }

    for (int i = 1; i < n; i++) {

        if ((arr[i] - arr[i - 1]) > (d * 2))

            return false;

    }

    return true;

}

int main()

{

	cin >> n >> l;

	for (int i = 0; i < n; i++) {

        cin >> arr[i];

	}

	sort(arr, arr + n);

	double low = 0, mid, high = 1e9;

	for (int i = 0; i < 100; i++)

    {

        mid = (low + high) / 2;

        if (!check(mid)) {

            low = mid;

        }

        else {

            high = mid;

        }

    }

    cout << fixed << setprecision(9) << high << endl;

	return 0;

}