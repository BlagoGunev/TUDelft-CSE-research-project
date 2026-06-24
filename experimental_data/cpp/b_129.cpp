#include<bits/stdc++.h>
using namespace std;

pair<int, int>p[5000];
int a[105];
stack <int>q;
int main()
{
       int n, m, i, j, c = 0;
       cin >> n >> m;
       for(i = 0; i < m; i++) {
              cin >> p[i].first >> p[i].second;
              a[p[i].first]++;
              a[p[i].second]++;
       }
       int k = 1;
       while(k != 0) {
              k = 0;
              for(j = 0; j < m; j++) {
                    if(a[p[j].first] == 1) {
                          k = 1;
                          a[p[j].first] = 0;
                          q.push(p[j].second);
                          p[j].first = 0;
                          p[j].second = 0;
      
                    } else if(a[p[j].second] == 1) {
                          k = 1;
                          a[p[j].second] = 0;
                          q.push(p[j].first);
                          p[j].first = 0;
                          p[j].second = 0;
                    }

               }
               if(k == 1) {
                    c++;
               }
               while(!q.empty()) {
                    a[q.top()]--;
                    q.pop();
               }
        }
        cout << c;
        return 0;
}