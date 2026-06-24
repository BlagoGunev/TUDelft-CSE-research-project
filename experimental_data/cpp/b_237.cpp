/***********************************************

 |Author: Fry

 |Created Time: 2016/7/13 13:47:02

 |File Name: A.CPP

 |Copyright: 

 |  For personal use, feel free to use

 |  Otherwise call me at http://blog.csdn.net/fry_guest 

***********************************************/

#include <iostream>

#include <algorithm>

#include <stdio.h>

using namespace std;

const int N=55;

void swap(int &a,int &b){int c=a; a=b; b=c;}

int a[N][N],num[N*N];

int x1[N*N],y1[N*N],x2[N*N],y2[N*N];

int main()

{

	int n,sum,ans,x,y,q,w;

	while (~scanf("%d",&n)){

		sum=ans=0;

		for (int i=1;i<=n;i++) scanf("%d",&a[i][0]);	

		for (int i=1;i<=n;i++){

			for (int j=1;j<=a[i][0];j++){

				scanf("%d",&a[i][j]);

				num[sum++]=a[i][j];

			}

		}

		sort(num,num+sum);

		x=1;y=1;

		for (int c=0;c<sum;c++){

			for (int i=1;i<=n;i++){

				for (int j=1;j<=a[i][0];j++){

					if (a[i][j]==num[c]){

						q=i; w=j;

						goto A;

					}

				}

			}

			A:;

			if (x!=q||y!=w){

				swap(a[x][y],a[q][w]);

				x1[ans]=q; y1[ans]=w;

				x2[ans]=x; y2[ans]=y;

				ans++;

			}

			y++;

			if (y>a[x][0]) {

				y=1;

				x++;

			}

		}

		printf("%d\n",ans);

		for (int i=0;i<ans;i++){

			printf("%d %d %d %d\n",x1[i],y1[i],x2[i],y2[i]);

		}

	}

	return 0;

}