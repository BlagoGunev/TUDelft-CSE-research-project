#include <iostream>



using namespace std;



int main()

{

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int T; cin>>T;



    while (T--){

        int N, K, ans = (1<<30) - 1; cin>>N;

        for (int i=0; i<N; i++){

            cin>>K;

            if (K != i) ans &= K;

        }

        cout<<ans<<"\n";

    }

    return 0;

}