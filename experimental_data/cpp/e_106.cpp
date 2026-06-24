#include<bits/stdc++.h>



using namespace std;



struct point

{

	double x,y,z;

};



double dist(point a, point b)

{

	return sqrt(((a.x - b.x) * (a.x-b.x)) +((a.y - b.y) * (a.y-b.y))+ ((a.z - b.z) * (a.z-b.z)));

}



point pontos[1002];



int main()

{

	int n;

	scanf("%d",&n);



	for(int i = 0 ; i < n ; i++)

	{

		

		scanf("%lf%lf%lf",&pontos[i].x,&pontos[i].y, &pontos[i].z);

	}



	double taxa = 1.;



	point resp = pontos[0];



	for(int i = 0 ; i < 100000; i++)

	{

		point far;

		double maior = -1.0;

		for(int j = 0 ; j < n ; j++)

		{

			double t = dist(resp, pontos[j]);



			if(t > maior)

			{

				far = pontos[j];

				maior = t;

			}

		}

		

		resp.x += taxa*(far.x - resp.x);

		resp.y += taxa*(far.y - resp.y);

		resp.z += taxa*(far.z - resp.z);

		//printf("%.3lf %.3lf %.3lf\n",resp.x, resp.y, resp.z);

		taxa*=0.999;

	}



	printf("%.15lf %.15lf %.15lf\n",resp.x, resp.y, resp.z);

}