#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int , int> pii;

#define F first
#define S second
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define upb upper_bound

const int max_N = 100000 + 20;
int a[max_N];

int main()
{
    ios::sync_with_stdio(false);

    int h , n(0) , pre(1);
    bool flag = false;
    cin >> h;

    for (int i = 0 ; i <= h ; i++){
        cin >> a[i];

        if (a[i] > 1 && pre > 1)
            flag = true;

        pre = a[i];
        n += a[i];
    }

    if (!flag){
        cout << "perfect\n";
        return 0;
    }

    cout << "ambiguous\n";

    int cnt1(1) , cnt2(0) , v(1) , pt(1);
    cout << 0 << ' ';

    while (cnt1 < n){
        cout << v << ' ';
        cnt1++ , cnt2++;

        if (cnt2 == a[pt]){
            v = cnt1 - cnt2 + 1;
            cnt2 = 0;
            pt++;
        }
    }

    cout << endl;

    cnt1 = 1 , cnt2 = 0 , v = 1 , pt = 1;
    int p = 0;
    cout << 0 << ' ';

    while (cnt1 < n){
        cout << v + p << ' ';
        cnt1++ , cnt2++;
        p = (p + 1) % a[pt - 1];
        
        if (cnt2 == a[pt]){
            v = cnt1 - cnt2 + 1;
            cnt2 = 0 , p = 0;
            pt++;
        }
    }

    cout << endl;

    return 0;
}