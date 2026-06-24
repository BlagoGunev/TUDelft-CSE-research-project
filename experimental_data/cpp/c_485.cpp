#include <bits/stdc++.h>

#define ll long long

#define mp make_pair

#define MOD 1000000007



using namespace std;



ll l, r, ans;

int n, b;



int main()

{

  //freopen("input.txt", "r", stdin);

  scanf("%d", &n);

  while(n--){

    scanf("%lld%lld", &l, &r);

    b = 60;

    ans = 0;

    if(l == r){

      printf("%lld\n", l);

      continue;

    }

    while(((1ll << b) & l) == ((1ll << b) & r)){

      ans |= ((1ll << b) & l);

      b--;

    }

    ans |= (1ll << b);

    ans--;

    printf("%lld\n", (ans | (1ll << b)) <= r ? (ans | (1ll << b)) : ans );

  }

  return 0;

}