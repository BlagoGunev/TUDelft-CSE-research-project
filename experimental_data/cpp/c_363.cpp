#include <bits/stdc++.h>
using namespace std;
struct _ {ios_base::Init i; _() {cin.sync_with_stdio(0); cin.tie(0);}} _;

int main() {
    int c, last = EOF, count = 1;
    bool flag = false;

    while ((c = getchar()) != '\n') {
        if (c != last) {
            putchar(c);
            last = c;
            if (count == 1) {
                flag = false;
            }
            count = 1;
        } else {
            count++;
            if (count == 2) {
                if (!flag) {
                    putchar(c);
                }
                flag = !flag;
            }
        }
    }
    putchar('\n');
}