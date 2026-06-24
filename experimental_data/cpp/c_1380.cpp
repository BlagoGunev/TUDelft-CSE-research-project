/*

    سَبِّحِ اسْمَ رَبِّكَ الأَعْلَى

        الَّذِي خَلَقَ فَسَوَّى

        وَالَّذِي قَدَّرَ فَهَدَ

        وَالَّذِي أَخْرَجَ الْمَرْعَى

        فَجَعَلَهُ غُثَاءً أَحْوَى

         سَنُقْرِؤُكَ فَلا تَنسَى

    إِلاَّ مَا شَاء اللَّهُ إِنَّهُ يَعْلَمُ الْجَهْرَ وَمَا يَخْفَى

            وَنُيَسِّرُكَ لِلْيُسْرَى

فَذَكِّرْ إِن نَّفَعَتِ الذِّكْرَى

*/

#include <bits/stdc++.h>

#define int long long

#define NEGO cin.tie(0), cout.tie(0), cin.sync_with_stdio(0), cout.sync_with_stdio(0);

#define END return 0;

#define E '\n'

using namespace std;

/*بسم الله الرحمن الرحيم

اللهم صلي علي سيدنا محمد

 */



signed main()

{

    NEGO

    int t=1;

    cin>>t;

    while(t--)

    {

      int n,x;cin>>n>>x;

      vector<int> nums(n);

      vector<int> need(n);

      for (int i = 0; i <n ; ++i)

      {

            cin>>nums[i];

      }

      std::sort(nums.begin(), nums.end());

      std::reverse(nums.begin(), nums.end());

      int ans = 0;

      int curr = 0;

      for (int i = 0; i < n; ++i)

      {

           curr++;

           if(nums[i]*curr >= x)

           {

               curr = 0;

               ans++;

           }



      }

      cout<<ans<<E;













    }









    END

}