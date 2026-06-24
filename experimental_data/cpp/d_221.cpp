#include <cstdio>

#include <iostream>

#include <vector>

using namespace std;



const int MAXN = 1e5 + 1;

int niz[MAXN], ans[MAXN], n, m, a, b, l, r, FT[MAXN], fsize;

vector <pair <int, int> > querry[MAXN];



int sum(int ind) {

    int res = 0;

    while(ind > 0) {

        res += FT[ind];

        ind -= ind & - ind;

    }

    return res;

}



void add(int ind, int val) {

    while(ind < fsize) {

        FT[ind] += val;

        ind += ind & - ind;

    }

}



vector <int> P[MAXN];



int main() {

    scanf("%d%d", &n, &m);

    for(int i = 1; i <= n; i++) {

        scanf("%d", &niz[i]);

    }

    for(int i = 0; i < m; i++) {

        scanf("%d%d", &l, &r);

        l--;

        querry[r].push_back(make_pair(l, i));

    }

    fsize = n + 1;

    for(int i = 1; i <= n; i++) {

        int cv = niz[i];

        if(cv <= n) {

            P[ cv ].push_back(i);

            if(P[ cv ].size() >= cv) {

                add(P[ cv ][ P[ cv ].size() - cv ], 1);

            }

            if(P[ cv ].size() >= cv + 1) {

                add(P[ cv ][ P[ cv ].size() - cv - 1 ], -2);

            }

            if(P[ cv ].size() >= cv + 2) {

                add(P[ cv ][ P[ cv ].size() - cv - 2 ], 1);

            }

        }

        for(int j = 0; j < querry[i].size(); j++) {

            ans[ querry[i][j].second ] = sum(i) - sum(querry[i][j].first);

        }

    }

    for(int i = 0; i < m; i++)

        printf("%d\n", ans[i]);



    return 0;

}