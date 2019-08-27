/* 
#include <iostream>
using namespace std;
*/

#define MAXR		99
#define MAXC		26

int realTable[MAXR][MAXC][2];
typedef struct fakeTable{
	int op;
	int fc;
	int fr;
	int rc;
	int rr;	
} _fakeTable;
_fakeTable charfakeTable[MAXR][MAXC];

int len;
int iC,iR;
void init(int C, int R) {
	int i,j;
	iC = C; iR = R;
	len = 0;
	for(i=0;i<MAXR;i++){
		for(j=0;j<MAXC;j++){
			realTable[i][j][0] = realTable[i][j][1] = 0;
			charfakeTable[i][j].op = charfakeTable[i][j].fc = charfakeTable[i][j].fr = charfakeTable[i][j].rc = charfakeTable[i][j].rr = 0; // No meanning, Should i do ?
		}
	}
}

void set(int col, int row, char input[]) {
	int i,j, val =0;
	if((int)input[0] <= 58){ // Num, SQA Required
		if((int)input[0] == 45) {
			for(len=1;input[len]!='\0';len++);
			for(i=len-1, j=1;i>=1;i--,j=j*10){
				val += (input[i]-48) * j; // 57 TBC
			}
			val *= -1;
		} else {
			for(len=0;input[len]!='\0';len++);
			for(i=len-1, j=1;i>=0;i--,j=j*10){
				val += (input[i]-48) * j; // 57 TBC
			}
		}
		realTable[row-1][col-1][0] = val;
		realTable[row-1][col-1][1] = 0;
	} else {
		// ADD 1, SUB 2, MUL 3, DIV 4, MAX 5, MIN 6, SUM 7
		realTable[row-1][col-1][1] = -1; // still ramaining in Func
		if(input[0]=='A') charfakeTable[row-1][col-1].op=1;
		else if(input[0]=='S' && input[2]=='B') charfakeTable[row-1][col-1].op=2;
		else if(input[0]=='M' && input[2]=='L') charfakeTable[row-1][col-1].op=3;
		else if(input[0]=='D') charfakeTable[row-1][col-1].op=4;
		else if(input[0]=='M' && input[2]=='X') charfakeTable[row-1][col-1].op=5;
		else if(input[0]=='M' && input[2]=='N') charfakeTable[row-1][col-1].op=6;
		else if(input[0]=='S' && input[2]=='M') charfakeTable[row-1][col-1].op=7;
		else ;
		
		if(input[6]==','){
			charfakeTable[row-1][col-1].fc = input[4]-65; 
			charfakeTable[row-1][col-1].fr = input[5]-49; 
			if(input[9]==')'){
				charfakeTable[row-1][col-1].rc = input[7]-65; 
				charfakeTable[row-1][col-1].rr = input[8]-49; 
			} else if(input[10]==')'){
				charfakeTable[row-1][col-1].rc = input[7]-65; 
				charfakeTable[row-1][col-1].rr = (input[8]-48)*10 + (input[9]-49); 
			} else ;
		} else if(input[7]==','){
			charfakeTable[row-1][col-1].fc = input[4]-65; 
			charfakeTable[row-1][col-1].fr = (input[5]-48)*10 + (input[6]-49); 

			if(input[10]==')'){
				charfakeTable[row-1][col-1].rc = input[8]-65; 
				charfakeTable[row-1][col-1].rr = input[9]-49; 
			} else if(input[11]==')'){
				charfakeTable[row-1][col-1].rc = input[8]-65; 
				charfakeTable[row-1][col-1].rr = (input[9]-48)*10 + (input[10]-49); 
			} else ;
		} else ;
	}
}
int makeit(int a, int b){
	// ADD 1, SUB 2, MUL 3, DIV 4, MAX 5, MIN 6, SUM 7
	int op = charfakeTable[a][b].op;
	int fc = charfakeTable[a][b].fc;
	int fr = charfakeTable[a][b].fr;
	int rc = charfakeTable[a][b].rc;
	int rr = charfakeTable[a][b].rr;
	
	if(op<=4){
		if(realTable[fr][fc][1]==-1)
			realTable[fr][fc][0] = makeit(fr,fc);
		if(realTable[rr][rc][1]==-1)
			realTable[rr][rc][0] = makeit(rr,rc);
				
		     if(op==1) return realTable[fr][fc][0]+realTable[rr][rc][0];
		else if(op==2) return realTable[fr][fc][0]-realTable[rr][rc][0];
		else if(op==3) return realTable[fr][fc][0]*realTable[rr][rc][0];
		else if(op==4) {
			if(realTable[fr][fc][0] == 0) return 0;
			else return realTable[fr][fc][0]/realTable[rr][rc][0];
		}
	} else if(op==5){
		int i,res = -10001;
		if(fc == rc) // sero
		{
			for(i=fr;i<=rr;i++){
				if(realTable[i][fc][1] == -1) realTable[i][fc][0] = makeit(i,fc);
				if(realTable[i][fc][0] > res) res = realTable[i][fc][0]; 
			}
			return res;
		}
		else if(fr == rr) // garo
		{
			for(i=fc;i<=rc;i++){
				if(realTable[fr][i][1] == -1) realTable[fr][i][0] = makeit(fr,i);
				if(realTable[fr][i][0] > res) res = realTable[fr][i][0]; 
			}
			return res;
		}
		else ;// rr
	} else if(op==6){
		int i,res = 10001;
		if(fc == rc) // sero
		{
			for(i=fr;i<=rr;i++){
				if(realTable[i][fc][1] == -1) realTable[i][fc][0] = makeit(i,fc);
				if(realTable[i][fc][0] < res) res = realTable[i][fc][0]; 
			}
			return res;
		}
		else if(fr == rr) // garo
		{
			for(i=fc;i<=rc;i++){
				if(realTable[fr][i][1] == -1) realTable[fr][i][0] = makeit(fr,i);
				if(realTable[fr][i][0] < res) res = realTable[fr][i][0]; 
			}
			return res;
		}
		else ;// rr
	} else if(op==7){
		int i,res = 0;
		if(fc == rc) // sero
		{
			for(i=fr;i<=rr;i++){
				if(realTable[i][fc][1] == -1) realTable[i][fc][0] = makeit(i,fc);				
				res += realTable[i][fc][0];
			}
			return res;
		}
		else if(fr == rr) // garo
		{
			for(i=fc;i<=rc;i++){
				if(realTable[fr][i][1] == -1) realTable[fr][i][0] = makeit(fr,i);
				res += realTable[fr][i][0];
			}
			return res;
		}
		else ;// rr
	} else ; //err
}
void update(int value[MAXR][MAXC]) {
	// No value -> init 0
	// Func -> do it
	// If func is exist in range, then push into arr and do it next
	int i, j;
	//debug();
	for(i=0;i<iR;i++){
		for(j=0;j<iC;j++){
			if(realTable[i][j][1]==-1){
				realTable[i][j][0] = makeit(i,j);
			}
		}
	}
	
	for(i=0;i<iR;i++){
		for(j=0;j<iC;j++){
			value[i][j] = realTable[i][j][0];
		}
	}

	//debug();
} 	
