# include<bits/stdc++.h>

# define ll long long

using namespace std;

int main()

{

    ll n , m , i , j , a , b , mn;

    cin>> n>> m>> i>> j>> a>> b;

    mn = 1000000000000;

    ll x1 = abs(i - 1) , x2 = abs(j - 1);

    if((n == i && m == j )||(1 == i && m == j ) || (n == i && 1 == j ) || (1 == i && 1 == j )) {cout<<0;return 0;}

    if((n - i < a && i - 1 < a) || (m - j < b && j - 1 < b)){cout<<"Poor Inna and pony!";return 0;}

   // cout<<x1<<' '<<x2<<'\n';

    if(x1 % a == 0 && x2 % b == 0 && (x1 / a - x2 / b) % 2 == 0) mn = min(mn , max(x1 / a , x2 / b));

     x1 = abs(i - 1) , x2 = abs(j - m);

     //cout<<x1<<' '<<x2<<'\n';

    if(x1 % a == 0 && x2 % b == 0 && (x1 / a - x2 / b) % 2 == 0) mn = min(mn , max(x1 / a , x2 / b));

     x1 = abs(i - n) , x2 = abs(j - 1);

    if(x1 % a == 0 && x2 % b == 0 && (x1 / a - x2 / b) % 2 == 0) mn = min(mn , max(x1 / a , x2 / b));

     x1 = abs(i - n) , x2 = abs(j - m);

    if(x1 % a == 0 && x2 % b == 0 && (x1 / a - x2 / b) % 2 == 0) mn = min(mn , max(x1 / a , x2 / b));

    if(mn == 1000000000000){cout<<"Poor Inna and pony!";return 0;}

    cout<<mn;

}