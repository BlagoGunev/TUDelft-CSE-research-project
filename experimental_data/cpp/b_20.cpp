#include<stdio.h>

#include<math.h>

#include<algorithm>

using namespace std;

int main()

{

    double  a,b,c;

    scanf("%lf%lf%lf",&a,&b,&c);

    if(a==0)

    {

        if(b==0)

        {

            if(c==0)

            {

                printf("-1\n");

            }

            else

                printf("0\n");

        }

        else

        {

            double q=-c/b;

            printf("1\n");

            printf("%.10lf\n",q);

        }

    }

    else

    {

        double d=b*b-4*a*c;

        if(d>0)

        {

            double q1=(-b+sqrt(b*b-4*a*c))/(2*a);

            double q2=(-b-sqrt(b*b-4*a*c))/(2*a);

            printf("2\n");

            if(q1>q2)

                swap(q1,q2);

            printf("%.10lf\n",q1);

            printf("%.10lf\n",q2);

        }

        else if(d==0)

        {

            printf("1\n");

            double q1=(-b)/(2*a);

            printf("%.10lf\n",q1);

        }

        else

        {

            printf("0\n");

        }

    }

}