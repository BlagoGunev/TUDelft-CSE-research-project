#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef long double ld;

typedef pair <int, int> ii;

typedef vector <int> vi;

typedef vector <vi> vvi;

typedef vector <ii> vii;

typedef vector <vii> vvii;

#define endl '\n'

#define PB push_back

#define MP make_pair

#define EPS (1e-7)              // ToDo

#define MOD (1000000007)        // ToDo

#define all(v) ((v).begin()),((v).end())

#define DEBUG(x) cout<< #x <<" = "<<"\""<< (x) <<"\""<<endl

#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

void read_file(bool outToFile = true){

#ifdef LOCAL_TEST

    freopen("in.in", "rt", stdin);

    if(outToFile)

    freopen("out.out", "wt", stdout);

#endif

}

//

const int DEBUGING = 1;

const ld OO = 100000;

const int itrMax = 1000;

struct point{

    ld x, y;

    

    point(){

        

    }

    point(ld nx, ld ny){

        x = nx, y = ny;

    }

    

    bool operator== (point q){

        return fabs(x - q.x) <= EPS && fabs(y - q.y) <= EPS;

    }

};

//

ld tmax, vmax;

point p1, p2, p3;

point w1, w2;

ld ans;

//

bool read(point &p){

    cin>>p.x>>p.y;

    if(cin.fail()) return 0;

    return 1;

}

//

ld dot(point p, point q){

    return p.x * q.x + p.y * q.y;

}

ld abs(point p){

    return sqrt( dot(p, p) );

}

ld alpha(point w, point p, point q){

    

    point r;

    r.x = q.x - p.x;

    r.y = q.y - p.y;

    

    if(w == point(0, 0))

        return vmax / abs(r);

    

    ld cos_theta = dot(w, r) / abs(w) / abs(r);

    ld sin_theta_2 = 1 - cos_theta * cos_theta;

    

    ld ret = abs(w) * cos_theta;

    

    ld tmp = vmax * vmax - sin_theta_2 * dot(w, w);                             ////////////

    if(tmp <= 0 + EPS)

        ret += 0;

    else

        ret += sqrt(tmp);

    

    ret /= abs(r);

    

    return ret;

}

//

ld tryy(ld ux, ld uy){

    

    point v;

    v.x = ux + w1.x;

    v.y = uy + w1.y;

    

    p2.x = p1.x + v.x * tmax;

    p2.y = p1.y + v.y * tmax;

    

    return 1 / alpha(w2, p2, p3) + tmax;

}

ld f(ld ux){

    

    ld tmp = vmax*vmax - ux*ux;                                                 ///////////

    if(tmp <= 0 + EPS)

        return tryy(ux, 0);

    

    ld uy = sqrt(tmp);

    ld c1 = tryy(ux, uy);

    ld c2 = tryy(ux, -uy);

    

    return min(c1, c2);

}

void TS(){

    

    ld lo = -vmax, hi=+vmax;

    int itr = 0;

    

    while(itr < itrMax)

    {

        itr++;

        

        ld md1 = (hi-lo)/3 + lo;

        ld md2 = (hi-lo)/3*2 + lo;

        

        if(f(md1) < f(md2))

            hi = md2;

        else

            lo = md1;

    }

    

    ans = f(lo);

}

//

bool special(){

    

    if(p1 == p3)

        return ans = 0, 1;

    

    ld t = 1 / alpha(w1, p1, p3);

    

    if(t - EPS > tmax)

        return 0;

    

    ans = t;

    return 1;

}

//

int main()

{

    FASTIO;

    read_file();

    while(read(p1))

    {

        read(p3);

        cin>>vmax>>tmax;

        read(w1);

        read(w2);

        

        if(!special())

        {

//            cout<< "not special\n";

            TS();

        }

        

        cout<< setprecision(25) << fixed << ans <<endl;

    }

}