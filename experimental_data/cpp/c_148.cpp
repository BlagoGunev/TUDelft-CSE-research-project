#include <bits/stdc++.h>
using namespace std;

vector<int> solve(int n, int a, int b)
{
    if (b == 0)
    {
        if (a != 0 && a == n-1) return {};
        else
        {
            auto answer = vector<int>(n-a, 1);
            for (auto i = 0; i < a; i++)
                answer.push_back(answer.back()+1);
            return answer;
        }
    }
    else
    {
        auto answer = vector<int>{1};
        for (auto i = 0; i < b; i++)
            answer.push_back(2*answer.back());
        for (auto i = 0; i < a; i++)
            answer.push_back(answer.back()+1);
        for (auto i = 0; i < n-(a+b)-1; i++)
            answer.push_back(1);
        return answer;
    }
}

int main()
{
    int n, a, b; cin >> n >> a >> b;

    auto answer = solve(n, a, b);
    if (answer.empty()) cout << -1 << endl;
    else
    {
        for (auto x : answer) cout << x << " ";
        cout << endl;
    }
}