#include <bits/stdc++.h>
using namespace std;

mt19937 g = mt19937(0);

int main(int argc, char **args){
	int n = 3;
	if(argc > 1){
		n = atoi(args[1]);
		g = mt19937(n);
	}
	assert(n >= 3 and n <= 2048);
	
	vector<int> v(n);
	for(int i = 0; i < n; i++)
		v[i] = i+1;
	shuffle(v.begin(), v.end(), g);
	for(int i = 0; i < n-1; i++)
		printf("%d ", v[i]);
	printf("%d\n", v[n-1]);
}
