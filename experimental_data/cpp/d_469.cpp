//看看会不会爆int!数组会不会少了一维！

//取物问题一定要小心先手胜利的条件

#include <bits/stdc++.h>

using namespace std;

#pragma comment(linker,"/STACK:102400000,102400000")

#define LL long long

#define ALL(a) a.begin(), a.end()

#define pb push_back

#define mk make_pair

#define fi first

#define se second

#define haha printf("haha\n")

const int maxn = 1e5 + 5;

int p[maxn], ans[maxn], ty[maxn];

map<int, int> id;

int a, b, n;



///a type is 0，b is 1, 2 is suit for a



void bfs(int w){

    queue<int> que;

    que.push(w);

    while (!que.empty()){

        int pos = que.front(); que.pop();

        int bval = b - p[pos];

        int mypos = lower_bound(p, p + n, bval) - p;

        if (p[mypos] == bval) {

            ///if (pos == 34 || pos == 35) haha;

            if (ty[mypos] != 1) {

                int aval = a - p[mypos];

                int sonpos = lower_bound(p, p + n, aval) - p;

                if (p[sonpos] != aval) continue;

                if (ty[sonpos] != 1){

                    que.push(sonpos);

                    ty[sonpos] = -1;

                }

            }

            else continue;

            ty[mypos] = ty[pos] = 1;

        }

    }

}



bool solve(){

    if (p[n] >= a && p[n] >= b) return false;

    ///集合在a里面

    for (int i = 0; i < n; i++){

        if (p[i] >= a) break;

        if (ty[i] == 0) continue;

        if (p[i] * 2 == a) {

            ty[i] = 2; continue;

        }

        int val = a - p[i];

        int pos = lower_bound(p, p + n, val) - p;

        if (pos >= n || p[pos] != val) continue;

        if (ty[pos] == -1){

            ty[pos] = 0, ty[i] = 0;

        }

    }

    if (a == b){

        for (int i = 0; i < n; i++){

            if (ty[i] == -1) return false;

            if (ty[i] == 2) ty[i] = 1;

        }

        return true;

    }

    ///集合在b里面

    for (int i = 0; i < n; i++){

        if (p[i] >= b) break;

        if (ty[i] == 0 || ty[i] == 1) continue;

        if (p[i] * 2 == b && ty[i] == -1){

            ty[i] = 1; continue;

        }

        int val = b - p[i];

        int pos = lower_bound(p, p + n, val) - p;

        if (pos >= n || p[pos] != val || ty[pos] == 0) continue;

        if (ty[pos] == -1 || ty[pos] == 2){

            ty[pos] = 1, ty[i] = 1;

        }

    }

    ///如果tyi==-1把集合a的都换成集合b的

    for (int i = 0; i < n; i++)

        if (ty[i] == -1)  bfs(i);

    for (int i = 0; i < n; i++){

        if (ty[i] == -1) return false;

        if (ty[i] == 2) ty[i] = 0;

        //printf("%d ", ty[i]);

        //if (ty[i] == -1) printf("i = %d p[i] = %d\n", i, p[i]);

    }

    cout << endl;

    return true;

}



int main(){

    int cnt = 0;

    cin >> n >> a >> b;

    for (int i = 0; i < n; i++){

        scanf("%d", p + i);

        id[p[i]] = cnt++;

    }

    sort(p, p + n);

    memset(ty, -1, sizeof(ty));

    bool flag = solve();

    if (flag){

        puts("YES");

        for (int i = 0; i < n; i++){

            int myid = id[p[i]];

            ans[myid] = ty[i];

        }

        for (int i = 0; i < n; i++){

            printf("%d ", ans[i]);

        }

        cout << endl;

    }

    else puts("NO");

    return 0;

}