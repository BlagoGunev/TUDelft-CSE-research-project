#include <bits/stdc++.h>

#include <string>

using namespace std;

typedef long long ll;

typedef string str;

#include <ext/pb_ds/assoc_container.hpp>

#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

void init_code()

{

#ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

#endif

}

ll c = 1;

void Case()

{

    cout << "Case #" << c << ": ";

    c++;

}

ll min2(ll a, ll b)

{

    if (a < b)

        return a;

    else

        return b;

}

ll max2(ll a, ll b)

{

    if (a > b)

        return a;

    else

        return b;

}













int main()

{

    init_code();

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    cout.tie(NULL);



    // 



        int t;

        // cin>>t;





        

        

        

        

        t=1;

        

        while(t-->0){

            // Case();

            //





            int n;

            cin>>n;

            string s;

            cin>>s;



            string s2="";

            int f=0;

            for(auto i:s){

                if(i=='0' && f==1){

                    s2+=i;

                }

                else if(i=='1'){

                    f=1;

                    s2+=i;

                }

            }

            if(s2.size()==0) s2+='0';

            s=s2;

            n=s2.size();



            int ind =-1;



            for(int i=0;i<n;i++){

                if(s[i]=='0'){

                    ind=i;

                    break;

                }

            }



            if(ind ==-1){

                cout<<s<<"\n";

            }

            else{

                string ans=s;



            



                int len = n-ind;



                for(int i=0;i<ind;i++){

                    vector<int> pp;

                    for(int j=0;j<len;j++){

                        if(s[i+j]=='1' && s[ind+j]=='0') {

                            pp.push_back(ind+j);

                        }

                    }

                    string temp=s;

                    for(auto j:pp){

                        temp[j]='1';

                    }

                    // cout<<temp<<" ";

                    for(int j=0;j<n;j++){

                        if(temp[j]=='1' && ans[j]=='0'){

                            ans=temp;

                            break;

                        }

                        else if(ans[j]=='1' && temp[j]=='0') {

                            break;

                        }

                    }



                }

                cout<<ans<<"\n";

            }



            



                

            //



        }



    

    return 0;

}