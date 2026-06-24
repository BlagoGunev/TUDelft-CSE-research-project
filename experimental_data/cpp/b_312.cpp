# include <bits/stdc++.h>

 using namespace std;



 const double EPS = 1e-8;



 int main(){



    double a, b, c, d;

    cin >> a >> b >> c >> d;



    double x = (1.0-a/b)*(1.0-c/d), sol = 0, pp = 1;

    while(pp > EPS){

       // i += 1.0;



        sol += pp*(a/b);

        //cout << sol << endl;

        pp *= x;



    }

    cout << setprecision(8) << sol << endl;



 }