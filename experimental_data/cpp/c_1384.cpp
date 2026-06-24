#include <bits/stdc++.h>

using namespace std;



const int ALPHA = 26;

const char MIN_CHAR = 'a';



struct union_find {

  private:

    int components;

    std::vector<int> sizes;

    std::vector<int> link;

 

  public:

    union_find(int _components) : components(_components) {

        sizes.assign(components, 1);

        link.resize(components);

        std::iota(link.begin(), link.end(), 0);

    }

 

    int count() const { return components; }

    int size(int x) { return sizes[find(x)]; }

    int find(int x) { return x == link[x] ? x : link[x] = find(link[x]); }

 

    bool unite(int x, int y) {

        x = find(x), y = find(y);

        if (x == y) return false;

        /* Ensure that y is a smaller set than x. */

        if (sizes[x] < sizes[y]) std::swap(x, y);

        /* Merge y into x. */

        sizes[x] += sizes[y];

        link[y] = x;

        components--;

        return true;

    }

};



int run_test_case() {

    int n;

    cin >> n;



    string a, b;

    cin >> a >> b;



    union_find UF(ALPHA);

    for (int i = 0; i < n; ++i) {

        if (b[i] < a[i]) return -1;

        UF.unite(a[i] - MIN_CHAR, b[i] - MIN_CHAR);

    }



    return ALPHA - UF.count();

}



int main() {

    ios::sync_with_stdio(false);

    cin.tie(nullptr);



    int test_cases;

    cin >> test_cases;

    

    while (test_cases--) {

        cout << run_test_case() << '\n';

    }

}