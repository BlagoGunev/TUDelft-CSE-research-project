#include <cstdio>
#include <cstring>

#define MAX 110

char letra[MAX];

int main() {
  int N;
  scanf("%d",&N);
  while (N--) {
    scanf("%s",letra);
    int len = strlen(letra);
    if (len > 10) {
      printf("%c%d%c\n",letra[0], len-2, letra[len-1]);
    }
    else
      printf("%s\n",letra);
  }
    return 0;

}