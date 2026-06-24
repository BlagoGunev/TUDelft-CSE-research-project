#include <bits/stdc++.h>
std::string to_string(__int128_t value) {
    if (value == 0) return "0";
    
    std::string result;
    bool negative = (value < 0);
    if (negative) value = -value;
    
    while (value > 0) {
        result += '0' + (value % 10);
        value /= 10;
    }
    
    if (negative) result += '-';
    
    std::reverse(result.begin(), result.end());
    return result;
}

// Overload << operator for __int128
std::ostream& operator<<(std::ostream& os, __int128_t value) {
    return os << to_string(value);
}
template<typename T1, typename T2>
std::ostream& operator<<(std::ostream& os, const std::pair<T1, T2>& p) {
    os << "(" << p.first << ", " << p.second << ")";
    return os;
}
template <typename T, std::size_t N>
std::ostream& operator<<(std::ostream& os, const std::array<T, N>& arr) {
    os << "[";
    for (std::size_t i = 0; i < N; ++i) {
        os << arr[i];
        if (i < N - 1) {
            os << ", ";
        }
    }
    os << "]";
    return os;
}
template<typename T> std::ostream& operator<<(std::ostream& os, const std::set<T>& s) {
    os << "{ ";
    for(const auto& elem : s) {
        os << elem << " ";
    }
    os << "}";
    return os;
}
template<typename T> std::ostream& operator<<(std::ostream& os, const std::multiset<T>& s) {
    os << "{ ";
    for(const auto& elem : s) {
        os << elem << " ";
    }
    os << "}";
    return os;
}

template<typename T> std::ostream& operator<<(std::ostream& os, std::queue<T> q) {
    // Print each element in the queue
    os << "{ ";
    while (!q.empty()) {
        os << q.front() << " ";
        q.pop();
    }
    os << "}";
    // Print a newline at the end
    return os;
}
template<typename T> std::ostream& operator<<(std::ostream& os, std::deque<T> q) {
    // Print each element in the queue
    os << "{ ";
    while (!q.empty()) {
        os << q.front() << " ";
        q.pop();
    }
    os << "}";
    // Print a newline at the end
    return os;
}
template<typename T> std::ostream& operator<<(std::ostream& os, std::stack<T> q) {
    // Print each element in the queue
    os << "{ ";
    while (!q.empty()) {
        os << q.top() << " ";
        q.pop();
    }
    os << "}";
    // Print a newline at the end
    return os;
}
template<typename T> std::ostream& operator<<(std::ostream& os, std::priority_queue<T> q) {
    // Print each element in the queue
    os << "{ ";
    while (!q.empty()) {
        os << q.top() << " ";
        q.pop();
    }
    os << "}";
    // Print a newline at the end
    return os;
}

template<typename T> std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
    os << "[ ";
    for(const auto& elem : vec) {
        os << elem << " ";
    }
    os << "]";
    return os;
}
template<typename K, typename V> std::ostream& operator<<(std::ostream& os, const std::map<K, V>& m) {
    os << "{ ";
    for(const auto& pair : m) {
        os << pair.first << " : " << pair.second << ", ";
    }
    os << "}";
    return os;
}
template<typename T>
using min_pq = std::priority_queue<T, std::vector<T>, std::greater<T>>;
using namespace std;
using ll = long long;
#define add push_back 
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define f first
#define s second
#define trav(a,x) for (auto& a: x)
#define int long long
#define vt vector
#define endl "\n"
#define double long double
ll mod = 1000000007;
ll inf = 1e18;
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
signed main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    // freopen("input.txt" , "r" , stdin);
    // freopen("output.txt" , "w", stdout);
    string s;
    cin >> s;
    int n = s.size();
    /*
    cases: s[i...j]<s[j+1...j+i-1] - impossible (set to -1)
    otherwise always optimal to take shortest one possible (first one that is different)
    */
    vt<vt<int>> firstDiff(n, vt<int>(n));
    F0R(i, n-1) {
        if(s[i]==s[n-1]) {
            firstDiff[i][n-1]=-1;
        } else {
            firstDiff[i][n-1]=0;
        }
    }
    R0F(i, n-1) {
        F0R(j, i) {
            if(s[i]==s[j]) {
                if(firstDiff[j+1][i+1]==-1) firstDiff[j][i]=-1;
                else firstDiff[j][i]=firstDiff[j+1][i+1]+1;
            }
        }
    }
    // cout << firstDiff << endl;
    vt<vt<int>> dp(n, vt<int>(n));//dp[i][j] = max parts for j+1...n if last one is i...j
    vt<vt<int>> suff(n, vt<int>(n));
    R0F(j, n-1) {
        F0R(i, j+1) {
            suff[i][j]=suff[i][j+1];
            /*
            first: i...j
            next: j+1...?
            */
            int dif = firstDiff[i][j+1];
            if(dif>j-i+1) dif=j-i+1;
            int least = -1;
            if(dif==-1) {
                least = j+1+(j-i)+1;//[i, j] [j+1, j+1+j-i]
                if(least>=n) {
                    dp[i][j]=-1;
                    continue;
                }
                // cout << i << " " << j << " " << least << endl;
                dp[i][j]=suff[j+1][least]+1;
            } else {
                int ind2 = j+1+dif;
                int ind1 = i+dif;
                if(ind1>=j+1) {
                    least=j+1+(j-i+1);
                    dp[i][j]=suff[j+1][least]+1;
                    suff[i][j]=max(suff[i][j], dp[i][j]);
                    continue;
                }
                if(s[ind2]<s[ind1]) {
                    dp[i][j]=-1;
                    continue;
                }
                // cout << i << " " << j << " " << ind1 << " " << ind2 << endl;
                dp[i][j]=suff[j+1][ind2]+1;
            }
            suff[i][j]=max(suff[i][j], dp[i][j]);
        }
    }
    // cout << firstDiff << endl;
    // cout << dp << endl;
    pair<int,int> last = {-1,-1};
    int most = -1;
    for(int i = 0; i < n; i++) {
        if(dp[0][i]>most) {
            most=dp[0][i];
            last={0,i};
        }
    }
    cout << most+1 << endl;
    while(most!=0) {
        cout << s.substr(last.f, last.s-last.f+1) << endl;
        for(int i = n-1; i >= 0; i--) {
            if(dp[last.s+1][i]==most-1) {
                most--;
                last={last.s+1, i};
                break;
            }
        }
    }
    cout << s.substr(last.f, last.s-last.f+1) << endl;
    return 0;
}