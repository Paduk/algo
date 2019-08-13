#include <iostream>
using namespace std;

char str[51];
int presentVal;
int firstminus = 0;
int gap = 0;
int getvalue(int stidx, int gap){
	int val = 0;
	if(gap == 1) val = str[stidx]-'0';
	else if(gap == 2) val = (str[stidx]-'0') * 10 + (str[stidx+1]-'0');
	else if(gap == 3) val = (str[stidx]-'0') * 100 + (str[stidx+1]-'0') * 10 + str[stidx+2]-'0';
	else if(gap == 4) val = (str[stidx]-'0') * 1000 + (str[stidx+1]-'0') * 100 + (str[stidx+2]-'0')*10 + str[stidx+3]-'0';
	else val = (str[stidx]-'0') * 10000 + (str[stidx+1]-'0') * 1000 + (str[stidx+2]-'0')*100 + (str[stidx+3]-'0') *10 + str[stidx+4] - '0';

	return val;
}

int checknextoper(int i){
	int chk = -1;
	int j;
	for(j=i;j<i+6;j++){
		if(str[j]=='\0') {
			gap = j-i;
			return -1;
		}		
		if(str[j] == '+' || str[j] == '-') break;
	}

	if(str[j]=='+') chk = 1;
	else if(str[j]=='-') chk = 0;

	gap = j-i;

	return chk;
}

int main(){
	cin >> str;

	int num;
	int j;
	int isplus;
	for(j=1;j<6;j++){
		if(str[j]=='\0') { break; }

		if(str[j] == '+' || str[j] == '-') break;
	}

	if(str[j] == '-') firstminus = 1;
	presentVal = getvalue(0,j-0);

	isplus = firstminus? 0 : 1;
	int i = j;
	while(str[i]!='\0'){
		i++;

		if(isplus){
			isplus = checknextoper(i);
			if(!firstminus){
				presentVal += getvalue(i,gap);
			} else {
				presentVal -= getvalue(i,gap);
			}
		} else {
			isplus = checknextoper(i);
			firstminus = 1;
			presentVal -= getvalue(i,gap);
		}
		i += gap;
	}

	cout << presentVal;
	return 0;
}