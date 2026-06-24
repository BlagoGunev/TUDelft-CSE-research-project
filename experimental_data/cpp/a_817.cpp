#include<stdio.h>
#include<stdlib.h>
int main()
{
	int x1,y1,x2,y2,x,y;
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	scanf("%d%d",&x,&y);
	int diffX,diffY,remX,remY;
	diffX=abs(x2-x1);
	diffY=abs(y2-y1);
	remX=((diffX)%x);
	remY=((diffY)%y);
	int a1=diffX/x;
	int b1=diffY/y;
	if((remX==0)&&(remY==0))
	{
		if((a1-b1)%2==0){
		printf("YES");

		}
		else{
				printf("NO");
			
		}		
	}
	else{
			printf("NO");
	}
	return 0;
}