#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 100005 * 2;
char str[maxn];

int main() {
    int len;
    scanf("%d", &len);
    scanf("%s", str);
    int zero = 0;
    for (int i = 0; i < len; i++) {
        if(str[i] == '0') {
            zero++;
        }
    }
    int one = len - zero;
    if (zero >= one) printf("%d\n", zero - one);
    else printf("%d\n", one - zero);
    return 0;
}