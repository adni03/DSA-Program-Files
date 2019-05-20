//STRONGLY CONNECTED COMPONENT IN A GRAPH

#include<iostream>
using namespace std;

void number_it(int G[][10], int n, int start, int posty[], int &cnt, int end){
	static int visited[10]={0};
	visited[start]=1;
	for(int i=0; i<n; i++){
		if(G[start][i] && !visited[i]){
			number_it(G,n,i,posty,cnt,end);
		}
	}
	posty[start]=cnt++;
	if(start==end){
		int j=0;
		for(j=0; j<10; j++){
			if(!visited[j]) break;
		}
		number_it(G,n,j,posty,cnt,end);
	}
}

int largest(int a[], int n){
	int max=a[0], pos=0;
	for(int i=0; i<n; i++){
		if(max < a[i]){
			max=a[i];
			pos=i;
		}
	}
	a[pos]=0;
	return pos;
}

void remove(int a[], int x){
	a[x]=0;
}

int isnotEmpty(int a[], int n){
	for(int i=0; i<n; i++){
		if(a[i]) return 1;
	}
	return 0;
}

void reverse(int G[][10], int G1[][10], int n){
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			G1[j][i]=G[i][j];
		}
	}
}

void strongConnection(int G[][10], int posty[], int n, int start){
	static int visited[10]={0};
	visited[start]=1;
	cout<<char(65+start)<<" ";
	remove(posty,start);
	for(int i=0; i<n; i++){
		if(G[start][i] && !visited[i]){
			strongConnection(G,posty,n,i);
		}
	}
}

int main()
{
	int G[10][10]={{0,1,0,1,0,0,0,0,0,0},{0,0,1,0,0,1,0,0,0,0},{1,0,0,1,1,0,0,0,0,0},{0,0,0,0,1,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,1,0,0,0,0,0,0,0},{0,0,0,0,0,1,0,1,0,0},{0,0,0,0,0,1,0,0,0,1},{0,0,0,0,0,0,0,1,0,0},{0,0,0,0,0,0,0,0,1,0}};
	int posty[10]={0,0,0,0,0,0,0,0,0,0}, cnt=1;
	int G1[10][10];
	cout<<"Strongly connected components are : \n";
	number_it(G,10,1,posty,cnt,1);
	for(int i=0; i<10; i++) cout<<posty[i]<<" ";
	cout<<"\n";
	reverse(G,G1,10);
	while(isnotEmpty(posty,10)){
		strongConnection(G1,posty,10,largest(posty,10));
		cout<<"\n";
	}
	return 0;
}
