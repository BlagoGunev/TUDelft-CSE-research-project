# include <bits/stdc++.h>



# define mk make_pair

# define pb push_back

# define fr first

# define sc second

# define all(s) s.begin(), s.end()

# define ll long long



using namespace std;



const int N = 1e5+10;



int n, b, r, b2, r2;

string s;



main()

{

   int a, b;

   cin >> a >> b;

   int g = __gcd(a, b);

   a /= g;

   b /= g;



   int cnt = 0;

   while(a % 2 == 0)  a /= 2, cnt ++;

   while(a % 3 == 0)  a /= 3, cnt ++;

   while(a % 5 == 0)  a /= 5, cnt ++;



   while(b % 2 == 0)  b /= 2, cnt ++;

   while(b % 3 == 0)  b /= 3, cnt ++;

   while(b % 5 == 0)  b /= 5, cnt ++;



    if(b != 1 || a != 1)

   {

       cout << -1;

       return 0;

   }



   cout << cnt;

}