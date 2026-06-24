#include <iostream>
using namespace std;

int arr[100 + 24];

int main() {
  int n, a = -1, b = -1, c = -1;
  cin>>n;
  for (int i = 0; i < n; i++) {
    cin>>arr[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        if (i != j && i != k && j != k) {
          if (arr[i] == arr[j] + arr[k]) {
            a = i+1;
            b = j+1;
            c = k+1;
            k = n + 100;
            j = n + 100;
            i = n + 100;
          }
        }
      }
    }
  }
    if (a == -1) {
      cout<<-1<<endl;
    }
    else {
      cout<<a<<" "<<b<<" "<<c<<endl;
    }
 }