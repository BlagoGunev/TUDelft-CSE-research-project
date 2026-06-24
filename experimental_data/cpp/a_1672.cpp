#include <iostream> 

#include <vector>



using namespace std;







int main () {

    int t; cin >> t;

    



    while(t--){

        int n; cin >> n;

        vector<int>v(n);

        int count = 0;

        for(int i = 0; i < v.size(); i++) {

            cin >> v[i];

            if (v[i] > 1 ) {

                count += v[i] - 1;

            }

        

        //cout<<count<<endl;

        }

        if (count % 2 == 0) {

            cout<<"maomao90"<<endl;

        }    

        else{

            cout<<"errorgorn"<<endl;

        }

    }

}