#include <iostream>
#include <cstdio>
#include <time.h>
using namespace std;

int main(){
	clock_t start, end;
	float res;

	FILE * fp;
    fp = fopen("input.txt","r");
	start = clock();

	end = clock();
	res = (float)(end - start)/CLOCKS_PER_SEC;
	printf(" line함수 소요된 시간 : %.3f \n", res);

	fclose(fp);
	return 0;
}