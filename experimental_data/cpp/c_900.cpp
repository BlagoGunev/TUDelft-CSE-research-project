#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

const int inf = 1e9;

int main()
{
    int n;
    scanf("%d", &n);
    int a[100500];
    bool b[100500];
    for (int i=0; i<n; i++) {
        scanf("%d", &a[i]);
        b[i] = 0;
    }

    int maxi = -1e9;
    int cnt = 0;
    for (int i=0; i<n; i++) {
        if (a[i] > maxi) {
            maxi = a[i];
            b[i] = 1;
            cnt++;
        }
    }


    int _max_= -1e9;
    int elem;

    if (cnt==n) printf("1");
    else {
        int i = 0;
        int step = -1e9;

        for (int k=0; k<cnt; k++) {
            int j = i+1;

            if (k==cnt-1) j = n;
            else {
                while (!b[j]) j++;
            }
            int l=i, r=j;

            int maxi = step;
            int cnt2 = 0;
            for (int j=l+1; j<r; j++) {
                if (a[j] > maxi) {
                    maxi = a[j];
                    cnt2++;
                }
            }

            //if (cnt2 == 0)
            //    cnt2 = 1;

            if ((cnt2 > _max_) || (cnt2 == _max_ && a[l] < elem)) {
                _max_ = cnt2;
                elem = a[l];
            }

            i = r;
            step = a[l];
        }

        int res = cnt + _max_ - 1;
        if (res > cnt) printf("%d", elem);
        else {
            int ans = 1e9;
            for (int i=0; i<n; i++) {
                if (!b[i]) {
                    ans = min(ans, a[i]);
                }
            }
            printf("%d", ans);
        }
    }

    return 0;
}