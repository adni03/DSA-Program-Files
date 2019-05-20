// DIJKSTRA ALGO

#include<iostream>
using namespace std;

struct stack 
{
	int size, top, elements[50];
};

void push(stack &m, int x){
	if(m.top < m.size-1)
		m.elements[++m.top] = x;
	else
		cout<<"\nOverflow";
}

int pop(stack &m){
	if(m.top == -1)
		cout<<"\nEmpty";
	else 
		return (m.elements[m.top--]);
}

int isVisited(int a[], int n){
	for(int i=0; i<n; i++){
		if(!a[i]) return 1;
	}
	return 0;
}

int inSpset(int spSet[], int x, int n){
	for(int i=0; i<n; i++){
		if(spSet[i]==x) return 1;
	}
	return 0;
}

int getMinDist(int info[][2], int spSet[], int n){
	int min=1000, pos=-1;
	for(int i=0; i<n; i++){
		if(min > info[i][0] && !inSpset(spSet,i,n)){
			min = info[i][0];
			pos = i;
		}
	}
	return pos;
}

/*void Djikstra(int G[][9], int info[][2], int S[], int n, int start){
	static int cnt=n-1, k=1;
	if(cnt > 0){
		int min=1000, vtx=-1;
		for(int i=0; i<n; i++){
			if(G[start][i]){
				if(info[i][0] > info[start][0] + G[start][i]){
					info[i][0] = info[start][0] + G[start][i];
					info[i][1] = start;
					if(min > info[i][0]){
						min = info[i][0];
						vtx = i;
					}
				}
			}
		}
		vtx = getMinDist(info,S,n);
		S[k++] = vtx;
		--cnt;
		Djikstra(G,info,S,n,vtx);
	}
}*/

void Dijkstra(int G[n][n], int start, int &sum){
	static int visited[n]={0};
	if(isVisited(visited)) return ;
	visited[start]=1;
	int min=100, from=0, to=0, flag=0;
	for(int i=0; i<n; i++){
		if(visited[i]){
			for(int j=0; j<n; j++){
				if(G[i][j] && !visited[j]){
					if(G[i][j] < min){
						min=G[i][j];
						from=i;
						to=j;
						flag=1;
					}
				}
			}
		}
	}
	if(flag){
		cout<<from+1<<"->"<<to+1<<"\n";
		sum+=G[from][to];
		Prims(G,to,sum);
	}
}


void print_shortest_path(int info[][2], stack m, int start, int end){
	if(info[end][0]==0){
		while(m.top!=-1) cout<<pop(m)<<" ";
	}
	else{
		push(m,info[end][1]);
		print_shortest_path(info,m,start,info[end][1]);
	}
}

int main()
{
	stack m; m.top=-1; m.size=50;
	int G[9][9] = {{0, 4, 0, 0, 0, 0, 0, 8, 0}, 
                      {4, 0, 8, 0, 0, 0, 0, 11, 0}, 
                      {0, 8, 0, 7, 0, 4, 0, 0, 2}, 
                      {0, 0, 7, 0, 9, 14, 0, 0, 0}, 
                      {0, 0, 0, 9, 0, 10, 0, 0, 0}, 
                      {0, 0, 4, 14, 10, 0, 2, 0, 0}, 
                      {0, 0, 0, 0, 0, 2, 0, 1, 6}, 
                      {8, 11, 0, 0, 0, 0, 1, 0, 7}, 
                      {0, 0, 2, 0, 0, 0, 6, 7, 0} 
                     }; 
	int info[9][2]={{100,0},{100,0},{100,0},{100,0},{100,0},{100,0},{100,0},{100,0},{100,0}}; //info[distance][from vertex]
	int S[9] = {0};
	int start=0;
	int end=8;
	info[start][0]=0;
	Djikstra(G,info,S,9,0);
	for(int i=0; i<9; i++){
			cout<<"Vertex : "<<i<<"| Dist : "<<info[i][0]<<" | Parent : "<<info[i][1]<<" |\n";
	}
	cout<<"The shortest path from start to end is : ";
	print_shortest_path(info,m,start,end);
	cout<<end;
	return 0;
}
