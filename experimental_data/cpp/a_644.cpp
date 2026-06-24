#include <bits/stdc++.h>

#define gc getchar

#define pc putchar

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);



typedef long long ll;

using namespace std;



int mat[100][100];

void display(int x, int y)

{

    for(int i=0; i<x; i++)

    {

        for(int j=0; j<y; j++)

            cout<<mat[i][j]<<" ";

        cout<<endl;

    }

}



int main() {

    _

    int n,a,b;

    cin>>n>>a>>b;

    if(n>a*b)

        cout<<"-1"<<endl;

    else

    {

        int k=1;

        if((b&1) && !(a&1))

        {

            for(int i=0; i<a; i++)

            {

                for(int j=0; j<b; j++)

                {

                    if(k>n)

                    {

                        mat[i][j]=0;

                        continue;

                    }

                    mat[i][j]=k;

                    k++;

                }

            }

            display(a,b);

        }

        if(a==b || ((a&1)&&(b&1)) || (!(a&1)&& !(b&1)))

        {

            for(int i=0; i<a; i++)

            {

                if(!(i&1))

                {

                    for(int j=0; j<b; j++)

                    {

                        if(k>n)

                        {

                            mat[i][j]=0;

                            continue;

                        }

                        mat[i][j]=k;

                        k++;

                    }

                }

                else

                {

                    for(int j=(b-1); j>=0; j--)

                    {

                        if(k>n)

                        {

                            mat[i][j]=0;

                            continue;

                        }

                        mat[i][j]=k;

                        k++;

                    }

                }

            }

            display(a,b);

        }

        if((a&1) && !(b&1))

        {

            for(int i=0; i<b; i++)

            {

                for(int j=0; j<a; j++)

                {

                    if(k>n)

                    {

                        mat[j][i]=0;

                        continue;

                    }

                    mat[j][i]=k;

                    k++;

                }

            }

            display(a,b);

        }

    }

	return 0;

}