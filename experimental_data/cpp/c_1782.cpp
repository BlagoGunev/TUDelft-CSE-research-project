#include<bits/stdc++.h>

using namespace std;



#define int long long

#define F first

#define S second

#define pb push_back

#define mp make_pair

typedef vector<int> vi;

typedef pair<int,int> pi;

 

signed main()

{

    ios::sync_with_stdio(0);

    cin.tie(0);

    cout.tie(0);

   

    int t;

    cin >> t;



    while (t--) {

      int n;

      string s;

      vi ct(26,0), c1(26,0), c2(26,0);

      pair<int, char> v1[26] ;



      cin >> n >> s;



      for(int i = 0; i < 26; i++) {

         v1[i].first = 0;

         v1[i].second = (char) ('a' + i);

      }



      for(int i = 0; i < n; i++) {

        ct[s[i] - 'a']++;

        c1[s[i] - 'a']++;

        v1[s[i] - 'a'].first = ct[s[i] - 'a']; 

        v1[s[i] - 'a'].second = s[i]; 

      }



      sort(ct.rbegin(), ct.rend());

      sort(v1, v1+26);

      reverse(v1, v1+26);



      int k, cnt=1e18, ct1;



      for(int i = 1; i <= n; i++) {

         if(n%i || n/i > 26) continue;

         int tmp = n/i;

         int t1 = 0, t2 = 0;

         for(int j = 0; j < 26 && j < tmp; j++){

            if(ct[j] > i) t1 += ct[j] - i;

            else if(ct[j] < i)  t2 += i - ct[j];

         }

         if(t1 < t2) t1 += t2 - t1;

         if(cnt > t1){

            cnt = t1;

            k = i;

            ct1 = n/i;

         }

    }

    cout << cnt << "\n";

   

    for(int i = 0; i < ct1; i++) {

      c2[v1[i].second - 'a'] = k;

    }



    /*for(int i = 0; i < 26; i++) {

      cout << c2[i] << " " << char ('a' + i) << endl;

    }*/



    for(int i = 0; i < n && cnt; i++) {

       if(c1[s[i] - 'a'] > k && c2[s[i] - 'a'] == k) {

        int u = -1;

         for(int p = 0; p < 26; p++) {

           if(c1[p] < k && c1[p] > 0 && c2[p] == k) {

            u = p;

            break;

           }

         }

         if(u != -1) {

          c1[u]++;

          c1[s[i] - 'a']--;

          s[i] = (char) ('a' + u);

         }

         else {

          for(int p = 0; p < 26; p++) {

            if(c1[p] == 0 && c2[p] == k) {

              u = p;

              break;

            }

          }

          c1[s[i] - 'a']--;

          c1[u]++;

          s[i] = (char) ('a' + u);

         }

         cnt--;

       }

       else if(c2[s[i] - 'a'] == 0) {

        int u = -1;

         for(int p = 0; p < 26; p++) {

           if(c1[p] < k && c1[p] > 0 && c2[p] == k) {

            u = p;

            break;

           }

         }

         if(u != -1) {

          c1[u]++;

          c1[s[i] - 'a']--;

          s[i] = (char) ('a' + u);

         }

         else {

          for(int p = 0; p < 26; p++) {

            if(c1[p] == 0 && c2[p] == k) {

              u = p;

              break;

            }

          }

          c1[u]++;

          c1[s[i] - 'a']--;

          s[i] = (char) ('a' + u);

         }

         cnt--;

       }

       

    }

    cout << s << "\n";

  }

}