#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif

int t;
cin >> t;
while(t--){
    int a, b;
    scanf("%d+%d", &a, &b);
    printf("%d\n", a + b);
}

return 0;
}