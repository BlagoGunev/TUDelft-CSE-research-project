#include <bits/stdc++.h>
#define pb push_back
#define CLR(a) memset(a, 0, sizeof a)
#define SETDP(a) memset(a, -1, sizeof a)
#define SETINF(a) memset(a, 127, sizeof a)
using namespace std;
typedef long long ll;
typedef pair<int, int>pii;
int n;
int cnt[300][300];
vector<pii>fractions;
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);
    cin>>n;
    for(int i=0; i<n; i++)
    {
        string s;
        int a=0, b=0, top=0, bot=0;
        cin>>s;
        int it=1;
        for(; it<=2; it++)
        {
            if(s[it]<'0'||s[it]>'9')break;
            a=a*10+s[it]-'0';
        }
        while(s[it]<'0'||s[it]>'9')it++;
        for(; it<s.size(); it++)
        {
            if(s[it]<'0'||s[it]>'9')break;
            b=b*10+s[it]-'0';
        }
        while(s[it]<'0'||s[it]>'9')it++;
        for(; it<s.size(); it++)
        {
            if(s[it]<'0'||s[it]>'9')break;
            bot=bot*10+s[it]-'0';
        }
        top=a+b;
        int dbd=__gcd(top, bot);
        top/=dbd;
        bot/=dbd;
        cnt[top][bot]++;
        fractions.pb({top, bot});
    }

    for(auto p:fractions)
        cout<<cnt[p.first][p.second]<<" ";
    cout<<"\n";
    return 0;
}