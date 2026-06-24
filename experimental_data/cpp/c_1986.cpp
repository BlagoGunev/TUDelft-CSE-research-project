#include <bits/stdc++.h>
using namespace std;

// datatype definations start //

#define ll long long
#define lld long double
#define ull unsigned long long
#define endl "\n"

// datatype definations end //


// functions start //

class SparseTable{
    
    vector<int> internalVector;
    vector<vector<int>> sparse;
    int n;
    
    bool valid = true;
    
    int logn;
    
    string typeF;
    void build(){
        for(int i=0;i<n;i++){
            sparse[i][0] = internalVector[i];
        }
        
        for(int j=1;j<=logn;j++){
            for(int i=0;i+(1<<j)-1<n;i++){
                if(typeF=="min"){
                    sparse[i][j] = min(sparse[i][j-1], sparse[i+(1<<(j-1))][j-1]);
                } else if(typeF=="max"){
                    sparse[i][j] = max(sparse[i][j-1], sparse[i+(1<<(j-1))][j-1]);
                } else if(typeF=="gcd"){
                    sparse[i][j] = __gcd(sparse[i][j-1], sparse[i+(1<<(j-1))][j-1]);
                } else if(typeF=="or"){
                    sparse[i][j] = sparse[i][j-1] | sparse[i+(1<<(j-1))][j-1];
                } else if(typeF=="and"){
                    sparse[i][j] = (sparse[i][j-1] & sparse[i+(1<<(j-1))][j-1]);
                }
            }
        }
    }
    
    public:
    
    SparseTable(vector<int> &v, string typeF) : typeF(typeF){
        
        n = v.size();
        if(n==0 || (typeF!="min" && typeF!="max" && typeF!="gcd" && typeF!="or" && typeF!="and")){
            valid = false;
            if(n==0){
                "please enter a valid vector";
            } else{
                cout<<"please enter a valid type"<<endl;
            }
        } else {
            logn = 31 - __builtin_clz(n);
            internalVector = v;
            sparse = vector<vector<int>>(n, vector<int>(logn+1, 0));
            build();
        }
    }
    
    int query(int l, int r){
        if(l>r || l<0 || r>=n){
            cout<<"please enter valid positions."<<endl;
            return -1;
        }
        if(!valid){
            cout<<"query not possible, table is not valid"<<endl;
            return -1;
        }
        int len = r-l+1;
        int loglen = 31 - __builtin_clz(len);
        if(typeF=="min"){
            return min(sparse[l][loglen], sparse[r-(1<<loglen)+1][loglen]);
        } else if(typeF=="max"){
            return max(sparse[l][loglen], sparse[r-(1<<loglen)+1][loglen]);
        } else if(typeF=="gcd"){
            return __gcd(sparse[l][loglen], sparse[r-(1<<loglen)+1][loglen]);
        } else if(typeF=="or"){
            return (sparse[l][loglen] | sparse[r-(1<<loglen)+1][loglen]);
        } else if(typeF=="and"){
            return (sparse[l][loglen] & sparse[r-(1<<loglen)+1][loglen]);
        }
    }
};

// functions end //

// debugger start //

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " -> "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

template<class T> void _print(T a){cerr << a;}

template<class T, class U> void _print(pair<T,U> a){cerr<<"(";_print(a.first);cerr<<", ";_print(a.second);cerr<<")";}
template<class T> void _print(vector<T> v1){cerr <<"[ ";for(T i: v1){_print(i);cerr<<" ";}cerr << "]";}
template<class T> void _print(set<T> s1){cerr <<"[ ";for(T i: s1){_print(i);cerr<<" ";}cerr << "]";}
template<class T> void _print(multiset<T> s1){cerr <<"[ ";for(T i: s1){_print(i);cerr<<" ";}cerr << "]";}
template<class T> void _print(unordered_set<T> s1){cerr <<"[ ";for(T i: s1){_print(i);cerr<<" ";}cerr << "]";}
template<class T, class U> void _print(map<T, U> mp){cerr <<"[ ";for(pair<T, U> i: mp){_print(i);cerr<<" ";}cerr << "]";}
template<class T, class U> void _print(multimap<T, U> mp){cerr <<"[ ";for(pair<T, U> i: mp){_print(i);cerr<<" ";}cerr << "]";}
template<class T, class U> void _print(unordered_map<T, U> mp){cerr <<"[ ";for(pair<T, U> i: mp){_print(i);cerr<<" ";}cerr << "]";}

// debugger end //



int main(){
    
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif

    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        string s;
        cin>>s;
        int arr[m];
        for(int i=0;i<m;i++) {
            cin>>arr[i];
            arr[i]--;
        }
        string x;
        cin>>x;

        sort(arr, arr+m);
        sort(x.begin(), x.end());
        set<int> st;
        int l = 0;
        for(int i=0;i<m;i++){
            if(st.count(arr[i])) continue;
            s[arr[i]] = x[l];
            l++;
            st.insert(arr[i]);
        }
        cout<<s<<endl;

    }
    
}