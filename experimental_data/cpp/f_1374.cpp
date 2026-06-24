#include <bits/stdc++.h>

using namespace std;



// const int MOD = 998'244'353;

const int MOD = 1'000'000'007;

const long long INF = 1'000'000'000LL + 100;



void doOperation(int index, vector<int> &answer, vector<pair<int, int>> &A)

{

    assert(index + 2 < (int)A.size());

    answer.emplace_back(index);

    swap(A[index + 1], A[index + 2]);

    swap(A[index + 0], A[index + 1]);

}



void solveTestCase()

{

    int N;

    cin >> N;



    vector<pair<int, int>> A(N);

    for (int i = 0; i < N; ++i)

    {

        cin >> A[i].first;

        A[i].second = i;

    }



    vector<int> order(N);

    iota(order.begin(), order.end(), 0);

    sort(order.begin(), order.end(), [&](int i, int j)

         { return A[i].first < A[j].first; });



    int inversions_count = 0;

    for (int i = 0; i < N; ++i)

    {

        for (int j = 0; j < i; ++j)

        {

            if (order[j] > order[i])

            {

                ++inversions_count;

            }

        }

    }



    if (inversions_count % 2 == 1)

    {

        bool has_equal = false;

        for (int i = 0; i + 1 < N; ++i)

        {

            if (A[order[i]].first == A[order[i + 1]].first)

            {

                has_equal = true;

                swap(order[i], order[i + 1]);

                break;

            }

        }



        if (!has_equal)

        {

            cout << -1 << "\n";

            return;

        }

    }



    vector<int> answer;

    for (int i = 0; i < N; ++i)

    {

        int target = -1;

        int index = order[i];

        for (int j = 0; j < N; ++j)

        {

            if (A[j].second == index)

            {

                target = j;

                break;

            }

        }



        while (target - 2 >= i)

        {

            doOperation(target - 2, answer, A);

            target -= 2;

        }



        if (target > i)

        {

            // cerr << target << " " << i << "\n";

            doOperation(i, answer, A);

            doOperation(i, answer, A);

        }

    }



    cout << (int)answer.size() << "\n";

    for (int i = 0; i < (int)answer.size(); ++i)

    {

        cout << answer[i] + 1 << " \n"[i == (int)answer.size() - 1];

    }

    return;

}



int main()

{

    ios::sync_with_stdio(false);

    cin.tie(NULL);



    int number_of_test_cases = 1;

    cin >> number_of_test_cases;

    for (int test_case_number = 1; test_case_number <= number_of_test_cases; ++test_case_number)

    {

        solveTestCase();

    }

    return 0;

}