#include<stdio.h>
int a[100001];
int main()
{
    int n,l,r,ql,qr,sum=0,tr,tl,first,last,i,su=0,s,min=1000000000;
    scanf("%d %d %d %d %d",&n,&l,&r,&ql,&qr);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        su+=a[i];
        }
/*    first=1;
    last=n;
    tl=0;
    tr=0;
    while(last>=first)
    {
        if(l*a[first]+ql*tl>r*a[last]+qr*tr)
        {
            sum+=r*a[last]+qr*tr;
            printf("%d ",sum);
            last--;
            if(tr==0)
            tr++;
            tl=0;
            }
        else
        {
            sum+=l*a[first]+ql*tl;
            printf("%d ",sum);
            first++;
            if(tl==0)
            tl++;
            tr=0;
            }
        }*/
    s=0;
    for(i=0;i<=n;i++)
    {
        sum=0;
        if(n-i>i)
        sum+=qr*(n-2*i-1);
        else if(n-i<i)
        sum+=ql*(2*i-n-1);
        sum+=s*l;
        sum+=(su-s)*r;
        s+=a[i+1];
//        printf("%d\n",sum);
        if(sum<min)
        min=sum;
        }
    printf("%d",min);
    scanf(" ");
    }