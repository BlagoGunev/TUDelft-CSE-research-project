//ashrafsusts19







#include <bits/stdc++.h>

#include <limits>



using namespace std;

typedef long long int lli;

#define prnt(a) cout << a << "\n"

#define prnt2(a, b) cout << a << " " << b << "\n";

#define prnt3(a, b, c) cout << a << " " << b << " " << c << "\n";

#define forp1(a) for (lli i = 0; i < a; i++)

#define forp2(a, b) for (lli i = a; i < b; i++)

#define forf(a, b, c) for (lli i = a; i < b; i += c)

#define forv1(i, a) for (lli i = 0; i < a; i++)



void debug(vector<lli> &lst){

    cout << "Debug: ";

    for (lli i = 0; i < lst.size(); i++) cout << lst[i] << " ";    

    cout << "\n";

}



void debug2(string name, vector<lli> &lst)

{

    cout << name << ": ";

    for (lli i = 0; i < lst.size(); i++) cout << lst[i] << " ";

    cout << "\n";

}







lli xgcd(lli a, lli b, lli &x, lli &y){

    if (b == 0){

        x = 1, y = 0;

        return a;

    }

    lli x1, y1;

    lli g = xgcd(b, a % b, x1, y1);

    x = y1;

    y =  x1 - (a / b) * y1;

    return g;

}



lli r, c;

vector<vector<lli>> grid;

vector<vector<pair<lli, lli>>> MEM;



lli dp(lli ir, lli ic, lli val){

    if (ir == r - 1 && ic == c - 1){

        return grid[ir][ic] - val;

    }

    if (MEM[ir][ic].second == val) return MEM[ir][ic].first;

    lli p = LLONG_MAX;

    if (ir < r - 1 && grid[ir + 1][ic] >= val){

        lli p1 = dp(ir + 1, ic, val);

        if (p1 != LLONG_MAX){

            p1 += grid[ir][ic] - val;

            p = min(p, p1);

        }

    }

    if (ic < c - 1 && grid[ir][ic  + 1] >= val){

        lli p1 = dp(ir, ic + 1, val);

        if (p1 != LLONG_MAX){

            p1 += grid[ir][ic] - val;

            p = min(p, p1);

        }

    }

    MEM[ir][ic].second = val;

    return MEM[ir][ic].first = p;

}



bool cmp (lli &a, lli &b){

    return a > b;

}



int main()

{

    ios_base::sync_with_stdio(false);

    cin.tie(0);

    lli t;

    cin >> t;

    while (t--){

        cin >> r >> c;

        MEM.clear();

        MEM.resize(r, vector<pair<lli, lli>>(c, {-1, LLONG_MIN}));        

        grid.clear();

        grid.resize(r, vector<lli> (c));        

        vector<lli> lst;

        forp1(r){

            for (lli j =0; j < c; j++){

                cin >> grid[i][j];

                grid[i][j] -= i + j;

                lst.push_back(grid[i][j]);

            }

        }

        sort(lst.begin(), lst.end(), cmp);

        lli un = unique(lst.begin(), lst.end()) - lst.begin();

        lst.resize(un);



        lli mncost = LLONG_MAX;

        vector<bool> vistat(un, false);

        lli start = 0, end = un - 1, ans = un - 1, mid;

        while (start <= end){

            mid = (start + end) / 2;

            lli val = lst[mid];

            lli p;

            if (grid[0][0] < val) {

                p = LLONG_MAX;

            }

            else {

                p = dp(0, 0, val);

            }

            vistat[mid] = true;

            mncost = min(mncost, p);

            if (p == LLONG_MAX){

                start = mid + 1;

            }

            else {

                ans = mid;

                end = mid - 1;

            }

        }

        for (lli i = ans; i < un; i++){

            if (vistat[i]) continue;

            

            lli val = lst[i];

            if (grid[0][0] < val) continue;

            lli p = dp(0, 0, val);

            mncost = min(p, mncost);

        }

        prnt(mncost);

    }

}