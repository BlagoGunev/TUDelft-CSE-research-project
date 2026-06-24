#include <bits/stdc++.h>



using namespace std;



#define MAXN 100005

#define xx first

#define yy second



int n, m, a[MAXN];

vector<pair<int, int> > qu[MAXN];

vector<int> mp[MAXN];

int BIT[MAXN], pos[MAXN], ans[MAXN];



void update(int idx, int v) {

    for(int i = idx; i <= n; i += i & -i) {

        BIT[i] += v;

    }

}



int query(int idx) {

    int ans = 0;



    for(int i = idx; i > 0; i -= i & -i) {

        ans += BIT[i];

    }



    return ans;

}



int main() {

    cin >> n >> m;



    for(int i = 1; i <= n; i++) {

        scanf("%d", a + i);

    }



    for(int i = 1; i <= m; i++) {

        int l, r;

        scanf("%d %d", &l, &r);



        qu[r].push_back({l, i});

    }



    for(int i = 1; i <= n; i++) {

        if(a[i] > n) {

            continue;

        }



        int x = a[i];



        mp[x].push_back(i);



        if(mp[x].size() >= x) {

            int id = pos[x]++;



            update(mp[x][id], 1);



            if(id) {

                update(mp[x][id - 1], -2);

            }



            if(id > 1) {

                update(mp[x][id - 2], 1);

            }

        }



        for(int k = 0; k < qu[i].size(); k++) {

            ans[qu[i][k].yy] = query(i) - query(qu[i][k].xx - 1);

        }

    }







    for(int i = 1; i <= m; i++) {

        printf("%d\n", ans[i]);

    }

}