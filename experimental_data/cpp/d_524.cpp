#include <bits/stdc++.h>

using namespace std;

main () {
    int n, M, T;
    scanf("%d %d %d", &n, &M, &T);
    int sz = 0;
    int bal = 0;
    vector <int> ans;
    deque <int> q;
    bool ok = false;
    for (int i = 1; i <= n; ++i) {
        int h, m, s;
        scanf("%d:%d:%d", &h, &m, &s);
        int t = s + m * 60 + h * 3600;
        while (bal > 0 && q.front () <= t) {
            --bal;
            q.pop_front ();
        }
        if (bal < M) {
            ++bal;
            q.push_back (t + T);
            ++sz;
        }
        else q.back () = t + T;
        if (bal == M) ok = true;
        ans.push_back (sz);
    }
    if (!ok) return cout << "No solution\n", 0;
    printf("%d\n", sz);
    for (int i = 0; i < ans.size (); ++i) printf("%d\n", ans[i]);
}