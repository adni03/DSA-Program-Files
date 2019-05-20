//COUNT NUMBER OF NODES AT EACH LEVEL USING BFS

#include<iostream>
using namespace std;

const int n=10;
struct Queue
{
	int size, f, r;
	int ele[50];
};

void enq(Queue &q, char x)
{
	if(q.f == (q.r +1)%q.size)
		cout<<"\nFull!";
	else
	{
		if(q.f == -1)
			q.f=0;
		q.r=(q.r + 1)%q.size;
		q.ele[q.r] = x;
	}		
}

int deq(Queue &q)
{
	char t;
	if(q.f == -1)
		cout<<"\nEmpty!";
	else
	{
		t=q.ele[q.f];
		if(q.f == q.r)
		{
			q.f=-1;
			q.r=-1;
		}
		else
			q.f=(q.f+1)%q.size;
		return t;
	}
}

void BFS(int G[n][n], int visited[n], int nodes[], Queue Q, int start, int cnt=1){
	visited[start]=1; //make vertex visited
	enq(Q,-1);
	for(int i=0; i<n; i++){
		if(G[start][i] && !visited[i]) //if its adjacent and isnt visited
		{
			cout<<start<<"-->"<<i<<"\n";
			nodes[cnt]++;
			visited[i]=1;
			enq(Q,i);
		}
	}
	if(Q.f!=-1){
		int x=deq(Q);
		if(x==-1){
			++cnt;
			x=deq(Q);
		}
		if(x!=-1) BFS(G,visited,nodes,Q,x,cnt);
	}
}

void all_BFS(int G[n][n], int visited[], Queue Q, int start){
	visited[start]=1; //make vertex visited
	for(int i=0; i<n; i++){
		if(G[start][i] && !visited[i]) //if its adjacent and isnt visited
		{
			cout<<start<<"-->"<<i<<"\n";
			visited[i]=1;
			enq(Q,i);
		}
	}
	if(Q.f!=-1){
		int x=deq(Q);
		all_BFS(G,visited,Q,x);
		visited[x]=0;
	}
}

int main()
{
	int G[n][n]={{0,1,1,0,0,0,0,0,0,0},{1,0,0,1,1,0,0,0,0,0},{1,0,0,0,0,1,1,0,0,0},{1,0,0,0,0,0,0,1,0,0},{0,1,0,0,0,0,0,0,1,1},{0,0,1,0,0,0,0,0,0,0},{0,0,1,0,0,0,0,0,0,0},{0,0,0,1,0,0,0,0,0,0},{0,0,0,0,1,0,0,0,0,0},{0,0,0,0,1,0,0,0,0,0}};
	int visited[n]={0};
	int nodes[n]={0};
	nodes[0]=1;
	Queue Q; Q.f=Q.r=-1; Q.size=20;
	cout<<"Recursive BFT : \n";
	BFS(G,visited,nodes,Q,0);
	for(int i=0; i<n; i++) visited[i]=0;
	cout<<"All such BFTs are : \n";
	all_BFS(G,visited,Q,0);
	return 0;
}
