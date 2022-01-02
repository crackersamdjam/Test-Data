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
	assert(a and a != b);
	
#ifdef DEBUG
	return lim ? (ans[a]&ans[b]&k) : (ans[a]&ans[b]);
#endif
	
	cout<<"? "<<a<<' '<<b<<endl;
	int x;
	cin>>x;
	assert(~x);
	return lim ? (x&k) : x;
}

/*
 * now I need to make this work for n != 2^k-1
 */

int main(){
#ifdef DEBUG
	n = ans.size()-1;
#else
	cin>>n;
#endif
	
	int l = __lg(n+1);
	k = (1<<l)-1;
	print(n, l, k);
	
	for(int i = 1; i <= n; i++)
		v[i] = i;
//	shuffle(v+1, v+1+n, g);

//    for(int i = 1; i <= n; i++)
//    	printr(v[i]);
	for(int i = 1; i <= n; i++)
		printr(ans[i]);
	print("");
	
	int a = v[1], b = v[2], ab = ask(a, b, 1);
	print("st", a, b, ab);
	
	for(int i = 3; i <= n; i++){
		int c = v[i];
		int bc = ask(b, c, 1);
		
		print("i", a, b, c, "(", ans[a], ans[b], ans[c], ")");
		print("cmp", ab, bc);
		
		if(bc < ab){
			continue;
		}
		else if(bc > ab){
			a = c;
			ab = bc;
		}
		else{
			//a&b == b&c
			int ac = ask(a, c, 1);
			print("cmp", ab, bc, ac);
			if(ac > ab){
				b = c;
				ab = ac;
			}
			else{
				assert(ac == ab);
				//doesn't matter which gets thrown out, because none are k
			}
		}
	}
	print("ab", a, b, "(", ans[a], ans[b], ")");
	//either a or b is full
	int id = 0;
	while(1){
		int c = v[randint(1, n)];
		if(c == a or c == b)
			continue;
		
		int va = ask(a, c, 1), vb = ask(b, c, 1);
		print("try", c, "(", ans[c], ")", va, vb);
		if(va == vb)
			continue;
		id = va > vb ? a : b;
		break;
	}
	print("id", id, "(", ans[id], ")");
	
	// now lim is not on, find k+1...
	
	int kk = 0;
	
	for(int i = 1; i <= n; i++){
		int c = v[i];
		if(c == id)
			out[c] = k;
		else
			out[c] = ask(c, id, 0);
		
		if(!out[c]){
			out[c] = k+1;
			kk = c;
		}
	}
	
	if(kk){
		//
	}
	
	cout<<"!";
	for(int i = 1; i <= n; i++)
		cout<<' '<<out[i];
	cout<<endl;
	
	for(int i = 1; i <= n; i++)
		printr(ans[i]);
}
/*
3
0
2
1
0
1
2
 */