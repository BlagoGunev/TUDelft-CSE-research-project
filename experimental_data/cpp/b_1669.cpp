#include<bits/stdc++.h>

using namespace std;

int main(){

    ios::sync_with_stdio(false);

    cin.tie(0);

    int cases, length, input;

    cin>>cases;

    while(cases--){

        cin>>length;

        map<int, int> cnt;

        while(length--){

            cin>>input;

            if(cnt.count(input) == 0)

                cnt[input] = 1;

            else

                cnt[input]++;

        }

        int ok = 0;

        for(auto it = cnt.begin(); it != cnt.end(); it++){

            if((*it).second >= 3){

                cout<<(*it).first<<endl;

                ok = 1;

                break;

            }

        }

        if(ok == 0)

            cout<<-1<<endl;

    }

}