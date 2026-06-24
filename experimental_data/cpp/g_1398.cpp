#include <bits/stdc++.h>
using namespace std;
struct FFT{
    const static int LOGN = 19;
    const static int MAXN = 1 << LOGN;
    const double PI = acos(-1);
 
    int lg2(int n) { return 32 - __builtin_clz(n - 1); }
    typedef complex<double> cpx;
    int rev[MAXN];
    cpx rt[MAXN];
 
    void precalc() {
        rt[1] = cpx{1, 0};
        for (int k = 2; k < MAXN; k *= 2) {
            cpx z[] = {1, polar(1.0, PI / k)};
            for (int i = k; i < 2 * k; i++)
                rt[i] = rt[i / 2] * z[i & 1];
        }
    }
    void fft(cpx *a, int n) {
        for (int i = 0; i < n; i++)
            rev[i] = (rev[i / 2] | (i & 1) << lg2(n)) / 2;
        for (int i = 0; i < n; i++)
            if (i < rev[i])
                swap(a[i], a[rev[i]]);
        for (int k = 1; k < n; k *= 2)
            for (int i = 0; i < n; i += 2 * k)
                for (int j = 0; j < k; j++) {
                    auto x = (double *)&rt[j + k], y = (double *)&a[i + j + k];
                    cpx z(x[0] * y[0] - x[1] * y[1], x[0] * y[1] + x[1] * y[0]);
                    a[i + j + k] = a[i + j] - z;
                    a[i + j] += z;
                }
    }
    cpx X[MAXN], Y[MAXN];
    vector<double> multiply(const vector<double> &a, const vector<double> &b) {
        if (a.empty() || b.empty())
            return {};
        int sz = a.size() + b.size() - 1, n = 1 << lg2(sz);
        fill(X, X+n, cpx{0, 0}), fill(Y, Y+n, cpx{0, 0});
        vector<double> res(sz);
        copy(a.begin(), a.end(), X);
        for (int i = 0; i < b.size(); i++)
            X[i].imag(b[i]);
        fft(X, n);
        for (int i = 0; i < n; i++)
            X[i] *= X[i];
        for (int i = 0; i < n; i++)
            Y[i] = X[(n - i) & (n - 1)] - conj(X[i]);
        fft(Y, n);
        for (int i = 0; i < sz; i++)
            res[i] = Y[i].imag() / (4 * n);
        return res;
    }
}fft;

int tmp[1000002], ans[1000002];
int main(){
    fft.precalc();
    int n, x, y;
    scanf("%d%d%d", &n, &x, &y);

    vector<double> a, b;
    a.resize(x+1);
    b.resize(x+1);
    for(int i=0;i<=n;i++){
        int l;
        scanf("%d", &l);
        a[l] = 1;
    }
    for(int i=0;i<=x;i++){
        if(a[i] > 0) b[x-i] = 1;
    }
    vector<double> result = fft.multiply(a, b);
    for(int i=0;i<result.size();i++){
        int val = round(result[i]);
        if(val > 0){
            int l = i-x;
            if(l > 0) tmp[l+l+2*y] = 1;
        }
    }
    for(int i=1;i<=1000000;i++) ans[i] = -1;
    for(int i=1;i<=1000000;i++){
        if(tmp[i]){
            for(int j=i;j<=1000000;j+=i){
                ans[j] = max(ans[j], i);
            }
        }
    }

    int q;
    scanf("%d", &q);
    for(int i=1;i<=q;i++){
        int l;
        scanf("%d", &l);
        printf("%d ", ans[l]);
    }
}