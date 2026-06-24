#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int END = 1e6;

int n;
int last, cur, ans;

int main() {
    while(1 == scanf("%d", &n)) {
        ans = END;
        last = 0;
        while(n-- > 0) {
            scanf("%d", &cur);
            ans = min(ans, max(END - cur, last - 1));
            last = cur;
        }
        ans = min(ans, last - 1);
        printf("%d\n", ans);
    }
}