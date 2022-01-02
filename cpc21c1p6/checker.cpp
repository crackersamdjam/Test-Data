#include <bits/stdc++.h>

using namespace std;

namespace CheckerCodes{
	int AC = 0;
	int WA = 1;
	int PE = 2;
	int IE = 7;
}

constexpr int MM = 5e5+5;

int n, a[MM], b[MM], c[MM];

int main(int argc, char** argv){
	if(argc != 4){
		return CheckerCodes::IE;
	}
	try{
		ifstream input(argv[1]), output(argv[2]), answer(argv[3]);
		input.exceptions(ifstream::failbit | ifstream::badbit);
		output.exceptions(ifstream::failbit | ifstream::badbit);
		answer.exceptions(ifstream::failbit | ifstream::badbit);
		
		input>>n;
		for(int i = 0; i < n; i++){
			input>>a[i]>>b[i]>>c[i];
		}
		
		int ra, rb, rc;
		output>>ra>>rb>>rc;

		int aa, ab, ac;
		answer>>aa>>ab>>ac;
		
		//cout<<"user: "<<ra<<' '<<rb<<' '<<rc<<endl;
		//cout<<"answer: "<<aa<<' '<<ab<<' '<<ac<<endl;

		for(int i = 0; i < n; i++){
			if(ra < a[i] and rb < b[i] and rc < c[i]){
				cout<<"Invalid answer"<<endl;
				return CheckerCodes::WA;
			}
		}

		if(ra+rb+rc != aa+ab+ac){
			cout<<"A better answer exists"<<endl;
			return CheckerCodes::WA;
		}
	}
	catch(...){
		return CheckerCodes::PE;
	}
	return CheckerCodes::AC;
}
