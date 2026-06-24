#include <bits/stdc++.h>



using namespace std;



#define fr(a, b, c) for(int a = b, __ = c; a < __; a++)



#define dbg(x) cerr << ">>> " << x << endl;

#define _ << ", " <<



typedef long long ll;

typedef pair<int, int> ii;



const int inf = 0x3f3f3f3f;

const ll linf = 0x3f3f3f3f3f3f3f3fLL;



int a, n;



int main() {

    ios_base::sync_with_stdio(false);



    while(cin >> a >> n) {

        fr(R, 0, 100011) {

            a = (2 * a) % n;

        }



        puts(a ? "No" : "Yes");

    }

    

    return 0;

}