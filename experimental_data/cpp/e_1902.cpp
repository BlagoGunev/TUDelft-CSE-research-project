// Haricharan
#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define vi vector<int>
#define vii vector<vector<int>>
#define vb vector<bool>
#define pi pair<int, int>
#define si set<int>
#define msi muliset<int>
#define rep(var, l, r) for (int var = l; var < r; var++)

const int ALPHABET_SIZE = 26;

// trie node
struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];
    int count = 0;
    // isEndOfWord is true if the node represents
    // end of a word
    bool isEndOfWord;
};

// Returns new trie node (initialized to NULLs)
struct TrieNode *getNode(void)
{
    struct TrieNode *pNode = new TrieNode;

    pNode->isEndOfWord = false;

    for (int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = NULL;

    return pNode;
}

// If not present, inserts key into trie
// If the key is prefix of trie node, just
// marks leaf node
void insert(struct TrieNode *root, string key)
{
    struct TrieNode *pCrawl = root;
    pCrawl->count++;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();

        pCrawl = pCrawl->children[index];
        pCrawl->count++;
    }

    // mark last node as leaf
    pCrawl->isEndOfWord = true;
}

// Returns true if key presents in trie, else
// false
// bool search(struct TrieNode *root, string key)
// {
//     struct TrieNode *pCrawl = root;
//     pCrawl->count++;

//     for (int i = 0; i < key.length(); i++)
//     {
//         int index = key[i] - 'a';
//         if (!pCrawl->children[index])
//             return false;

//         pCrawl = pCrawl->children[index];
//         pCrawl->count++;
//     }

//     return (pCrawl->isEndOfWord);
// }

void solve()
{
    int n;
    cin >> n;

    struct TrieNode *root = getNode();

    vector<string> s(n);

    int tot = 0;
    rep(i, 0, n)
    {
        cin >> s[i];
        insert(root, s[i]);
        tot += s[i].length();
    }

    int ans = 0;

    rep(i, 0, n)
    {
        string curr = s[i];
        reverse(curr.begin(), curr.end());

        ans += tot + curr.length() * n;

        // cout << ans << endl;

        struct TrieNode *pCrawl = root;

        for (int j = 0; j < (int)curr.length(); j++)
        {
            int index = curr[j] - 'a';
            if (!pCrawl->children[index])
                break;

            pCrawl = pCrawl->children[index];
            ans -= 2 * pCrawl->count;

        }

        // cout << ans << endl;
    }

    cout << ans << endl;
}

int32_t main()
{

    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int tc = 1;
    // cin >> tc;
    rep(i, 0, tc)
        solve();

    return 0;
}