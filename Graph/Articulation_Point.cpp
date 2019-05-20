// ARTICULATION POINT PROGRAM

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct info{
	int num, low;
};
const int n=7;

void ThisIsArt(int G[n][n], int visited[], struct info I[n], int start, int parent=-1, int cnt=0){
	visited[start]=1;
	I[start].num=cnt++; I[start].low=I[start].num;
	for(int i=0; i<n; i++){
		if(G[start][i]){
			if(!visited[i]){ //NORMAL EDGE
				ThisIsArt(G,visited,I,i,start,cnt);
				I[start].low=min(I[start].low,I[i].low);
				
			}
			else if(visited[i] && i!=parent){ //BACK EDGE CONDITION
				I[start].low=min(I[start].low,I[i].num);
			}
		}
	}
	if(I[start].low >= I[parent].num){  //ARTICULATION POINT CONDITION
		cout<<"Articulation point : "<<char(65+parent)<<"\n";
	}
	if(I[start].low > I[parent].num){ //BRIDGE CONDITION
		cout<<"Bridge : "<<char(65+start)<<"--"<<char(65+parent)<<"\n";
	}
}

int main()
{
	int G[n][n]={{0,1,1,0,0,0,0},{1,0,0,1,0,0,0},{1,0,0,1,0,0,0},{0,1,1,0,1,1,0},{0,0,0,1,0,1,0},{0,0,0,1,1,0,1},{0,0,0,0,0,1,0}};
	int visited[n]={0}, start=0;
	struct info I[n];
	cout<<"The Incidence matrix is : \n";
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout<<G[i][j]<<" ";
		}
		cout<<"\n";
	}
	cout<<"Articulation Points : \n";
	ThisIsArt(G,visited,I,start);
	return 0;
}
