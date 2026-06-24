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



void solveTestCase()

{

    int N, M;

    cin >> N >> M;



    vector<int> A(N), B(N);

    for (int i = 0; i < N; ++i)

    {

        cin >> A[i] >> B[i];

    }



    long long sumA = 0;

    long long sumB = 0;

    vector<int> X(N), Y(N);

    for (int i = 0; i < N; ++i)

    {

        int canA = min(A[i], M);

        int canB = M - canA;

        X[i] = canA, A[i] -= canA;

        Y[i] = canB, B[i] -= canB;

        sumA += A[i];

        sumB += B[i];

    }



    if (sumA < sumB)

    {

        for (int i = 0; i < N; ++i)

        {

            int canG = min((sumB - sumA) / 2, min((long long)B[i], (long long)X[i]));

            X[i] -= canG, Y[i] += canG;

            sumA += canG, sumB -= canG;

        }

    }



    cout << abs(sumA - sumB) << "\n";

    for (int i = 0; i < N; ++i)

    {

        cout << X[i] << " " << Y[i] << "\n";

    }

    cout << "\n";

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