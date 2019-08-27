#include <iostream>
using namespace std;

int main(){
	int N;
	int chk = 1;
	int a,b,c,d,e,f,g,i;
	cin >> N;
	for(i=1000;chk!=N;i++){
		a= i%10;
		b= i/10%10;
		c= i/100%10;
		d= i/1000%10;
		e= i/10000%10;
		f= i/100000%10;
		g= i/1000000%10;

		if(a== 6 && b== 6 && c== 6) chk++;
		else if(b== 6 && c== 6 && d== 6) chk++;
		else if(c== 6 && d== 6 && e== 6) chk++;
		else if(d== 6 && e== 6 && f== 6) chk++;
		else if(e== 6 && f== 6 && g== 6) chk++;
	}
	if(chk==1) i = 667;
	cout << i-1;
	return 0;
}