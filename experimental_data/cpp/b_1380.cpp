#include <bits/stdc++.h>

#include <cmath>

using namespace std;

 

#define fori(v) for(auto it=v.begin();it!=v.end();it++)

#define cin(v) for(auto &i : v) cin>>i;

#define cout(v) for(auto &i : v) cout<<i<<" "; cout<<"\n"

#define maxe(v) max_element(v.begin(),v.end())

#define mine(v) min_element(v.begin(),v.end())

#define fin(i,a,b) for(int i=a;i<b;i++)

#define fdec(i,a,b) for(int i=a;i>=b;i--)

#define endl "\n"

#define all(a) a.begin(),a.end()

#define int long long int

#define vint vector <int>

#define ff first

#define ss second

const int  M=1e9+7;

const int N=1e6;

 

void myprog();

int32_t main(){    

#ifndef ONLINE_JUDGE

    freopen("input.txt","r",stdin);

    freopen("output.txt","w",stdout);

#endif

    ios_base::sync_with_stdio(false);

    cin.tie(0);

    cout.tie(0);

    int t;

    cin >> t; // number of test cases

    while (t-- > 0)

    {

        myprog();

    }

    //myprog();

    return 0;

}

vector<int> primeFactors(int n){

    vector <int> an;

    while (n%2==0){

        an.push_back(2);

        n=n/2;

    }

    for(int i=3;i<=sqrt(n);i=i+2){

        while(n%i==0){

            an.push_back(i);

            n = n/i;

        }

    }

    if(n>2)an.push_back(n);

    return an;

}

 int dist(vector <int> arr){

    int n=arr.size();

    unordered_set <int> s;

    int res = 0;

    for (int i=0;i<n;i++) {

        if (s.find(arr[i]) == s.end()){

            s.insert(arr[i]);

            res++;

        }

    }

 

    return res;

}

int ncr(int n,int k){

    int res = 1;

    if(k>n-k)

        k=n-k;

    fin(i,0,k) {

        res*=(n-i);

        res/=(i+1);

    }

    return res;    

 }

int power(int x,int y){

    int temp;

    if (y == 0)return 1;

    temp=power(x,y/2);

    if (y % 2 == 0)return temp * temp;

    else return x*temp*temp;

}

int fact(int n){

    int f=1;

    fin(i,1,n+1)f*=i%M;

    return f;

}

int _ceil(int a,int b){

    if(a==0) return 0;

    return (a%b==0?a/b:a/b+1);

}

int sum_digits(int n){

    int sum=0;

    while(n>0){

        sum+=n%10;

        n/=10;

    }

    return sum;

}

void myprog(){

    string x;

    cin>>x;

    int n=x.size();

    int r=0,p=0,s=0;

    fin(i,0,n){

        if(x[i]=='R')r++;

        if(x[i]=='P')p++;

        if(x[i]=='S')s++;

    }

    if(r>=p&&r>=s){

        fin(i,0,n)cout<<"P";

    }

    else if(p>=r&&p>=s){

        fin(i,0,n)cout<<"S";

    }

    else{

        fin(i,0,n)cout<<"R";

    } 

    cout<<endl;

}



// 6

// 15

// 1434

// 1

// 6

// 7

// 36

// 1

// 1