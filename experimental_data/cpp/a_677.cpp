#include<bits/stdc++.h>



#define ll long long

#define pb push_back

#define pl pop_front

#define pf push_front

#define pp pop_back

#define fr freopen

#define fi first

#define se second

#define so sort

#define ld long double

#define mp make_pair

using namespace std;

ll n , m , l , i , j , r , k , x , y , kol , s , ans;

string a;

int main()

{

    ios_base::sync_with_stdio(0);

    cin.tie(NULL);

    cout.tie(NULL);

    cin>>n>>k;

    for (i = 1 ; i <= n ; i ++)

        cin>>s , ans += 1 + (s > k);

    cout<<ans;

    return 0;

}