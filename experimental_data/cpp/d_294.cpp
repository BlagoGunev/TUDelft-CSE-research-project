#include <bits/stdc++.h>
#include <cstdio>
#include <set>
#include <string>
#include <iostream>
using namespace std;
struct State
{
    int x, y, vec;
    bool operator< (const State &a) const
    {
        if (x != a.x)
            return x < a.x;
        else if (y != a.y)
            return y < a.y;
        else
            return vec < a.vec;
    }
};
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    int x, y;
    scanf("%d%d", &x, &y);
    string s;
    cin >> s;
    int vec;
    if (s == "UL")
        vec = 0;
    else if (s == "UR")
        vec = 1;
    else if (s == "DL")
        vec = 2;
    else
        vec = 3;
    set <State> st, udst;
    State now, udnow;   
    now.x = x;
    now.y = y;
    now.vec = vec;
    udnow.x = x;
    udnow.y = y;
    udnow.vec = 0;  
    long long ans = 0;
    while (1)
    {
        //printf("%d %d %d\n", now.x, now.y, now.vec);
        int &vec = now.vec;
        if (st.find(now) != st.end())
            break;
        st.insert(now);
        udst.insert(udnow);
        if (udst.size() == n + m - 2)
            break;
        int step = 0;
        if (now.vec == 0)
        {
            step = min(now.x - 1, now.y - 1);
            now.x -= step;
            now.y -= step;
            if (now.x == now.y)
                vec = 3;
            else if (now.x < now.y)
                vec = 2;
            else
                vec = 1;
        }
        else if (now.vec == 1)
        {
            step = min(now.x - 1, m - now.y);
            now.x -= step;
            now.y += step;
            if (now.x == m - now.y + 1)
                vec = 2;
            else if (now.x < m - now.y + 1)
                vec = 3;
            else 
                vec = 0;
        }
        else if (now.vec == 2)
        {
            step = min(n - now.x, now.y - 1);
            now.x += step;
            now.y -= step;
            if (n - now.x + 1 == now.y)
                vec = 1;
            else if (n - now.x + 1 < now.y)
                vec = 0;
            else
                vec = 3;
        }
        else 
        {
            step = min(n - now.x, m - now.y);
            now.x += step;
            now.y += step;
            if (n - now.x == m - now.y)
                vec = 0;
            else if (n - now.x < m - now.y)
                vec = 1;
            else
                vec = 2;
        }
        ans += step;
        udnow = now;
        udnow.vec = 0;
    }
    //printf("%d\n", udst.size());
    if (udst.size() != n + m - 2)
        ans = -1;
    else
        ++ans;
    printf("%lld\n", ans);
    return 0;
}