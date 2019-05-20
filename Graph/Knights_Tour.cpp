// KNIGHTS TOUR

#include<iostream>
using namespace std;

struct Queue{
	int data[50];
	int f, r, size;
};

const int n=12;

void insert(int G[n][n], int x, int y){
	G[x][y]=1;
	G[y][x]=1;
}

void enq(Queue &A, int x){
	if(A.f == (A.r+1)%A.size) cout<<"Full";
	else if(A.f == -1) A.f=0;
	A.r=(A.r+1)%A.size;
	A.data[A.r]=x;
}

int deq(Queue &A){
	if(A.f == -1) cout<<"Empty";
	else{
		int t=A.data[A.f];
		if(A.f == A.r) A.f=A.r=-1;
		else A.f=(A.f+1)%A.size;
		return t;
	}
}

int isVisited(int a[]){
	for(int i=0; i<n; i++){
		if(!a[i]) return 0;
	}
	return 1;
}

void TourdeKnight(int G[n][n], int visited[], int start, Queue A){
	visited[start]=1;
	enq(A,start);
	if(isVisited(visited)){
		while(A.f!=-1) cout<<deq(A)<<" ";
		cout<<"\n";
		return ;
	}
	for(int i=0; i<n; i++){
		if(G[start][i] && !visited[i]){
			TourdeKnight(G,visited,i,A);
			visited[i]=0;
		}
	}
}

int main()
{
	int G[n][n]={{0,0}};
	int x=0, y=0, visited[n]={0}, start=0;
	Queue A; A.f=A.r=-1; A.size=50;
	insert(G,0,5);
	insert(G,0,7);
	insert(G,5,10);
	insert(G,5,6);
	insert(G,10,3);
	insert(G,3,8);
	insert(G,6,1);
	insert(G,1,8);
	insert(G,8,9);
	insert(G,6,11);
	insert(G,11,4);
	insert(G,4,9);
	insert(G,7,2);
	insert(G,2,3);
	cout<<"Adjacency matrix is : \n";
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout<<G[i][j]<<" ";
		}
		cout<<"\n";
	}
	cout<<"\nAll Knight's tours : \n";
	for(int i=0; i<n; i++){
		TourdeKnight(G,visited,i,A);
		for(int j=0; j<n; j++) visited[j]=0;
	}
	return 0;
}
