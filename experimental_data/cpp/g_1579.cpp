#include <bits/stdc++.h>

using namespace std;



void setI(string name)

{

    freopen((name + ".in").c_str(), "r", stdin);

}



void setO(string name)

{

    freopen((name + ".out").c_str(), "w", stdout);

}



// const int MOD = 998'244'353;

const int MOD = 1'000'000'007;

const long long INF = 1'000'000'000LL * 2;



const int MAXN = 3'030;



bool validAnswer(int minimum_length, const vector<int> &A)

{

    bitset<MAXN> range;

    for (int i = 0; i <= minimum_length; ++i)

    {

        range[i] = true;

    }



    bitset<MAXN> dp = range;

    for (const int &segment_length : A)

    {

        dp = ((dp << segment_length) | (dp >> segment_length)) & range;

    }

    return dp.any();

}



void solveTestCase()

{

    int N;

    cin >> N;



    vector<int> A(N);

    for (int &segment_length : A)

    {

        cin >> segment_length;

    }



    int answer = INF;

    int low = *max_element(A.begin(), A.end()), high = 2 * low;

    while (low <= high)

    {

        int mid = (low + high) / 2;

        if (validAnswer(mid, A))

        {

            answer = mid;

            high = mid - 1;

        }

        else

        {

            low = mid + 1;

        }

    }

    cout << answer << "\n";

    return;

}



int main()

{

    ios::sync_with_stdio(false);

    cin.tie(NULL);



    // setI("");

    // setO("");



    int number_of_test_cases = 1;

    cin >> number_of_test_cases;



    for (int test_case_number = 1; test_case_number <= number_of_test_cases; ++test_case_number)

    {

        solveTestCase();

    }

    return 0;

}