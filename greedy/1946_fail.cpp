#include <iostream>
using namespace std;
int check(int N){
	if(N>0) return (N+2)/3;
	else return 0;
}
int main(){
	int N,M,K;
	int teamcnt = 0;
	cin >> N >> M >> K;

	if(N/2*M == 1){
		teamcnt = M - (check(K);)
	} else if(N/2*M > 1) {
		K -= (N-2*M);
		teamcnt = M - check(K);
	} else {
		K -= (M-0.5*N);
		teamcnt = N/2 - check(K);
	}

	if(teamcnt < 0) teamcnt = 0;
	if(N == 0 || M == 0) teamcnt = 0;

	cout << teamcnt;
	return 0;
}