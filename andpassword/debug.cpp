#ifndef ONLINE_JUDGE
#define DEBUG
#endif

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
vector<int> val[MM];
//vector<int> ans = {0, 11, 4, 9, 10, 6, 3, 7, 2, 1, 5, 8, 12};
//vector<int> ans = {0, 4, 1, 2, 3, 7, 5, 6};
//vector<int> ans = {0, 4, 5, 1, 2, 3};
vector<int> ans = {0, 6, 2, 1, 8, 3, 9, 4, 10, 5, 7};
// 6 2 1 8 3 9 4 10 5 7

int rem = 9999;
int cache[MM][MM];

int ask(int a, int b, bool lim){
	rem--;
	assert(rem >= 0);
	assert(a and a != b);
	
	if(a > b)
		swap(a, b);
	if(cache[a][b])
		return cache[a][b];

#ifdef DEBUG
	return cache[a][b] = (lim ? (ans[a]&ans[b]&k) : (ans[a]&ans[b]));
#endif
	
	cout<<"? "<<a<<' '<<b<<endl;
	int x;
	cin>>x;
	assert(~x);
	return cache[a][b] = (lim ? (x&k) : x);
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
	
	//z is for overlap help
	int a = v[1], b = v[2], z = 0, ab = ask(a, b, 1);
	print("st", a, b, ab);
	
	for(int i = 3; i <= n; i++){
		int c = v[i];
		int bc = ask(b, c, 1);
		
		print("i", "[", z, "]", a, b, c, "(", "[", ans[z], "]", ans[a], ans[b], ans[c], ")");
		print("cmp", ab, bc);
		
		if(bc < ab){
			//does not have same bits
			continue;
		}
		else if(bc > ab){
			a = c;
			ab = bc;
			
			//now it is (z, c, b)
			//if z, check if keep or go
			if(z){
				int za = ask(z, a, 1);
				if(za > ab){
					ab = za;
					b = z;
					z = 0;
				}
				else
					z = 0;
			}
		}
		else{
			//has same bits
			int ac = ask(a, c, 1);
			print("cmp", ab, bc, ac);
			if(ac > ab){
				b = c;
				ab = ac;
				//now it is (z, a, c)
				if(z){
					int zb = ask(z, b, 1);
					if(zb > ab){
						ab = zb;
						a = z;
						z = 0;
					}
					else
						z = 0;
				}
			}
			else{
				assert(ac == ab);
				//doesn't matter which gets thrown out, because none are k
				//^comment above no longer applies when n != 2^m-1
				
				//now it is (z, a, b)
				//ac and bc same
				if(z){
					int zc = ask(z, c, 1);
					print("cmp", ab, bc, ac, zc);
					if(zc > ac){
						ab = zc;
						a = z;
						b = c;
						z = 0;
						assert(ask(a, b, 1) == ab);
					}
					else{
						z = 0;
//						cout<<"wtf"<<endl;
//						abort();
					}
				}
				else{
					z = c;
				}
			}
		}
	}
	
	int id = 0, kk = 0; // id is k (2^m-1), kk is k+1 (if exists)
//	int lim = 1e9;
	
	while(1){
//		if(!--lim){
//			cout<<flush;
//			abort();
//		}
		
		int c = v[randint(1, n)];
		if(c == z or c == a or c == b){
			continue;
		}
		
		print("zab", z, a, b, "(", "[", ans[z], "]", ans[a], ans[b], ")");
		
		int ac = ask(a, c, 1), bc = ask(b, c, 1), zc = 0;
		if(z){
			zc = ask(z, c, 1);
			if(zc > ac){
				ac = zc;
				a = z;
			}
			else if(zc > bc){
				bc = zc;
				b = z;
			}
		}
		
		print("try", c, "(", ans[c], ")", ac, bc);
		if(ac == bc)
			continue;
		id = ac > bc ? a : b;
		break;
	}
	
	print("id", id, "(", ans[id], ")");
	
	for(int i = 1; i <= n; i++){
		int c = v[i];
		if(c == id)
			out[c] = k;
		else
			out[c] = ask(c, id, 1);
		
		if(!out[c]){
			out[c] = k+1;
			kk = c;
		}
		
		val[out[c]].emplace_back(c);
	}
	
	if(kk){
		//
		for(int i = 1; i <= k; i++){
			if(val[i].size() < 2)
				break;
			assert(val[i].size() == 2);
			int c = val[i][0], cc = val[i][1];
			assert(c != kk);
			if(ask(kk, c, 0) > k)
				out[c] |= (k+1);
			else
				out[cc] |= (k+1);
		}
	}
	
	cout<<"!";
	for(int i = 1; i <= n; i++)
		cout<<' '<<out[i];
	cout<<endl;
	
	for(int i = 1; i <= n; i++)
		printr(ans[i]);
	
	print("\n", 9999-rem);
}