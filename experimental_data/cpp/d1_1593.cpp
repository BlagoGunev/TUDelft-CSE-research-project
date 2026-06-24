#include<bits/stdc++.h>

#define ll long long

#define ull unsigned long long

#define nl cout<<"\n";

#define sp cout<<" ";

#define sz(x) x.size()

#define NumOfDigit(w) log10(w) + 1

#define fill(arr, val)  memset(arr, val , sizeof(arr))

#define PI 3.141592654

#define ceil(w, m) (((w) / (m)) + ((w) % (m) ? 1 : 0))

#define all(v) v.begin(), v.end()

#define rall(v) v.rbegin(), v.rend()

#define fi first

#define se second

#define cin(v) for (auto&i:v) cin >> i;

#define cout(v) for (auto&i:v) cout << i << " ";

#define fixed(n) fixed << setprecision(n)

using namespace std;



void zainab_hamdy(){

    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    //freopen("filename.in" , "r" ,stdin);

#ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);

#endif

}



void isAccepted(){

    int n , ans = 0;  cin >> n ;

    

    vector<int> v(n); cin(v);

 //   sort(all(v));

    for(int i=1;i<n;i++)

        ans=__gcd( ans, abs(v[i] - v[i-1]) );

    

if(ans==0) cout <<"-1";

else cout << ans ;



nl



}



int main(){

                zainab_hamdy();

    int testCase=1;  // one test case

         cin >> testCase;

    while(testCase--)

        isAccepted();  // my code

    return 0;

}