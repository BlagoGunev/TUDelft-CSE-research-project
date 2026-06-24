#include <bits/stdc++.h>
#include <stdio.h>
#include <map>
#include <algorithm>
using namespace std;

struct tt
{
    int a, id;
    bool operator < (const tt &o) const
    {
        if (a != o.a) {
            return a < o.a;
        }
        return id < o.id;
    }
} t, u;

map<tt, bool> my, you;
map<tt, bool>::iterator it, us;

int n = 0, m = 0, k = 0, v[100005] = { 0 };

long long f()
{
    my.clear();
    you.clear();

    long long ans = 0, sum = 0, our = 0;
    int i = 0;
    bool b = false;

    for (i = 0; i < n; i ++) {

        if (i >= m) {
            sum -= v[i-m];

            if (v[i-m] < 0) {
                t.a = v[i-m];
                t.id = i - m;

                us = you.find(t);
                if (us != you.end()) {
                    you.erase(us);
                }

                it = my.find(t);
                if (it != my.end()) {
                    our += v[i-m] + v[i-m];
                    my.erase(it);
                }
            }

        }
        
        sum += v[i];

        if (v[i] < 0) {
            t.a = v[i];
            t.id = i;

            you[t] = true;
        }
        
        b = true;
        while (b) {
            b = false;
            if (you.size() > 0) {
                
                us = you.begin();

                u = us->first;

                if (my.size() < k) {
                    b = true;
                    our -= u.a + u.a; 
                    my[u] = true;
                    you.erase(us);
                }
                else if (my.size() > 0) {
                    it = my.end();
                    it --;
                    t = it->first;
                    if (u < t) {
                        b = true;
                        you.erase(us);
                        you[t] = true;
                        our += t.a * 2;
                        my.erase(it);
                        my[u] = true;
                        our -= u.a * 2;
                    }
                }
            }
        }

        if (i >= m - 1) {
            if (sum + our > ans) {
                ans = sum + our;
            }
        }
    }
    return ans;
}
        

int main()
{
    int i = 0;
    long long now = 0, ans = 0;

    while (scanf("%d%d", &n, &m) == 2) {
        for (i = 0; i < n; i ++) {
            scanf("%d", v + i);
        }
        scanf("%d", &k);
        ans = f();
        for (i = 0; i < n; i ++) {
            v[i] = -v[i];
        }
        now = f();
        if (now > ans) {
            ans = now;
        }
        printf("%lld\n", ans);
    }
    return 0;
}