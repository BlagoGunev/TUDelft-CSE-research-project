#include <bits/stdc++.h>

using namespace std;





//  -- General -- //

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define rep(i, a, b) for(int i = a; i < (b); ++i)

#define trav(a, x) for(auto& a : x)

#define all(x) x. begin(), x.end()

#define sz(x) (int)(x).size()

typedef long long  ll;

typedef pair<int, int> pii;

typedef vector<int> vi;

const double PI = acos(-1.0);

const double EPS = (1e-10);

int dcmp(double a , double b){

    return fabs(a-b) <= EPS ? 0 : a < b ? -1 : 1; // double comparison //

}





// -- Complex (2D) -- // 

typedef complex<double> point;

#define X real()

#define Y imag()

#define angle(a) (atan2((a).imag(), (a).real())) // theta //

#define vec(a,b) ((b) - (a))

#define length(a) (hypot((a).imag(),(a).real())) // r //

#define normalize(a) (a)/length(a)

// dot product = a*b*cos(T), if zero then perpendicular

#define dp(a,b) ( (conj(a)*(b)).real() )

// cross product = a*b*sin(T), if zero then parallel

#define cp(a,b) ( (conj(a)*(b)).imag() )

#define lengthSqr(p) dp((p),(p))

#define same(p1,p2) (lengthSqr(vec(a,b)) < EPS)

#define rotateO(p,ang) ((p)*exp(point(0,ang))) // rotate angle around Origin //

#define rotateA(p,ang,A) (rotateO(vec(A,p),ang) + A) // rotate angle around point A //

#define reflectO(v,mirror) (conj((v)/(mirror)) * (mirror)) // reflect around mirror from Origin // 









int main()

{   

    IOS

    int t; cin >> t;

    while(t--){

        int n,a,b; cin >> n >> a >> b;

        if (a>b) cout << 1 << '\n';

        else if (n%a) cout << n/a + 1 << '\n';

        else cout << n/a << '\n';

    }

    return 0;

}