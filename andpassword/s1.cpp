//#define DEBUG

#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
#ifdef DEBUG
template<typename T>
void printr(T a){std::cout<<a<<' ';}
template<typename T>
void print(T a){std::cout<<a<<std::endl;}
template<typename T,typename... Args>
void print(T a, Args... args) {std::cout<<a<<' ',print(args...);}
#else
template<typename... Args>
void print(Args... args){}
template<typename... Args>
void printr(Args... args){}
#endif

using namespace std;
const int MM = 2100;

mt19937 g(0);
int randint(int a, int b){return uniform_int_distribution<int>(a, b)(g);}

int n, k, v[MM], out[MM];
//vector<int> ans = {0, 3, 2, 1};
vector<int> ans = {0, 4, 1, 2, 3, 7, 5, 6};

int ask(int a, int b, bool lim){

#ifdef DEBUG
	return lim ? (ans[a]&ans[b]&k) : (ans[a]&ans[b]);
#endif
	
	cout<<"? "<<a<<' '<<b<<endl;
	int x;
	cin>>x;
	assert(~x);
	return lim ? (x&k) : x;
}

int main(){
#ifdef DEBUG
	n = ans.size()-1;
#else
	cin>>n;
#endif
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(i == j) continue;
			out[i] |= ask(i, j, 0);
		}
		if(!out[i])
			out[i] = n;
	}
	cout<<"!";
	for(int i = 1; i <= n; i++)
		cout<<' '<<out[i];
	cout<<endl;
}