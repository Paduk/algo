#include <iostream>
using namespace std;

int main(){
	int N;
	int opt;
	cin >> N;

	int n1,n2,n3;
	if(N < 100) cout << N ;
	else {
		if(N==1000) N=999;
		opt = 99;		

		for(int i=100;i<=N;i++){
			n1 = i/100;
			n2 = (i%100)/10;
			n3 = i%10;
			if(n3-n2 == n2-n1) opt++;
		}	
		cout << opt;
	}

	return 0;
}