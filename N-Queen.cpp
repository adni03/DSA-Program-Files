#include<iostream>
using namespace std;

const int n=8;

int isAvailable(int V[n][n], int x, int y){
	for(int i=0; i<n; i++){ //horizontal and vertical
		if(V[x][i] || V[i][y]) return 0;
	}
	if(x < y){
		for(int i=0, j=y-x; i<n && j<n; i++, j++){
			if(V[i][j]) return 0;
		}
	}
	else{
		for(int i=x-y, j=0; i<n && j<n; i++, j++){
			if(V[i][j]) return 0;
		}
	}
	if(x+y<=n-1){
		for(int i=x+y, j=0; i>=0 && j<n; --i, j++){//minor diagonal
			if(V[i][j]) return 0;
		}
	}
	else{
		for(int i=n-1, j=x+y-n+1; j<n; --i, j++){
			if(V[i][j]) return 0;
		}
	}
	return 1;
}

void clear(int B[n][n]){
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			B[i][j]=0;
		}
	}
}

void print(int B[n][n]){
	for(int k=0; k<n; k++){
		for(int l=0; l<n; l++){
			cout<<B[k][l]<<" ";
		}
		cout<<"\n";
	}
	cout<<"\n";
}

void solveNQueen(int B[n][n], int cnt, int x, int y, int &c){
	B[x][y]=1;
	cnt--;
	if(cnt == 0){
		print(B);
		c++;
		return ;
	}
	for(int j=y+1; j<n; j++){
		for(int i=0; i<n; i++){
			if(isAvailable(B,i,j)){	
				solveNQueen(B,cnt,i,j,c);
				B[i][j]=0;
			}
		}
		return ;
	}
}

void solveNQueen_Aux(int B[n][n], int &c){
	for(int i=0; i<n; i++){
		clear(B);
		solveNQueen(B,n,i,0,c);
	}
}

int main()
{
	int B[n][n] = {{0},{0}};
	int cnt=0;
	cout<<"Solutions for 4-Queen problem are : \n";
	solveNQueen_Aux(B,cnt);
	cout<<"Total possible solutions : "<<cnt;
	return 0;
}
