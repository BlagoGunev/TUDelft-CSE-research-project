/*

النجاح الساحق خير انتقام

Youssef Elnagar

 * */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define all(c) (c).begin(),(c).end()

#define allr(c) (c).rbegin(),(c).rend()

#define srt(c) sort(all(c))

#define srtv(c) sort(allr(c))

#define rep(i, n) for(ll (i) = 0; (i) < (n); ++(i))

#define repv(i, n) for(ll (i) = n-1; (i) >= 0; --(i))

#define rep1(i, j, n) for(ll (i) = (j); (i) < (n); ++(i))

#define in(v) for(auto& i: (v)) cin >> i

#define YouSefJoUe ios_base::sync_with_stdio(0); cin.tie(0), cout.tie(0);

#define pi pair<int, int>

#define vi vector<int>

#define vll vector<ll>

#define vpll vector<pair<ll, ll>>

#define vpi vector<pair<int, int>>

#define mpll map<ll, ll>

#define F first

#define S second

#define pb push_back

#define clr(val, arr) memset(arr, val, sizeof (arr))

#define sz(pram) (ll)pram.size()

const int OO = 0x3f3f3f3f;

const ll LOO = 0x3f3f3f3f3f3f3f3f;

//const int mod = 1000000007;

const double PI = acos(-1.);

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> p) { return os << '(' << p.first << ", " << p.second << ')'; }

template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

// Delta for: up, right, down, left

int dr[4] { -1, 0, 1, 0 };

int dc[4] { 0, 1, 0, -1 };

const int MOD = 1e9+7;

ll n, m, a, b, c, d, x, y, q;

string s, t, temp1, temp2;

ll nCr(ll n, ll r)

{

    if (r > n)

        return 0;

    if (r == 0 || r == n)

        return 1;

    return nCr(n - 1, r - 1) + nCr(n - 1, r);

}

class BinaryTree {

private:

    int data { };

    BinaryTree* left { };

    BinaryTree* right { };



public:

    BinaryTree(int data) :

            data(data) {

    }

    void print_inorder() {

        if(left)

            left->print_inorder();

        cout << data << " ";

        if(right)

            right->print_inorder();

    }

    void add(vector<int> values, vector<char> direction) {

        assert(values.size() == direction.size());

        BinaryTree* current = this;

        for (int i = 0; i < (int) values.size(); ++i) {

            if (direction[i] == 'L') {

                if (!current->left)

                    current->left = new BinaryTree(values[i]);

                else

                    assert(current->left->data == values[i]);

                current = current->left;

            } else {

                if (!current->right)

                    current->right = new BinaryTree(values[i]);

                else

                    assert(current->right->data == values[i]);

                current = current->right;

            }

        }

    }

    ll height(){

        ll res = 0;

        if(left)

            res = 1 + left->height();

        if(right)

            res = max(res, 1 + right->height());

        return res;

    }

    ll mx(){

        ll res = data;

        if(left)

            res = max(res, left->mx());

        if(right)

            res = max(res, right->mx());

        return res;

    }

    ll nodes(){

        int res = 1;

        if(left)

            res += left->nodes();

        if(right)

            res += right->nodes();

        return res;

    }

    ll leaves(){

        int res = !right && !left;

        if(left)

            res += left->leaves();

        if(right)

            res += right->leaves();

        return res;

    }

    bool find(int val){

        if(data == val)

            return true;

        if(left && left->find(val)) return true;

        if(right && right->find(val)) return true;

        return false;

    }

    bool is_perfet(int h = -1){

        if(~h)

            h = height();

        if(!right && !left)

            return h == 0;

        if((!right && left) || (!left && right))

            return false;

        return left->is_perfet(h-1) && right->is_perfet(h-1);

    }

    void clear(){

        if(left) {

            delete left;

            left = nullptr;

        }

        if(right) {

            delete right;

            right = nullptr;

        }

    }

    ~BinaryTree(){

        clear();

    }

};

const int N = 10000+5;

void solve(){

   cin >> x >> y >> a >> b;

   c = (y-x) / (a+b);

   if(x+c*a == y-c*b){

       cout << c << '\n';

   }else cout << -1 << '\n';

}

int main() {

    YouSefJoUe

    int t = 1;

    cin >> t;

//    freopen("input.txt", "r", stdin);

    while (t--) solve();

//    freopen("output.txt", "w", stdout);

    return 0;

}