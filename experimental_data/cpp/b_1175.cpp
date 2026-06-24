#include <bits/stdc++.h>

using namespace std;

string oper;
char _[100];

typedef long long int LL;

stack<int> mm;
LL times = 1, ans = 0;

const LL MX = (1LL << 32) - 1;

int main()
{
    int n; scanf("%d", &n);

    bool overflow = 0;
    while(n--)
    {
        scanf("%s", _);
        oper = _;

        if(oper == "end")
        {
            times /= mm.top();
            mm.pop();
        }
        else if(oper == "add")
        {
            ans += times;

            if(ans > MX)
            {
                overflow = 1;
                break;
            }
        }
        else if(oper == "for")
        {
            int w; scanf("%d", &w);

            if(times > MX)
            {
                mm.push(1);
                times *= 1;
            }
            else
            {
                mm.push(w);
                times *= w;
            }
        }
    }

    if(overflow) printf("OVERFLOW!!!\n");
    else printf("%lld\n", ans);

    return 0;
}