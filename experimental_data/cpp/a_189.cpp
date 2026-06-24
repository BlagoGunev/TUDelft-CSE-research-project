#include <cmath>

#include <cstdio>

#include <vector>

#include <iostream>

#include <map>

#include <algorithm>

using namespace std;









int main() {

    

    int n;

    cin>>n;

    vector<int> values;

    for(int i = 0; i < 3; i++){

        int temp;

        cin>>temp;

        values.push_back(temp);

    }

    

    int dp[4010][3] = {0};

    dp[0][0] = 1;

    dp[0][1] = 1;

    dp[0][2] = 1;

    

    int truei = 0;

    for(int i = 0; i <= n; i++){

        

        if(dp[i][0] != 0){

            if(i+values[0] <= n){

                dp[i+values[0]][0] = max(dp[i][0]+1,dp[i+values[0]][0]);

            }

            if(i+values[1] <= n){

                dp[i+values[1]][0] = max(dp[i][0]+1,dp[i+values[1]][0]);

            }

            if(i+values[2] <= n){

                dp[i+values[2]][0] = max(dp[i][0]+1,dp[i+values[2]][0]);

            }

        }

        if(dp[i][1] != 0){

            if(i+values[0] <= n){

                dp[i+values[0]][1] = max(dp[i][1]+1,dp[i+values[0]][1]);

            }

            if(i+values[1] <= n){

                dp[i+values[1]][1] = max(dp[i][1]+1,dp[i+values[1]][1]);

            }

            if(i + values[2] <= n){

                dp[i+values[2]][1] = max(dp[i][1]+1,dp[i+values[2]][1]);

            }

        }

        if(dp[i][2] != 0){

            if(i+values[0] <= n){

                dp[i+values[0]][2] = max(dp[i][2]+1,dp[i+values[0]][2]);

            }

            if(i+values[1] <= n){

                dp[i+values[1]][2] = max(dp[i][2]+1,dp[i+values[1]][2]);

            }

            if(i + values[2] <= n){

                dp[i+values[2]][2] = max(dp[i][2]+1,dp[i+values[2]][2]);

            }

        }

        

        

        //dp[i][1] += min(dp[i-1][0], min(dp[i-1][1], dp[i-1][2])) + values[1];

        //dp[i][2] += min(dp[i-1][0], min(dp[i-1][1], dp[i-1][2])) + values[2];

        /*

        if(dp[i][0] > n){

            dp[i][0] = INT_MAX;

        }

        if(dp[i][1] > n){

            dp[i][1] = INT_MAX;

        }

        if(dp[i][2] > n){

            dp[i][2] = INT_MAX;

        }

         */

        

        //cout<<i<<" "<<dp[i][0]<<" "<<dp[i][1]<<" "<<dp[i][2]<<endl;



    }

    

    cout<<max(dp[n][0],max(dp[n][1], dp[n][2]))-1;

    

    

    return 0;

}