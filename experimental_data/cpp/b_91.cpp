#include<cstdio>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int n;
int c;
int a[100001];
int val[100001];
int ans[100001];

int find(int k, int cur) {
  int min = 0;
  int max = c;
  
  while (min < max) {
    int mid = min + (max - min)/2;
    int ind = val[mid];
    if (ind >= cur) {
      min = mid + 1;
    } else {
      max = mid;
    }
  }
  min = 0;
  while (min < max) {
    int mid = min + (max - min)/2;
    int ind = val[mid];
    if (a[ind] >= k) {
      min = mid + 1;
    } else {
      max = mid;
    }
  }
  return max;
}

int main()
{
  scanf ("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf ("%d", &a[i]);
  }
  val[0] = n-1;
  c = 1;
  for (int i = n - 2; i >= 0; i--) {
    if (a[i] < a[val[c-1]]) {
      val[c++] = i;
    }
  }
  /*for (int i = 0; i < c; i++) {
    printf ("%d ", val[i]);
  }*/
  for (int i = 0; i < n; i++) {
    ans[i] = -1;
    int p = find(a[i], i);
    if (p < c && val[p] > i) {
      ans[i] = val[p] - i - 1;
    }
    printf ("%d", ans[i]);
    if (i == n - 1) {
      printf ("\n");
    } else {
      printf (" ");
    }
    
  }
  return 0;
}