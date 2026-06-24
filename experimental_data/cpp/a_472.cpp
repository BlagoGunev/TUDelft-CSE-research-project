#include<bits/stdc++.h>



using namespace std;



//Constants

typedef long long ll;

typedef pair<long long, long long> pii;

const ll mod7 = 1000000007;



#define fori(x) for (ll i = 0; i < x; i++)

#define forj(x) for (ll j = 0; j < x; j++)

#define fork(x) for (ll k = 0; k < x; k++)



#define forin(u, x) for (ll u = 0; u < x; u++)

#define forde(u, x) for (ll u = x - 1; u >= 0; u--)



#define rep(u, s, x) for (ll u = s; u < x; u++)

#define rem(u, x, s) for (ll u = s - 1; u >= x; u--)



#define DBG(x) cout << (x) << endl;

#define DBGT(x, t) cout << (t) << "" << (x) << endl;

#define DBGARRAY(x, s, t) cout << t << ""; for (unsigned int z = 0; z < s; z++) cout << x[z] << " "; cout << endl;

#define DBGVECTOR(x, t) cout << t << ""; for (unsigned int z = 0; z < x.size(); z++) cout << x[z] << " "; cout << endl;

#define DBGVECTORPAR(x, t, p) cout << t << ""; for (unsigned int z = 0; z < x.size(); z++) cout << x[z].p << " "; cout << endl;

#define GETVECTOR(x, s) for (unsigned int z = 0; z < s; z++) { cin >> temp; x.push_back(temp); }



//Structs



//Global Variables

ll A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;

ll temp;

char tempChar;

string tempString;



//Function Declarations



int main()

{

    cin >> N;

    if (N % 2 == 0)

    {

        cout << 4 << " " <<  N - 4 << endl;

    }

    else

    {

        cout << 9 << " " << N - 9 << endl;

    }

}