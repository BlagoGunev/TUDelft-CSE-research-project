// Date / Time: 2022-12-15 18:30:35



//Слава Україні, Героям слава



#include <bits/stdc++.h>



using namespace std;



int main() {

    ios_base::sync_with_stdio(false);

    cin.tie(0);

    vector<long long> fib = {1, 1};

    while(fib.back() < 1e15) {

        fib.push_back(fib[(int)fib.size() - 1] + fib[(int)fib.size() - 2]);

    }

    int t;

    cin >> t;

    while(t--) {

        int n;

        cin >> n;

        long long s = 0;

        priority_queue<long long> q;

        while(n--) {

            int x;

            cin >> x;

            s += x;

            q.push(x);

        }

        bool foi = false;

        long long cur = 0, cnt = -1;

        for(auto e : fib) {

            cur += e;

            cnt++;

            if(cur == s) {

                foi = true;

                break;

            }

        }

        if(!foi) {

            cout << "NO\n";

            continue;

        }

        foi = true;

        cur = 0;

        while(!q.empty()) {

            long long x = q.top(); q.pop();

            if(cnt < 0 or x < fib[cnt]) {

                foi = false;

                break;

            }

            x -= fib[cnt--];

            if(cur) {

                q.push(cur);

            }

            cur = x;

        }

        if(cnt >= 0) {

            foi = false;   

        }

        cout << (foi ? "YES\n" : "NO\n");

    }

    return 0;

}