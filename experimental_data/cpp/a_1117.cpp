#include<stdio.h>
void swap(int* arr,int a,int b)
{
	int temp=arr[a];
	arr[a]=arr[b];
	arr[b]=temp;
}
void QuickSort(int* arr,int left,int right)
{
	if(left<right)
	{
		int i=left-1;
		int j=right+1;
		int mid=arr[(left+right)/2];
		while(true)
		{
			while(arr[++i]>mid);
			while(arr[--j]<mid);
			if(i>=j) break;
			swap(arr,i,j);
		}
		QuickSort(arr,left,i-1);
		QuickSort(arr,j+1,right);
	}
}
int main()
{
	int a;
	while(scanf("%d",&a)!=EOF)
	{
		int max=-2147483647;
		int arr[a];
		for(int i=0;i<a;i++)
		{
			scanf("%d",&arr[i]);
			if(arr[i]>max)
			{
				max=arr[i];
			}
		}
		int count=1;	
		int temp=0;
//		printf("%d\n",max);
		for(int i=0;i<a;i++)
		{
			if(arr[i]==max) temp++;
			else
			{
//				printf("%d",i);
				if(temp>count) count=temp;
				temp=0;
			}
			if(i==a-1)
			{
				if(temp>count) count=temp;
				temp=0;
			}
		}
		printf("%d\n",count);
	}
	return 0;
 }