#include<bits/stdc++.h>

#pragma GCC optimize(3)

using namespace std;

class segment_tree{

public:

    segment_tree(int N):tree(N, 1e9){}

    void add(int place, int item){

        tree[place] = item;

    }

    void compile(int N){

        for(int i = N; i > 0; i --){

            tree[i] = min(tree[i*2], tree[i*2+1]);

        }

    }

    int getmax(int node, int l, int r, int ml, int mr){

        if (r < ml || l > mr) return 1e9;

        if (l >= ml && r <= mr) return tree[node];

        int mid = (l + r) / 2;

        return min(getmax(node*2, l, mid, ml, mr), getmax(node*2+1, mid+1, r, ml, mr));

    }

private:

    vector<int> tree;

};

void solve(){

	int R, C;

	cin >> R >> C;

	vector<int> arr(C, R);

	int T = C;

	while(__builtin_popcount(T)!= 1){T+=(T&-T);}

	segment_tree tree(T*2);

	for(int i = 0; i < C; i ++){

        int a;

        cin >> a;

        arr[i] -= a;

	}

	for(int i = 0; i < C; i ++){

        tree.add(T+i, arr[i]-1);

	}

	tree.compile(T-1);

	int Q;

	cin >> Q;

	for(int i = 0; i < Q; i ++){

        int ax, ay, bx, by, k;

        cin >> ax >> ay >> bx >> by >> k;

        if (abs(ax-bx)%k != 0 || abs(ay-by)%k!=0){

            cout << "NO" << "\n";

            continue;

        }

        int bound = tree.getmax(1, 0, T-1, min(ay-1, by-1), max(by-1,ay-1));

        if (bound < (R-ax) % k){

            cout << "NO" << "\n";

        }

        else{

            cout << "YES" << "\n";

        }

	}

}

int main()

{

    ios_base::sync_with_stdio(false);

    cin.tie(0);

    cout.tie(0);

    int N = 1;

    while(N--)solve();

    return 0;

}