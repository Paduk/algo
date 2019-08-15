#include <iostream>
#include <algorithm>
using namespace std;

int arr1[51], arr2[50];
bool cmp(int a,int b){
	if(a > b) return true;
	else return false;
}
bool _cmp(int a,int b){
	if(a < b) return true;
	else return false;
}
int main(){
	int i;
	int N;
	int opt = 0;
	cin >> N;

	for(int i=0;i<N;i++){
		cin >> arr1[i];
	}
	for(int i=0;i<N;i++){
		cin >> arr2[i];
	}
	sort(arr1,arr1+N,cmp);
	sort(arr2,arr2+N,_cmp);

	for(i=0;i<N;i++){
		opt += arr1[i] * arr2[i];
	}
	cout << opt;
	return 0;
}