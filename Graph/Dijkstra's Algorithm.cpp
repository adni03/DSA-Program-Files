// DIJKSTRA ALGO

#include<iostream>
using namespace std;

struct stack 
{
	int size, top, elements[50];
};

struct queue
{
	int size, f, r;
	char ele[50];
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

void enq(queue &q, char x){
	if(q.f == (q.r +1)%q.size)
		cout<<"\nFull!";
	else{
		if(q.f == -1)
			q.f=0;
		q.r=(q.r + 1)%q.size;
		q.ele[q.r] = x;
	}		
}

char deq(queue &q){
	char t;
	if(q.f == -1)
		cout<<"\nEmpty!";
	else{
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

int isVisited(int a[], int n){
	for(int i=0; i<n; i++){
		if(!a[i]) return 1;
	}
	return 0;
}

void update_info(int G[][9], int info[][2], int n, int start){
	if(start<n){
		for(int i=0; i<n; i++){ //updates information of adjacent vertices
			if(G[start][i]){ // i -> current vertex; start -> source vertex	
				if(info[i][0] > info[start][0] + G[start][i]){
					info[i][0] = info[start][0] + G[start][i];
					info[i][1] = start+1;
				}
			}
		}
		update_info(G,info,n,start+1);
	}
}

void print_shortest_path(int info[][2], stack m, int start, int end){
	if(info[end-1][0]==0){
		while(m.top!=-1) cout<<pop(m)<<" ";
	}
	else{
		push(m,info[end-1][1]);
		print_shortest_path(info,m,start,info[end-1][1]);
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
	int start=0;
	int end=3;
	cout<<"The shortest path from start to end is : ";
	info[start][0]=0;
	update_info(G,info,9,start);
	print_shortest_path(info,m,start,end);
	cout<<end;
	return 0;
}
