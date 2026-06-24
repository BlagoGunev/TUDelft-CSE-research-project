////////////////////////////////////////////////////////---------------DEFINE + DECLARATION-------------/////////////////////////////////////////////////////////////////////////////



#include <bits/stdc++.h>

using namespace std;

#define MASK(i) (1LL << (i))

#define BIT_ON(mask, i) (mask | MASK(i))

#define BIT_OFF(mask, i) (mask &~ MASK(i))

#define C_BITS(i) __builtin_popcount(i)

#define GET_BIT(mask, i)    ((mask >> i) & 1)

#define FOR(i, a, b) for (int i = a; i <= b; i++)

#define FORD(i, a, b) for (int i = a; i >= b; i--)

#define REP(i, n)    for (int i = 0; i < n; i++)

#define fi first

#define se second

#define pb push_back

#define ii pair<int, int>

template<class U, class V> ostream& operator << (ostream& out, const pair<U, V>& p) {

    return out << '(' << p.first << ", " << p.second << ')';

}



template<typename A> ostream& operator<<(ostream &os, const vector<A> &vt) {

    os << '[';

    for (size_t i = 0; i + 1 < vt.size(); i++) os << vt[i] << ", ";

    if (!vt.empty()) os << vt.back();

    return os << ']';

}



template<class U, class V> istream& operator >> (istream& in, pair<U, V>& p) {

    return in >>  p.first >> p.second;

}



template<typename A, typename B> bool maximize(A &x, B y){

    if (x >= y) return false;

    x = y;

    return true;

}



template<typename A, typename B> bool minimize(A &x, B y){

    if (x <= y) return false;

    x = y;

    return true;

}



#define TASK ""



int const oo = 1e9 + 719;

int const mod = 1e9 + 7;

int const lmt = 1e6 + 7;



int n, p, a[lmt];

int cnt[lmt];



////////////////////////////////////////////////////////---------------------FUNCTION------------------/////////////////////////////////////////////////////////////////////////////



bool lower_check(int x){

    memset(cnt + 1, 0, (n + 1) * sizeof(int));

    for (int i = 1; i <= n; i++)

        cnt[min(n + 1, max(1, a[i] - x + 1))]++;



    for (int i = 1, pre = 0; i <= n; i++, pre--){

        pre += cnt[i];

        if (!pre)       return false;

    }

    return true;

}



bool upper_check(int x){

    memset(cnt + 1, 0, (n + 1) * sizeof(int));

    for (int i = 1; i <= n; i++)

        cnt[min(n + 1, max(1, a[i] - x + 1))]++;



    for (int i = 1, pre = 0; i <= n; i++, pre--){

        pre += cnt[i];

        if (!pre)       return false;

        if (pre >= p)   return true;

    }

    return false;

}



int __find(int lowerVal, int upperVal, bool(*func)(int)){

    while (lowerVal != upperVal){

        int mid = lowerVal + upperVal >> 1;

        if (func(mid))  upperVal = mid;

            else lowerVal = mid + 1;

    }

    return lowerVal;

}



void main_project(){

    cin >> n >> p;

    for (int i = 1; i <= n; i++)	cin >> a[i];

    int L = __find(1, oo, *lower_check);

    int R = __find(1, oo, *upper_check);



    if (L >= R) cout << 0;

        else{

            cout << R - L << "\n";

            for (int i = L; i < R; i++)	cout << i << " ";

        }       

}



///////////////////////////////////////////////////////------------------------MAIN--------------------/////////////////////////////////////////////////////////////////////////////



int main(){

    if (fopen(TASK".inp", "r"))     {freopen(TASK".inp", "r", stdin);    freopen(TASK".out", "w", stdout);}

    ios_base::sync_with_stdio(false); cin.tie(nullptr);

	//int t; cin >> t; while (t--)

    main_project();

    return (!!(0-0));

}



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////