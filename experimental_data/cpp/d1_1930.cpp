#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<cstring>
#include<set>
#include<queue>
void solve()
{
    int n;
    std::cin>>n;
    std::string s;
    std::cin>>s;
    int cnt = 0;
    auto cal = [](std::string t)
    {
        int p = 0;
        int cnt = 0;
        while(p < t.size())
        {
            if(t[p] == '1')
            {
                cnt++;
                p += 2;
            }
            p++;
        }
        return cnt;
    };
    for(int i = 0;i < s.size();i++)
    {
        for(int j = i;j < s.size();j++)
        {
            std::string t = s.substr(i,j - i + 1);
//            std::cout<<t<<std::endl;
            cnt += cal(t);
        }
    }
    std::cout<<cnt<<std::endl;
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