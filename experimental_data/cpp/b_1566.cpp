//  B. MIN-MEX Cut

// "Abdelkareem Elkhatib" 

//! وَٱسۡتَعِینُوا۟ بِٱلصَّبۡرِ وَٱلصَّلَوٰةِۚ وَإِنَّهَا لَكَبِیرَةٌ إِلَّا عَلَى ٱلۡخَـٰشِعِینَ

#include<bits/stdc++.h>

#include<iostream>



#define  el "\n"

#define  db(x)    cout << "DEBUG: "<< x << el;

#define sln(n) sizeof(n)/sizeof(n[0])

#define arri(arr, n) for(int i = 0 ; i < n ; cin >> arr[i] , i++)

#define arro(arr, n) for(int n : arr) cout << n //<<el

#define vec vector

#define sorto(v) sort(v.begin(),v.end())

#define reverseo(v) reverse(v.begin(),v.end())

using namespace std;

typedef long long ll;

//typedef unsignd long long ull;

//typedef unsigneed int uint;

//const double pi = acos(-1.0);

//int arr[1000000];

//string s, s2, s3;

// Functions Declarations:

//bool is_prime(int n) {

//    if (n == 2 || n == 3) return true;

//    for (int i = 2; i * i <= n; ++i) {

//        if (n % i == 0) return false;

//    }

//    return true;

//}

//int findlastindex(string& str,char x){

//    for(int i=str.length()-1;i>=0;i--)

//        if(str[i]==x)

//            return i;

//    return -1;

set<ll> v;

//void primeFactors(ll n)

//{

//    while (n % 2 == 0)

//    {

//        v.insert(2);

//        n = n/2;

//    }

//    for (ll i = 3; i <= sqrt(n); i = i + 2)

//    {

//        while (n % i == 0)

//        {

//            v.insert(i);

//            n = n/i;

//        }

//    }

//    if (n > 2)

//        v.insert(n);

//}

const ll INF = (1LL << 60) - 1;



inline void kobo() {

    ios_base::sync_with_stdio(0);

    cin.tie(0);

    cout.tie(0);

}

void sovle(){

    string s;

    cin>>s;

    bool f0 = false,f01=false,f010= false;

    for(char c:s){

        if(c=='0') {

            f010 |= f01;

            f0 = true;

        }else{

            f01|=f0;

        }

    }

    if(f010){

        cout<<2<<el;

    }else if(f0)

        cout<<1<<el;

    else

        cout<<0<<el;

}

int main() {

    kobo();

    int t;

    cin>>t;

    while(t--){

        sovle();

    }

    return 0;//Q.E.D ^_^

}