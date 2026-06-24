#include <cstdio>
#include <cctype>

const int N = 1000;
int n;
bool a[N][N];
long long sum;

int get_int() {
  int x = 0;
  char c;
  while(!isdigit(c = getchar()));
  do {
    x = x*10 + c - '0';
  } while(isdigit(c = getchar()));
  return x;
}

void init_sum() {
  for(int i = 0; i < n; ++i)
    for(int j = 0; j < n; ++j)
      sum += a[i][j]*a[j][i];
}

int main() {
  n = get_int();
  for(int i = 0; i < n; ++i)
    for(int j = 0; j < n; ++j)
      a[i][j] = get_int();
  init_sum();
  int q = get_int();
  for(int i = 0; i < q; ++i) {
    int t = get_int();
    if(t < 3)
      get_int(), ++sum;
    else
      putchar(sum%2+'0');
  }
}