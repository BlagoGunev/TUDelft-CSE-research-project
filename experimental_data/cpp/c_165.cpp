#include <cstdio>
#include <cstring>
#include <algorithm>

int count, k, len;
char s[1000001], *last, *next, *st, *ed;
long long ans;
int main()
{
  scanf("%d\n%s", &k, s);
  char* end(s+strlen(s));
  if (k == 0)
  {
    st = s-1;
    while (st < end)
    {
      ed = std::find(st+1, end, '1');
      ans += static_cast<long long>(ed-st)*(ed-st-1)/2;
      st = ed;
    }
    printf("%I64d", ans);
    return 0;
  }

  last = s-1, next = s;
  for (count = 0; next < end && count < k; ++next)
    if (*next == '1')
    {
      ++count;
      if (count == 1)
        st = next;
    }
  --next;
  if (st == NULL || count < k)
  {
    printf("0");
    return 0;
  }
  while (next < end)
  {
    ed = next++;
    while (next < end && *next == '0') ++next;
    ans += static_cast<long long>(st-last)*(next-ed);
    last = st++;
    while (st < end && *st == '0') ++st;
  }
  printf("%I64d", ans);
}