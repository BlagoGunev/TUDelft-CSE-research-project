#include <iostream>

#include <vector>

using namespace std;



#define INF (long long)1e11



void Solve()

{

    int N, K;

    cin >> N >> K;



    vector<long long> PREFIX(N + 1, 0);



    char ch;

    for(int i = 1; i <= N; ++i)

    {

        cin >> ch;



        PREFIX[i] = PREFIX[i-1] + ((ch == 'B') ? 1 : 0);

    }



    const int up = N - K + 1;



    long long ans = INF;

    for(int i = 1; i <= up; ++i)

    {

        long long cur = K - (PREFIX[i+K-1] - PREFIX[i-1]);



        ans = min(ans, cur);

    }



    cout << ans << '\n';

}



int main()

{

    ios_base::sync_with_stdio(false);

    cin.tie(0);

    cout.tie(0);



    int T;

    cin >> T;



    while(T--)

    {

        Solve();

    }



    return 0;

}