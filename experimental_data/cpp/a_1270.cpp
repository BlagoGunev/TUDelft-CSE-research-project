#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;
    vector<int>v;
    int x, y , z;
    int max1 = 0, max2 = 0, maxx = 0;
    for (int i = 0; i < t; i++){
        cin >> x >> y >> z;
        int q[y];
        int w[z];
        for(int j = 0; j < y; j++){
            scanf("%d", &q[j]);

        }
        sort(q, q+y);
        max1 = q[y-1];
        for(int k = 0; k < z; k++){
            scanf("%d", &w[k]);
        }
        sort(w, w+z);
        max2 = w[z-1];
        if (max1 > max2){
        v.push_back(1);
        }
        else{
            v.push_back(0);
        }
    }
    for(int i = 0; i < v.size(); i++){
        if (v[i])
            printf("%s\n", "YES");
        else
            printf("%s\n", "NO");
    }

    return 0;
}