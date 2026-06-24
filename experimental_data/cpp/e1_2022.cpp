#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;

// Fast exponentiation to compute (base^exp) % mod
ll mod_pow(ll base, ll exp, ll mod)
{
    ll result = 1;
    base %= mod;
    while (exp > 0)
    {
        if (exp & 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k, q;
        cin >> n >> m >> k >> q; // q=0 for E1

        struct Cell
        {
            int row, col, value;
        };

        vector<Cell> fixed_cells(k);
        for (int i = 0; i < k; i++)
        {
            cin >> fixed_cells[i].row >> fixed_cells[i].col >> fixed_cells[i].value;
            fixed_cells[i].row--; // Convert to 0-based index
            fixed_cells[i].col--;
        }

        ll answer = 1;

        for (int bit = 0; bit < 30; bit++)
        {
            int total_vars = n + m;
            vector<vector<pair<int, int>>> adj(total_vars);
            vector<int> parity(total_vars, -1);
            bool is_consistent = true;
            int components = 0;

            // Build the graph with parity constraints
            for (const auto &cell : fixed_cells)
            {
                int r = cell.row;
                int c = n + cell.col; // Adjusted index for columns
                int bit_value = (cell.value >> bit) & 1;
                adj[r].emplace_back(c, bit_value);
                adj[c].emplace_back(r, bit_value);
            }

            function<bool(int, int)> dfs = [&](int node, int p)
            {
                parity[node] = p;
                for (auto &edge : adj[node])
                {
                    int neighbor = edge.first;
                    int val = edge.second;
                    if (parity[neighbor] == -1)
                    {
                        if (!dfs(neighbor, p ^ val))
                            return false;
                    }
                    else if (parity[neighbor] != (p ^ val))
                    {
                        return false;
                    }
                }
                return true;
            };

            // Perform DFS to check for consistency and count components
            for (int i = 0; i < total_vars; i++)
            {
                if (parity[i] == -1)
                {
                    if (!dfs(i, 0))
                    {
                        is_consistent = false;
                        break;
                    }
                    components++;
                }
            }

            if (!is_consistent)
            {
                answer = 0;
                break;
            }

            // Update the answer based on the number of components
            answer = (answer * mod_pow(2, components - 1, MOD)) % MOD;
        }
        cout << answer << "\n";
    }
}