#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int maxn = 200005;

char s[maxn];
int cnt[26];
int odd[26];

int main()
{
    scanf("%s", s);
    int len = strlen(s);
    int ji = 0;
    for (int i = 0; i < len; i++)
    {
        cnt[s[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++)
    {
        if (cnt[i] & 1)
        {
            odd[ji++] = i;
        }
    }
    if (ji & 1) s[len / 2] = 'a' + odd[ji / 2];
    for (int i = 0; i < ji / 2; i++)
    {
        cnt[odd[i]]++;
    }
    for (int i = ji / 2; i < ji; i++)
    {
        cnt[odd[i]]--;
    }
    for (int i = len / 2 - 1, j = 25; i >= 0; i--)
    {
        while (!cnt[j]) j--;
        s[i] = s[len - 1 - i] = 'a' + j;
        cnt[j] -= 2;
    }
    puts(s);
    return 0;
}