#include <stdio.h>
#define MAX_L 10000

char ch[MAX_L];

int main(void)
{
    scanf("%s", ch);
    int ans = 0;
    for (int i = 0; ch[i] != '\0'; i++) {
        int sup = 0, inf = 0;
        for (int j = i; ch[j] != '\0'; j++) {
            switch (ch[j])
            {
            case '(':
                sup++;
                inf++;
                break;
            case ')':
                sup--;
                inf--;
                break;
            case '?':
                sup++;
                inf--;
                break;
            }
            if (sup < 0) break;
            if (inf < 0) inf = 0;
            if (inf == 0 && ((j - i) & 1)) ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}