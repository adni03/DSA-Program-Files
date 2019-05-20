// SNAKES AND LADDERS

#include<iostream>
using namespace std;

int find(int D[], int key){
	return D[key];
}

void Union(int D[], int key, int root){
	D[key]=D[root];
}

void reset(int a[], int n){
	for(int i=0; i<n; i++){
		a[i]=i;
	}
}

int Find_Min_Throws(int D[], int n, int pos=0, int cnt=0){
	if(D[pos]==n-1) return cnt;
	int max=-1;
	for(int j=pos; j<6+pos; j++){
		if(max < find(D,D[j])){
			max=find(D,D[j]);
		}
	}
	return Find_Min_Throws(D,n,max,cnt+1);
}

int main()
{
	int D[30];
	int info[8][2]={{26,0},{2,21},{16,3},{4,7},{18,6},{10,25},{20,8},{19,28}};
	reset(D,30);
	for(int i=0; i<8; i++){
		Union(D,info[i][0],info[i][1]);
	}
	cout<<"With given configuration, minimum moves : "<<Find_Min_Throws(D,30);
	return 0;
}
