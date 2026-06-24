#include<bits/stdc++.h>
using namespace std;

const char nl='\n';
#define int long long int 
#define vpii vector<pair<int,int>>
#define pb push_back 
const int inf = LLONG_MAX>>1;
const int ninf=LLONG_MIN>>1;
#define no cout<<"NO"<<nl
#define yes cout<<"YES"<<nl
#define all(x) x.begin(),x.end()

#define print_arr(arr) for(int i=0;i<(sizeof(arr)/sizeof(arr[0]));i++){ cout << arr[i] << " ";}cout << endl;
#define print_vec(v) for(int i=0;i<v.size();i++){ cout << v[i] << " ";}cout << endl;
#define print_map(m) for(auto i: m){ cout << i.first << " " << i.second << endl;}
#define print_set(s) for(auto i:s){ cout<<i<<" ";}cout<<endl;
#define print_vecvec(v) for(int i=0;i<v.size();i++){for(int j=0;j<v[i].size();j++){cout << v[i][j] << " ";}cout << endl;}
#define print_vecpair(v) for(int i=0;i<v.size();i++){cout << v[i].first << " " << v[i].second << endl;}

 /*  
1. Think Greedy
2. Think Brute Force
3. Think solution in reverse order
4. Think DP [ check constraints carefully ]
5. Check base cases for DP and prove solution for Greedy
6. Think Graph 
7. ceil a/b=(a-1+b)/b do remember
8. Take care while converting double/float to integers!!! Add some small double number before conversion!!
throws precision errors!
9. Remember to convert size() to int!
10. XOR is invertible to itself.
11.If x = a mod b then a mod 2b = x or x+a
12. (a+b)modc = (a+b-c)modc
13. Conveyer Belt Matrix = (i+j-1)%max_row_value
*/  

void init2(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

bool cmp(string a,string b){
    if(a.size()!=b.size()) return (a.size()>b.size());
    else return (a>b);
}

void solve(){
    int n;cin>>n;
    vector<string> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    vector<map<int,int>> dp(6);

    int ans=0;
    sort(all(arr),cmp);

    for(int i=n-1;i>=0;i--){
        string s=arr[i];
        int total=0;
        for(auto ch: s) total+=(ch-'0');

        for(int leng=s.size()+2-(s.size()%2);leng<=10;leng+=2){
            if(leng>(2*s.size())) break;

            int a=0,b=0;

            int mid=s.size()-(leng/2);
            for(int c=0;c<mid;c++){
                a+=s[c]-'0';
                b+=s[s.size()-c-1]-'0';
            }
            
            ans+=dp[leng-s.size()][total-(2*a)];
            ans+=dp[leng-s.size()][total-(2*b)];
        }

        dp[s.size()][total]++;
        ans++;

    }
    cout<<ans<<nl;

}


signed main(){
    int t;t=1;
    while(t--){
        solve();
    }
    return 0;
}