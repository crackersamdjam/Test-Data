#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=char(n%10+48);n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

#define f first
#define s second

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

mt19937_64 g;

ll randint(ll a, ll b){return uniform_int_distribution<ll>(a, b)(g);}

int main(int argc, char *args[]){
	int seed = argc > 1 ? atoi(args[1]) : 0;
	int k = argc > 2 ? atoi(args[2]) : 0;
	g = mt19937_64(seed);
	
//	int n = randint(1, 2e5);
//	int n = randint(1, 1000);
	int n = seed;
	cout<<k<<' '<<n<<'\n';
	for(int i = 0; i < n; i++)
		cout<<randint(0, 1e9)<<' ';
	cout<<endl;
	for(int i = 0; i < n; i++)
		cout<<randint(0, 1e9)<<' ';
	cout<<'\n';
}