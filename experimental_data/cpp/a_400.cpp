#include<iostream>

using namespace std;

int main()

{

    int test,i,j,mark[10],a,b,counter;

    char line[15];

    cin>>test;

    while(test--)

    {

        cin>>line;

        for(i=0;i<12;i++)

        {

            mark[0]=0;

            for(j=0;j<12;j++)

            {

                if(line[j]=='X')

                {

                    mark[0]=1;

                }

            }

            mark[1]=0;

            for(j=0;j<6;j++)

            {

                if(line[j]=='X'&&line[j+6]=='X')

                {

                    mark[1]=1;

                }

            }

            mark[2]=0;

            for(j=0;j<4;j++)

            {

                if(line[j]=='X'&&line[j+4]=='X'&&line[j+8]=='X')

                {

                    mark[2]=1;

                }

            }

            mark[3]=0;

            for(j=0;j<3;j++)

            {

                if(line[j]=='X'&&line[j+3]=='X'&&line[j+6]=='X'&&line[j+9]=='X')

                {

                    mark[3]=1;

                }

            }

            mark[4]=1;

            a=0;

            b=0;

            for(j=0;j<12;j++)

            {

                if(j%2==0&&line[j]=='O')

                {

                    a=1;

                }

                else if(j%2==1&&line[j]=='O')

                {

                    b=1;

                }

            }

            if(a==1&&b==1)

            {

                mark[4]=0;

            }

            mark[5]=1;

            for(j=0;j<12;j++)

            {

                if(line[j]=='O')

                {

                    mark[5]=0;

                }

            }

        }

        counter=0;

        for(j=0;j<6;j++)

        {

            if(mark[j]==1)

            {

                counter++;

            }

        }

        cout<<counter;

        if(mark[0]==1)

        {

            cout<<" 1x12";

        }

        if(mark[1]==1)

        {

            cout<<" 2x6";

        }

        if(mark[2]==1)

        {

            cout<<" 3x4";

        }

        if(mark[3]==1)

        {

            cout<<" 4x3";

        }

        if(mark[4]==1)

        {

            cout<<" 6x2";

        }

        if(mark[5]==1)

        {

            cout<<" 12x1";

        }

        cout<<endl;

    }

    return 0;

}