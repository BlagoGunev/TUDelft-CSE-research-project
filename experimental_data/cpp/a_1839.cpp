#include<iostream>
#include<algorithm>
#include<vector>
void solve()
{
    int n,k;
    std::cin>>n>>k;
    int maxx = 0;
    int lst = 0;
    int cnt = 0;
    auto cal = [](int a,int b)
    {
        return a % b == 0 ? a / b : a / b + 1;
    };
    for(int i = 1;i <= n / 2;i++)
    {
        maxx = std::max(maxx,cal(i,k) + cal(n - i,k));
    }
    std::cout<<maxx<<std::endl;
}
int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int t;
    std::cin>>t;
    while(t--)solve();
    return 0;
}