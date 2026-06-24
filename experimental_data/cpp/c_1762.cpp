#include<bits/stdc++.h>

using namespace std;



int main ()

{

    #ifndef ONLINE_JUDGE

    

        // For getting input from input.txt file

        freopen("input.txt", "r", stdin);

    

        // Printing the Output to output.txt file

        freopen("output.txt", "w", stdout);



        // Printing the run time of code in Terminal

        class Timer { chrono::time_point <chrono::steady_clock> B, E; public: Timer () : B(), E()

        { B = chrono::steady_clock::now(); } ~Timer () { E = chrono::steady_clock::now();

        cerr << "\nDuration: " << ((chrono::duration <double>)(E - B)).count() << "s\n"; } } TimerT;

    

    #endif



    // For faster Input / Output

    ios_base::sync_with_stdio(false);

    cin.tie(NULL); 

    int testcase;

    cin >> testcase;

    long long int M= 998244353;

    for(int ta = 0; ta < testcase; ta++) 

    {

        long long int n;

        cin>>n;

        string s;

        cin>>s;

        long long int ans=1,fact=1;

        for(int i=1;i<n;i++){

            if(s[i-1]==s[i]){

                fact*=2;

                fact= fact%M;

                ans+=fact;

                ans= ans%M;

            }

            else{

                ans+=1;

                ans=ans%M;

                fact=1;

            }

        }

        cout<<ans<<endl;

    }

    return 0;

}