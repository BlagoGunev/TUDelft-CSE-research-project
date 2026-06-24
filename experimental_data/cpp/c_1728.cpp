#include<bits/stdc++.h>

using namespace std;

#define int long long

#define tcase cout<<"test case : "<<tc<<endl

#define all(a) a.begin(),a.end()

#define sortu(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))

int const mod =1000000007;

int const inf=LLONG_MAX;

int const N=1000005;



// void f(int i)





void solve(){

    int n;

    cin>>n;



    priority_queue<int> a;

    priority_queue<int> b;



    for(int i=0;i<n;i++){

        int x;

        cin>>x;



        a.push(x);

    }

    for(int i=0;i<n;i++){

        int x;

        cin>>x;



        b.push(x);

    }



    int ans=0;

    while(!a.empty() && !b.empty()){

        if(a.top() == b.top()){

            a.pop();

            b.pop();

        }else if(a.top() > b.top()){

            ans++;

            string str=to_string(a.top());

            a.pop();

            if(str.size()==1)a.push(1);

            else a.push(str.size());



        }else{

            ans++;

            string str=to_string(b.top());

            b.pop();

            if(str.size()==1)b.push(1);

            else b.push(str.size());



        }

    }



    cout<<ans<<endl;





}

signed main() {



    ios_base::sync_with_stdio(false);

    cin.tie(nullptr);

    cout.tie(nullptr);



    int t;

    cin>>t;

    // t=1;



    for(int tc=1;tc<=t;tc++){

        // tcase;

        solve();

    }









}