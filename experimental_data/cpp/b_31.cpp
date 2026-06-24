/* End. Death. Resurrection.*/







#include<bits/stdc++.h>

using namespace std;

typedef long long LL ;

#define get(a) for( int i = 0; i < n; i++) sf("%d", &a[i]) ;

#define bug printf("TRUST\n");

#define pf printf

#define sf scanf

#define lp(i, n) for(int i = 0; i < n; i++)

#define rlp(n, i) for(int i = n - 1; i >= 0; i--)

#define bye vector<LL>

#define pb push_back

#define r0 return 0

#define ff first

#define sc second

#define mp make_pair

#define pii pair <int, int>

#define mod 1000000007

#define nod 200003



void func(void)

{

        freopen("input.c","r",stdin);

        freopen("output.c","w",stdout);

}



int main(){

    LL n, q, i,j = 0, temp, t, k, ans = 0, sum = 0, cnt = 0, m, fg = 0, x, y, mx = 0, mx1 = 0, mn = 10000000000000000, mn1 = 10000000000000000;

    string a;

    cin >> a;

    int fga = 0, fgat = 0, fga2 = 0;

    n = a.size();

    for(i = 0; i < n - 2; i++){

        if(a[i] >= 97 and a[i] <= 122 and a[i+2] >= 97 and a[i+2] <= 122 and a[i+1] == '@' ){

            a.insert(a.begin() + i + 3, ',');

            n++;

            sum++;

            i+= 2;

        }

      //  if(a[i] == '@')cnt++;

    }

    for(i = 0; i < n; i++)if(a[i] == '@')cnt++;

    //cout << a << endl;

    if(sum != cnt or cnt == 0)fg = 1;

    for(i = a.size() - 1; a[i]; i--){

        if(a[i] == ','){

            a.erase(a.begin() + i);

            break;

        }

    }

    if(fg)cout << "No solution\n";

    else cout << a << endl;

    r0;

}