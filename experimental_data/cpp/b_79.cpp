#include <bits/stdc++.h>

using namespace std;





int count_(int i1 , int j1, int m){

    return i1*m + j1 + 1;

}



vector<pair<int,int> > waste;

string ans[] = {"Grapes" ,"Carrots" , "Kiwis"};



int main(){

    int n , m, k ,t;

    int a , b;

    int cnt;

    int x , y;

    int sum;



    cin >> n >> m >> k >> t;

    waste.resize(k);

    for(int i = 0 ; i < k ; i++){

        cin >> a >> b;

        waste[i].first = a-1;

        waste[i].second = b-1;

    }



    while(t--){

        cin >> x >> y;

        x--;

        y--;

        cnt = 0;

        sum = count_(x,y,m);

        for(int i = 0 ; i < waste.size() ; i++){

            if(count_(waste[i].first , waste[i].second ,m) < sum){

                cnt++;

            }else if(count_(waste[i].first , waste[i].second ,m) == sum){

                sum = -1;

                break;

            }

        }

        sum -= cnt;

        if(sum < 0){

            cout << "Waste\n";

        }else{

            cout << ans[sum % 3] << "\n";

        }

    }

}