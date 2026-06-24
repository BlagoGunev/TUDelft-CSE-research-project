#include <stdio.h>
#include <stdlib.h>
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
int arr[200005];
int gap[200005];
int main(){
	int t; scanf("%d",&t);
	for(int tt=0; tt<t; tt++){
		getchar();
		int n, d; scanf("%d %d",&n,&d);
		for(int i=0; i<n; i++){
			scanf("%d",&arr[i]);
		}
		int m1, m2;
		gap[0] = arr[0];
		for(int i=1; i<n; i++){
			gap[i] = arr[i] - arr[i-1];
		}
		gap[n] = d - arr[n-1];
		int min = gap[0];
		int max = gap[0];
		int index = 0;
		for(int i=0; i<n; i++){
			if(min>gap[i]){
				min = gap[i];
				index = i;
			}
			if(max<gap[i]) max = gap[i];
		}
		gap[index+1] += gap[index];
		gap[index] = gap[index+1];
		if(index==n-1){
			gap[index] *= 2;
		}
		gap[n] *= 2;
		int new_min = gap[0];
		int new_max = gap[0];
		for(int i=0; i<n; i++){
			if(new_min>gap[i]){
				new_min = gap[i];
			}
			if(new_max<gap[i]) new_max = gap[i];
		}
		if(new_max<gap[n]) new_max = gap[n];
		if(new_min <= new_max/2) m1 = new_min-1;
		else m1 = new_max/2 -1;
		
		
		gap[0] = arr[0];
		for(int i=1; i<n; i++){
			gap[i] = arr[i] - arr[i-1];
		}
		gap[n] = d - arr[n-1];
		min = gap[0];
		max = gap[0];
		index = 0;
		for(int i=0; i<n; i++){
			if(min>gap[i]){
				min = gap[i];
				index = i;
			}
			if(max<gap[i]) max = gap[i];
		}
		if(index==0){
			printf("%d\n",m1); continue;
		}
		gap[index-1] += gap[index];
		gap[index] = gap[index-1];
		gap[n] *= 2;
		new_min = gap[0];
		new_max = gap[0];
		for(int i=0; i<n; i++){
			if(new_min>gap[i]){
				new_min = gap[i];
			}
			if(new_max<gap[i]) new_max = gap[i];
		}
		if(new_max<gap[n]) new_max = gap[n];
		if(new_min <= new_max/2) m2 = new_min-1;
		else m2 = new_max/2 -1;
		
		printf("%d\n",MAX(m1,m2));
	}
}