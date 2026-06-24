#include<bits/stdc++.h>

using namespace std;



vector<int> balls;



int CO(int i , int x)

{

    int cnt=0;

    if(i == balls.size()-1)

                return cnt;

    if(balls[i+1] != balls[i])

                return cnt ;

    while(i < balls.size() && balls[i] == x)

    {

        cnt++;

        i++;

    }

    int bw = i-cnt-1, fw=i ,cur = 10000;



    if(balls[bw] == balls[fw])

        cur=balls[bw];

    else

        return cnt;



    int next1=cur,next2=cur, c=0;

    bool ok1 =0, ok2 =0;

    while(1)

    {

        if(fw < balls.size() && balls[fw] == cur)

        {

            fw++;

            c++;

            ok1=false;

        }

        else

            {

                int sizevec=balls.size()-1;

                int ind=min(fw,sizevec);

                next1=balls[ind] ;

                ok1 = true;

             }



        if(bw >= 0 && balls[bw] == cur)

        {

            bw--;

            c++;

            ok2=false;

        }

        else

            next2=balls[max(0,bw)], ok2=true;



        if(ok2 && ok1)

        {

            if(c >= 3)

                cnt+=c, c=0;

            else

                break;

            if(next1 == next2 )

                cur = next2;

            else

                break;

        }

    }



    return cnt;

}

int main ()

        {

            int N, k, x;

            cin>>N >> k >> x;

            for(int i=0;i<N;i++)

                {

                    int y;

                    cin>>y;

                    balls.push_back(y);

                }



            bool yes=true;

            int res=0;

            for(int i=0;i<balls.size();i++)

                {

                    if(balls[i] != x)

                        {

                            yes=true;

                            continue ;

                        }

                    if(yes)

                            res=max(res,CO(i,x));



                    yes=false;



                }



            cout<<res<<"\n";

            return 0;

        }