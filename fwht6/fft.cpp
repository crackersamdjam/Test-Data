#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using cd = complex<double>;
const double pi = acos(-1);
const double ang = pi*2/3;
const cd r(cos(ang), sin(ang));
const double ang2 = pi*4/3;
const cd r2(cos(ang2), sin(ang2));

using T = cd;
using matrix = vector<vector<cd>>;

const vector<vector<cd>> tmp = {{1, 1, 1}, {1, r, r2}, {1, r2, r}};
const vector<vector<cd>> tmpinv = {{r2+r, -1, -1}, {-1, cd(-1)/r, (r+cd(1))/r}, {-1, (r+cd(1))/r, cd(-1)/r}};
const cd det = r2+r-cd(2);

void go(vector<T> &v){
	int n = size(v);
	for(int len = 1; len < n; len *= 3){
		for(int pos = 0; pos < n; pos += len*3){
			for(int i = 0; i < len; i++){
				// replace values v[pos+i] v[pos+i+len] with their product with T_2
				T a = v[pos+i];
				T b = v[pos+i+len];
				T c = v[pos+i+len+len];
				v[pos+i] = a+b+c;
				v[pos+i+len] = a + r*b + r2*c;
				v[pos+i+len+len] = a + r2*b + r*c;
			}
		}
	}
}
void invgo(vector<T> &v){
	int n = size(v);
	for(int len = 1; len < n; len *= 3){
		for(int pos = 0; pos < n; pos += len*3){
			for(int i = 0; i < len; i++){
				T a = v[pos+i];
				T b = v[pos+i+len];
				T c = v[pos+i+len+len];
				v[pos+i] = ((r2+r)*a - b - c)/det;
				v[pos+i+len] = (-a - (cd(1)/r)*b + (r+cd(1))/r*c)/det;
				v[pos+i+len+len] = (-a + (r+cd(1))/r*b - (cd(1)/r)*c)/det;
			}
		}
	}
}

void mul(vector<T> &va, vector<T> &vb){
	int n = 1;
	while(n < size(va))
		n *= 3;
	va.resize(n), vb.resize(n);
	go(va); go(vb);
	for(int i = 0; i < n; i++)
		va[i] *= vb[i];
	invgo(va);
}

// matrix matmul(matrix ma, matrix mb){
// 	matrix c(3);
// 	for(int i = 0; i < 3; i++){
// 		c[i].resize(3);
// 		for(int j = 0; j < 3; j++){
// 			T t = 0;
// 			for(int k = 0; k < 3; k++)
// 				t = (t + ma[i][k] * mb[k][j]);
// 			c[i][j] = t/det;
// 		}
// 	}
// 	return c;
// }

int main(){
	// cout<<pi<<endl;
	// cout<<r<<' '<<r*r<<' '<<r*r*r<<endl;
	// cout<<r<<' '<<r2<<endl;
	// cout<<"det "<<det<<endl;
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin>>k>>n;
	vector<cd> a(n), b(n);
	for(int i = 0; i < n; i++){
		cin>>a[i];
		// cout<<a[i]<<' ';
	}
	// cout<<endl;
	for(int i = 0; i < n; i++){
		cin>>b[i];
		// cout<<b[i]<<' ';
	}
	// cout<<endl;
	
	mul(a, b);
	a.resize(3*n);
	for(int i = 0; i < 3*n; i++){
		cout<<round(a[i].real())<<' ';
	}
	cout<<endl;
	
	// cout<<"\nres\n";
	// matrix res = matmul(tmp, tmpinv);
	// for(auto i: res){
	// 	for(auto j: i)
	// 		cout<<j<<' ';
	// 	cout<<endl;
	// }
}