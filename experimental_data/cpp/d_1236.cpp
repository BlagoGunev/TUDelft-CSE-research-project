#include <bits/stdc++.h>
using namespace std;

const int N = 100000;
vector<int> X[N+10], Y[N+10];

bool checkX(int L, int R, int U, int D){
    int len = R - L + 1;
    for (int x = U; x <= D; ++x){
        auto t1 = lower_bound(X[x].begin(), X[x].end(), L);
        auto t2 = upper_bound(X[x].begin(), X[x].end(), R);
        if (t2 - t1 != len) return false;
    }
    return true;
}

bool checkY(int L, int R, int U, int D){
    int len = D - U + 1;
    for (int y = L; y <= R; ++y){
        auto t1 = lower_bound(Y[y].begin(), Y[y].end(), U);
        auto t2 = upper_bound(Y[y].begin(), Y[y].end(), D);
        if (t2 - t1 != len) return false;
    }
    return true;
}

int main(){
    int n, m, k, x, y;
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= k; ++i){
        scanf("%d %d", &x, &y);
        X[x].push_back(y);
        Y[y].push_back(x);
    }
    for (int i = 1; i <= n; ++i){
        sort(X[i].begin(), X[i].end());
    }
    for (int i = 1; i <= m; ++i){
        sort(Y[i].begin(), Y[i].end());
    }
    int L = 0, R = m, U = 1, D = n, now = 1;
    x = 1, y = 1;
    bool f = true;
    while (true){
        if (now == 1){
            auto re = lower_bound(X[x].begin(), X[x].end(), y);
            if (re == X[x].end() || (*re) > R){
                y = R; ++L; now = 2;
            }
            else {
                if (checkY(*re, R, U, D)){
                    y = R = *re - 1;
                    ++L; now = 2;
                }
                else {
                    f = false;
                    goto end;
                }
            }
        }
        else if (now == 2){
            auto re = lower_bound(Y[y].begin(), Y[y].end(), x);
            if (re == Y[y].end() || (*re) > D){
                x = D; ++U; now = 3;
            }
            else {
                if (checkX(L, R, *re, D)){
                    x = D = *re - 1;
                    ++U; now = 3;
                }
                else {
                    f = false;
                    goto end;
                }
            }
        }
        else if (now == 3){
            auto re = lower_bound(X[x].begin(), X[x].end(), y);
            if (re == X[x].begin() || (*--re) < L){
                y = L; --R; now = 4;
            }
            else {
                if (checkY(L, *re, U, D)){
                    y = L = *re + 1;
                    --R; now = 4;
                }
                else {
                    f = false;
                    goto end;
                }
            }
        }
        else if (now == 4){
            auto re = lower_bound(Y[y].begin(), Y[y].end(), x);
            if (re == Y[y].begin() || (*--re) < U){
                x = U; --D; now = 1;
            }
            else {
                if (checkX(L, R, U, *re)){
                    x = U = *re + 1;
                    --D; now = 1;
                }
                else {
                    f = false;
                    goto end;
                }
            }
        }
        //cout << x << ' ' << y << ' ' << now << endl;
        //cout << " " << L << ' ' << R << ' ' << U << ' ' << D << endl;
        if ((now == 2 || now == 4) && U >= D) break;
        if ((now == 1 || now == 3) && L >= R) break;
    }
    end:
    if (f) printf("Yes\n");
    else printf("No\n");
    return 0;
}