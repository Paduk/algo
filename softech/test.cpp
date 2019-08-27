#include <iostream>
using namespace std;
#define MAX_M 5

struct Result {
   int y, x;
};

int MyM = 5;

int swap_[MAX_M][MAX_M];
void rotate(int stars[MAX_M][MAX_M]){
	int i,j;
	for(i=0;i<MyM;i++)
		for(j=0;j<MyM;j++)
			swap_[i][j] = stars[i][j];
	
	for(i=0;i<MyM;i++)
		for(j=0;j<MyM;j++)
			stars[i][j] = swap_[MyM-1-j][i];
}

void printtmp(int stars[MAX_M][MAX_M]){
	int i,j;
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			cout << stars[i][j] << " ";
		}
		cout << endl;
	}
}

int main(){
	int k;
	int star[5][5];
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			star[i][j] = (5*i) + (j+1);
		}
	}

	for(k=0;k<5;k++){
		printtmp(star);
		cout << endl;
		rotate(star);
   	}
	
   	return 0;
}