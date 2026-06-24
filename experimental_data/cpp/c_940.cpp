#include <cstdio>
#include <cassert>

using namespace std;

char s[100005];
bool has[30];
int n, k;

int main(int argc, char* argv[]) {
    scanf("%d%d", &n, &k);
    scanf("%s", s);

    for (int i = 0; i < n; ++i)
        has[s[i] - 'a'] = true;

    int pos = -1;
    for (int i = k - 1; i >= 0; --i) {
        int ch;
        for (ch = s[i] + 1; !has[ch - 'a'] && ch <= 'z'; ++ch)
            ;
        if (ch <= 'z') {
            pos = i;
            break;
        }
    }

    int smch = 'a';
    while (!has[smch - 'a'])
        ++smch;

    if (k > n) {
        for (int i = 0; i < k; ++i) {
            if (i < n)
                putchar(s[i]);
            else
                putchar(smch);
        }
    } else {
        assert(pos >= 0);
        for (int i = 0; i < k; ++i) {
            if (i < pos)
                putchar(s[i]);
            else if (i == pos) {
                int ch;
                for (ch = s[i] + 1; !has[ch - 'a']; ++ch)
                    ;
                putchar(ch);
            } else
                putchar(smch);
        }
    }
    putchar('\n');

    return 0;
}