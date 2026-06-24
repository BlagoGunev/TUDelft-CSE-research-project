#include<stdio.h>
#include<math.h>
int main()
{
    long long int sum=0,m,d,y,mm,dd,yy,i,j,k,flag=0,a,b,c,di,e,f,flagm=0;

    scanf("%lld:%lld:%lld",&a,&b,&c);
    scanf("%lld:%lld:%lld",&di,&e,&f);
    y=a;
    m=b;
    d=c;
    yy=di;
    mm=e;
    dd=f;

    if(a>di)
    {
        y=di;
        m=e;
        d=f;
        yy=a;
        mm=b;
        dd=c;
    }

    if(a==di)
    {
        if(b>e)
        {
            y=di;
            m=e;
            d=f;
            yy=a;
            mm=b;
            dd=c;
        }
        if(b==e)
        {

            if(c>f)
            {
                y=di;
                m=e;
                d=f;
                yy=a;
                mm=b;
                dd=c;
            }
        }

    }


    yy=yy-1;
    for(i=y+1; i<=yy; ++i)
    {


        if(i%4==0&&i%100!=0&&i%400!=0)
        {
            flag=1;
            sum+=366;
        }
        else if(i%100==0)
        {
            if(i%400==0)
            {
                flag=1;
                sum+=366;
            }
            else
            {
                flag=0;
                sum+=365;
            }
        }
        else
        {
            flag=0;
            sum+=365;
        }
    }


    int flag1=0,flag2=0;
        if(y%4==0&&y%100!=0&&y%400!=0)
        {
            flag1=1;
        }
        else if(y%100==0)
        {
            if(y%400==0)
            {
                flag1=1;
            }
            else
            {
                flag1=0;
            }
        }
        else
        {
            flag1=0;
        }


         if((yy+1)%4==0&&(yy+1)%100!=0&&(yy+1)%400!=0)
        {
            flag2=1;
        }
        else if((yy+1)%100==0)
        {
            if((yy+1)%400==0)
            {
                flag2=1;
            }
            else
            {
                flag2=0;
            }
        }
        else
        {
            flag2=0;
        }


   if(y!=yy+1)
   {
    sum+=dd;
    for(i=1; i<mm; ++i)
    {
        if(i==1)
            sum+=31;
        if(i==2)
        {
            if(flag2==1)
                sum+=29;
            else
                sum+=28;
        }

        if(i==3)
            sum+=31;
        if(i==4)
            sum+=30;
        if(i==5)
            sum+=31;
        if(i==6)
            sum+=30;
        if(i==7)
            sum+=31;
        if(i==8)
            sum+=31;
        if(i==9)
            sum+=30;
        if(i==10)
            sum+=31;
        if(i==11)
            sum+=30;
        if(i==12)
            sum+=31;
    }

    for(i=12; i>m; --i)
    {
        if(i==1)
            sum+=31;
        if(i==2)
        {
            if(flag1==1)
                sum+=29;
            else
                sum+=28;
        }

        if(i==3)
            sum+=31;
        if(i==4)
            sum+=30;
        if(i==5)
            sum+=31;
        if(i==6)
            sum+=30;
        if(i==7)
            sum+=31;
        if(i==8)
            sum+=31;
        if(i==9)
            sum+=30;
        if(i==10)
            sum+=31;
        if(i==11)
            sum+=30;
        if(i==12)
            sum+=31;
    }


    if(m==1)
        sum+=31-d;
    if(m==2)
    {
        if(flag1==1)
            sum+=29-d;
        else
            sum+=28-d;
    }

    if(m==3)
        sum+=31-d;
    if(m==4)
        sum+=30-d;
    if(m==5)
        sum+=31-d;
    if(m==6)
        sum+=30-d;
    if(m==7)
        sum+=31-d;
    if(m==8)
        sum+=31-d;
    if(m==9)
        sum+=30-d;
    if(m==10)
        sum+=31-d;
    if(m==11)
        sum+=30-d;
    if(m==12)
        sum+=31-d;
   }

  if(y==yy+1&&m==mm)
  {
         sum+=dd-d;
  }



   if(y==yy+1&&m!=mm)
   {
       sum+=dd;
       for(i=m+1; i<mm; ++i)
    {
        if(i==1)
            sum+=31;
        if(i==2)
        {
            if(flag2==1)
                sum+=29;
            else
                sum+=28;
        }

        if(i==3)
            sum+=31;
        if(i==4)
            sum+=30;
        if(i==5)
            sum+=31;
        if(i==6)
            sum+=30;
        if(i==7)
            sum+=31;
        if(i==8)
            sum+=31;
        if(i==9)
            sum+=30;
        if(i==10)
            sum+=31;
        if(i==11)
            sum+=30;
        if(i==12)
            sum+=31;
    }

    {

    if(m==1)
        sum+=31-d;
    if(m==2)
    {
        if(flag1==1)
            sum+=29-d;
        else
            sum+=28-d;
    }

    if(m==3)
        sum+=31-d;
    if(m==4)
        sum+=30-d;
    if(m==5)
        sum+=31-d;
    if(m==6)
        sum+=30-d;
    if(m==7)
        sum+=31-d;
    if(m==8)
        sum+=31-d;
    if(m==9)
        sum+=30-d;
    if(m==10)
        sum+=31-d;
    if(m==11)
        sum+=30-d;
    if(m==12)
        sum+=31-d;
    }

   }


    printf("%lld\n",sum);
   return 0;

}