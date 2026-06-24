#include <bits/stdc++.h>

#include <iostream>

using namespace std;

#include <stack>

#include <vector>

#include <set>

#include <string>

#include <algorithm>

#include <unordered_map>

#include <unordered_set>

typedef long long int ll;

#define MAX 100001

#include <map>

const int MOD = 1e9 + 7;

const ll MaxVal = 2e18; 

string PI = "314159265358979323846264338327";

map<ll, ll> freq;

vector<ll> power2;

vector<ll> pf;

vector<bool> prime(1000001, true);

string xoazero(string a){

    int i = 0;

    while (i < a.length() - 1 && a[i] == '0')

        i++;

    string res ="";

    for (i; i<a.length() - 1; i++){

        res+=a[i];

    }

    return res;

}

//-5 -3

int cmp(string a, string b){

    if (a.length() > b.length()) return 1;

    else if (a.length() < b.length()) return 0;

    else{

        for (int i=0; i<a.length(); i++){

            if (a[i] > b[i]) return 1;

            else if (a[i] < b[i]) return 0;

        }

    }

    return -1;

}

string sub(string a, string b){

    bool sig = false;

    if (cmp(a, b) == 0){

        swap(a, b);

        sig = true;

    }

    else if (cmp(a, b) == -1){

        string res = "0";

        return res;

    }

    

    while (a.length() > b.length()){

        b = "0" + b;

    }

    while (a.length() < b.length()){

        a = "0" + a;

    }

    int nho = 0;

    // 123

    //-456

    //   3 

    string res = "";

    // cout << a << " " << b;

    for (int i = a.length() - 1; i >= 0; i--){

        int numa = a[i] - '0', numb = b[i] - '0';

        int sum = numa - (numb + nho);

        if (sum < 0){

            sum+=10;

            nho = 1;

        }

        else nho = 0;

        res = to_string(sum) + res;

    }

    //

    string tmp;

    int i = 0;

    while (res[i] =='0' && i < res.length()) i++;

    for (i; i<res.length(); i++){

        tmp+=res[i];

    }

    if (sig){

        tmp = "-" + tmp;

    }

    return tmp;

}



string add(string a, string b){

    if (a.length() < b.length()) return add(b, a);

    while (a.length() > b.length()){

        b = "0" + b;

    }

    string res="";

    int nho = 0;

    for (int i = a.length() -1; i >=0; i--){

        int numa = a[i] - '0', numb = b[i] -'0';

        int sum = numa + numb + nho;

        nho=0;

        int mod = sum%10;

        res = to_string(mod) + res;

        nho+=sum/10;

    }

    if (nho > 0){

        res = to_string(nho) + res;

    }

    // int i = 0;

    // while (res[i] == '0' && i < res.length()) i++;

    // for (i; i<res.length(); i++)

    return res;

}

void solve(){

    int n;

    cin >> n;

    bool checka = false;

    vector<int> a(n), b(n);

    for (int &x: a) cin >> x;

    sort(a.begin(), a.end());

    vector<int> res;

    int i = 0, j = n - 1;

    while (i < j){

        res.push_back(a[j]);

        res.push_back(a[i]);

        ++i;

        --j;

    }

    if (n%2) res.push_back(a[i]);

    reverse(res.begin(), res.end());

    for (int x: res) cout << x << " ";

    cout << '\n';

}   



int main() {

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    

    // for (ll q = 1;q<=MaxVal; q*=2){

    //     power2.push_back(q);

    // }

    // pf.resize(power2.size());

    // pf[0] = power2[0];

    // for (int i=1; i<power2.size(); i++) pf[i] = pf[i - 1] + power2[i];

    int t;

    // t = 1;

    cin >> t;       

    while (t--) solve();    

}