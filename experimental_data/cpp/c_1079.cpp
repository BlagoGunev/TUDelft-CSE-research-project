#include <bits/stdc++.h> 
using namespace std; 


int main() 
{ 
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int a[n], b[n];

    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    	b[i] = 0;
    }

    bool valid = true;

    if (n == 1) {
    	printf("1\n");
    	return 0;
    }

    if (a[0] > a[1]) b[0] = 5;
    else if (a[0] < a[1]) b[0] = 1;

    for (int i = 1; i < n; i++) {

    	if (a[i] > a[i-1] && b[i-1] == 5) { valid = false; break;}
    	if (a[i] < a[i-1] && b[i-1] == 1) { valid = false; break; }

    	if (a[i] > a[i-1] && b[i-1] == 4) { b[i] = 5; continue; }
    	if (a[i] < a[i-1] && b[i-1] == 2) { b[i] = 1; continue; }

    	if (i < n-1 && a[i] == a[i+1]) continue; 

    	int least_valid = 1, max_valid = 5;

    	if (a[i] > a[i-1]) {
    		least_valid = b[i-1] + 1;
    		max_valid = 5;
    	} else if (a[i] < a[i-1]) {
    		least_valid = 1;
    		max_valid = b[i-1] - 1;
    	} else {
    		if (b[i-1] == 1) least_valid = 2;
    		if (b[i-1] == 5) max_valid = 4;
    	}

    	if (i == n-1) b[i] = max_valid;

    	if (a[i] > a[i+1]) {
    		b[i] = max_valid;
    	} else {
    		b[i] = least_valid;
    	}
    }

    if (!valid) {
    	printf("-1\n");
    	return 0;
    }

    for (int i = n-2; i > 0; i--) {
    	if (b[i] != 0) continue;

	  	if(a[i] == a[i-1]) {
	  		if (b[i+1] == 2)
	  			b[i] = 3;
	  		else b[i] = 2;
	  	} else if (a[i] < a[i-1]) {
	  		if (b[i+1] == 1)
	  			b[i] = b[i-1] - 1;
	  		else b[i] = 1;
	  	}
	  	else if (a[i] > a[i-1]) {
	  		if (b[i+1] == 5)
	  			b[i] = b[i-1] + 1;
	  		else b[i] = 5;
	  	}

	  	if (b[i] < 1 || b[i] > 5) {
	  		valid = false;
	  		break;
	  	}

    }

    if (b[0] == 0) {
    	if (b[1] == 1)
    		b[0] = 2;
    	else b[0] = 1;
    }

    if (b[n-1] == 0) {
    	if (b[n-2]  == 1)
    		b[n-1] = 2;
    	else b[n-1] = 1;
    }

    if (!valid) {
    	printf("-1\n");
    	return 0;
    }

    for (int i = 0; i < n; i++)
    	printf("%d ", b[i]);
    printf("\n");


	return 0; 
}