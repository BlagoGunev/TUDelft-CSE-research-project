#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false);; cin.tie(NULL)
void selfMax(int& a, int b){
    a = max(a, b);
}
void selfMin(int& a, int b){
    a = min(a, b);
}
/*

Use DSU dsu(N);

*/
struct DSU {
	vector<int> e;
	DSU(int N) { e = vector<int>(N, -1); }

	// get representive component (uses path compression)
	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }

	bool same_set(int a, int b) { return get(a) == get(b); }

	int size(int x) { return -e[get(x)]; }

	bool unite(int x, int y) {  // union by size
		x = get(x), y = get(y);
		if (x == y) return false;
		if (e[x] > e[y]) swap(x, y);
		e[x] += e[y]; e[y] = x;
		return true;
	}
};
/*

Run with Bit<int> BIT

*/
template <class T> class BIT {
    private:
        int size;
        vector<T> bit;
        vector<T> arr;
    public:
        BIT(int size) : size(size), bit(size + 1), arr(size) {}
        void set(int ind, int val) { add(ind, val - arr[ind]); }
        void add(int ind, int val) {
            arr[ind] += val;
            ind++;
            for (; ind <= size; ind += ind & -ind) { bit[ind] += val; }
        }
        T pref_sum(int ind) {
            ind++;
            T total = 0;
            for (; ind > 0; ind -= ind & -ind) { total += bit[ind]; }
            return total;
        }
};
/*

Change Comb for specific Seg tree probs, but run with Seg<int> Seg;

*/
template<class T> struct Seg {
	const T ID = 1e18; T comb(T a, T b) { return min(a,b); }
	int n; vector<T> seg;
	void init(int _n) { n = _n; seg.assign(2*n,ID); }
	void pull(int p) { seg[p] = comb(seg[2*p],seg[2*p+1]); }
	void upd(int p, T val) {
		seg[p += n] = val; for (p /= 2; p; p /= 2) pull(p); }
	T query(int l, int r) {
		T ra = ID, rb = ID;
		for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
			if (l&1) ra = comb(ra,seg[l++]);
			if (r&1) rb = comb(seg[--r],rb);
		}
		return comb(ra,rb);
	}
};
int main(){
	IOS;
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        map<string, int> mp;
        for(int i = 0; i < n - 1; i++){
            string s2 = to_string(s[i]);
            s2 += to_string(s[i + 1]);
            mp[s2]++;
        }
        cout << mp.size() << "\n";
    }
}