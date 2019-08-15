#include <iostream>
using namespace std;


typedef struct arr{
	int clist[50];
	int cnum;
	int pidx;
} _arr;
_arr arr[50];
int leapcnt = 0;
void dfs(_arr arrF){
	if(arrF.cnum==0 || (arrF.cnum==1 && arrF.clist[0]==-2)){
		leapcnt++;
		return;
	}

	for(int i=0;i<arrF.cnum;i++){
		if(arrF.clist[i]==-2) continue;
		dfs(arr[arrF.clist[i]]);
	}
}
int main(){
	int N;
	int reidx;
	int rootidx;
	cin >> N;
	for(int i=0;i<N;i++){
		cin >> arr[i].pidx;
		if(arr[i].pidx!=-1){
			arr[arr[i].pidx].clist[arr[arr[i].pidx].cnum++] = i;
		} else {
			rootidx = i;
		}
	}
	cin >> reidx;
	if(reidx == rootidx){
		cout << "0";
		return 0;
	}

	for(int i=0;i<arr[arr[reidx].pidx].cnum;i++){
		if(arr[arr[reidx].pidx].clist[i]==reidx){
			arr[arr[reidx].pidx].clist[i] = -2;
			break;
		}
	}

	dfs(arr[rootidx]);
	cout << leapcnt;
	return 0; 
}