// HAMILTONIAN CYCLE

#include<iostream>
using namespace std;

struct Queue{
	char data[50];
	int f, r, size;
};

const int n=5;
//const int n=4;

void enq(Queue &A, char x){
	if(A.f == (A.r+1)%A.size) cout<<"Full";
	else if(A.f == -1) A.f=0;
	A.r=(A.r+1)%A.size;
	A.data[A.r]=x;
}

char deq(Queue &A){
	char t;
	if(A.f == -1) cout<<"Empty";
	else{
		t=A.data[A.f];
		if( A.f == A.r) A.f=A.r=-1;
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

void Hamiltonian_Cycle(int G[n][n], int visited[], int start, Queue A, int vtx){
	visited[start]=1;
	enq(A,char(65+start));
	if(isVisited(visited)){
		while(A.f!=-1) cout<<deq(A)<<" ";
		cout<<"\n";
		return ;	
	}
	for(int i=0; i<n; i++){
		if(G[start][i] && !visited[i]){
			Hamiltonian_Cycle(G,visited,i,A,vtx);
			visited[i]=0;
		}
	}
}

int main()
{
	int G[n][n]={{0,1,1,1,0},{1,0,1,0,1},{1,1,0,1,1},{1,0,1,0,1},{0,1,1,1,0}};
	//int G[n][n]={{0,1,1,0},{0,0,1,0},{0,0,0,1},{1,0,0,0}};
	int visited[n]={0}, start=0;
	Queue A; A.f=A.r=-1; A.size=50;
	cout<<"Hamiltonian cycle is : \n";
	Hamiltonian_Cycle(G,visited,start,A,start);
	return 0;
}
