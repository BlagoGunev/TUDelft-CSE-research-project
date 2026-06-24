#include <bits/stdc++.h>

using namespace std;

string s; int n;

int main(){

  freopen("input.txt", "r", stdin);

  freopen("output.txt", "w", stdout);

  scanf("%d", &n);  cin >> s;

  for(int i=0; i<n/2; i++){

    if(s[i] == s[i + n/2])printf("%d %d\n", i+1, i+1+n/2);

    else{if(s[i] == 'L') printf("%d %d\n", i+1, i+1+n/2);

      else printf("%d %d\n", i+1+n/2, i+1);}

  }

}