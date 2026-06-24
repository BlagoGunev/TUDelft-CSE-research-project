#include <cstdio>

using namespace std;

int n, k;
int len;
bool a[100];
int res[100];
char names[50][10];

void init() {
  for(int i = 0; i < 25; i++)
    for(int j = 0; j < 2; j++) {
      sprintf(names[2*i + j], "%c%c", 'A' + i, 'a' + j);
    }
}

void solve() {
  int c = 0;
  int i;
  for(i = n - 1; i >= len; i--)
    res[i] = c++;
  for(; i >= 0; i--)
    if(a[i])
      res[i] = c++;
    else
      res[i] = res[i + k - 1];
}

int main() {
  init();
  scanf("%d %d", &n, &k);
  len = n - k + 1;
  for(int i = 0; i < len; i++) {
    char s[10];
    scanf("%s", s);
    if(s[0] == 'Y')
      a[i] = true;
    else
      a[i] = false;
  }

  solve();
  for(int i = 0; i < n; i++)
    printf("%s ", names[res[i]]);
  printf("\n");
  return 0;
}