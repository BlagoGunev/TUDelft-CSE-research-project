/* Coded By Sandyb3k */



#include <bits/stdc++.h>



#define ll long long

#define f first

#define s second

#define pb push_back



#define pii pair<int, int>

#define mp make_pair



#define ios ios_base::sync_with_stdio(0)



using namespace std;



const int LIT = 1e3;

const int MID = 1e5;

const int MAX = 1e9;



int main() {

  int l, n;

   scanf("%d%d", &l, &n);

for( int i = 1; i <= l; i++)

    if( i % n == 0 ) {

        l++; }

 cout << l;

return 0;

}