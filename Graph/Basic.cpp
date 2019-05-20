//GRAPH - in-degree, out-degree, checks if there is a cycle from adjacency matrix

#include<iostream>
using namespace std;

struct lnode
{
	char data;
	struct lnode *next=NULL;
};

struct queue
{
	int size, f, r;
	char ele[50];
};

typedef struct lnode* LPTR;

void enq(queue &q, char x)
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

char deq(queue &q)
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

void insert_f(LPTR &L, char n)
{
	LPTR T;
	T=new(lnode);
	T->data = n;
	T->next=L;
	L=T;
}

void insert_end(LPTR &L, char n)
{
	LPTR T, TEMP=L;
	if(L == NULL)
	{
		insert_f(L,n);
	}
	else
	{
		while(TEMP->next != NULL)
			TEMP=TEMP->next;
		T=new(lnode);
		T->data = n;
		T->next = NULL;
		TEMP->next=T;
	}
}

int indegree(int G[][5], int n, int v){
	int deg=0;
	for(int i=0; i<n; i++){
		deg+=G[i][v-1];
	}
	return deg;
}

int outdegree(int G[][5], int n, int v){
	int deg=0;
	for(int i=0; i<n; i++){
		deg+=G[v-1][i];
	}
	return deg;
}

int cycle(int G[][5], int n, int vtx, int prev=-1){
	static int visited[10]={0};
	visited[vtx]=1;
	cout<<char(65+vtx)<<" ";
	for(int i=0; i<n; i++){
		if(G[vtx][i] && !visited[i]){
			if(cycle(G,n,i,vtx)) return 1;
		}
		else if(G[vtx][i] && visited[i] && i!=prev){
			cout<<char(65+i);
			return 1;
		}
	}
	return 0;
}

int cycle_al(LPTR L[], int n, int vtx, char ch='\0'){
	static int visited[10]={0,0,0,0,0,0,0,0,0,0};
	if(vtx<n){
		LPTR T=L[vtx];
		visited[vtx]=1;
		T=T->next;
		while(T){
			if(!visited[T->data-65]){
				visited[T->data-65]=1;
				char ch=L[vtx]->data;
				if(cycle_al(L,n,T->data-65,ch)) return 1;
			}
			else if(T->data!=ch) return 1;
			T=T->next;
		}
	}
	return 0;
}

void print_all_paths(int G[][5], int n, int start, int end, queue q){
	static int visited[10]={0};
	enq(q,char(65+start));
	visited[start]=1;
	if(start==end){
		while(q.f!=-1) cout<<deq(q)<<" ";
		cout<<"\n";
		return ;
	}
	for(int i=0; i<n; i++){
		if(G[start][i] && !visited[i]){
			print_all_paths(G,n,i,end,q);
			visited[i]=0;
		}
	}
}

/*int print_path(int G[][5], int visited[], int n, int start, int end){
	//cout<<char(65+start)<<" ";
	visited[start]=1;
	if(start==end) return 1;
	for(int i=0; i<n; i++){
		if(G[start][i] && !visited[i]){
			if(print_path(G,visited,n,i,end)){
				return 1;	
			}
		}
	}
}*/

void print_path(int G[][5], int visited[], int n, int start, int end){
	cout<<char(65+start)<<" ";
	visited[start]=1;
	if(start==end) return ;
	for(int i=0; i<n; i++){
		if(G[start][i] && !visited[i]){
			print_path(G,visited,n,i,end);	
		}
	}
}


void print(LPTR L)
{
	if(L != NULL)
	{
		cout<<L->data<<" ";		
		print(L->next);
	}
}

void reset(int a[], int n){
	for(int i=0; i<n; i++) a[i]=0;
}

int main()
{
	int G[5][5]={{0,1,1,1,0},{1,0,1,0,1},{1,1,0,1,0},{1,0,1,0,1},{0,1,0,1,0}};
	//int G[4][5]={{0,1,0,1},{1,0,1,0},{0,1,0,1},{1,0,1,0}};
	//int G[3][5]={{0,1,0},{1,0,1},{0,1,0}};
	int visited[5]={0};
	char path[10];
	int n=5;
	queue q; q.f=q.r=-1;
	q.size=50;
	cout<<"Indegree is : "<<indegree(G,4,1);
	cout<<"\nOutdegree is : "<<outdegree(G,4,1);
	cout<<"\n-------------------------------------------\n";
	cout<<"Adjacency matrix is : \n";
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout<<G[i][j]<<" ";
		}
		cout<<endl;
	}
	if(cycle(G,5,0)==1) cout<<"\nCycle is present!";
	else cout<<"No Cycle!";
	cout<<"\n-------------------------------------------";
	/*-------- ADJACENCY LIST -------*/
	LPTR L[5]={NULL,NULL,NULL,NULL,NULL};
	//char c[5][5]={{'A','B','C','D'},{'B','A','C','E'},{'C','A','B','D'},{'D','A','C','E'},{'E','B','D'}};
	char c[3][4]={{'A','B'},{'B','A','C'},{'C','B'}};
	for(int i=0; i<3; i++){
		for(int j=0; c[i][j]!='\0'; j++){
			insert_end(L[i],c[i][j]);
		}
	}
	cout<<"\nAdjacency list is : \n";
	for(int i=0; i<3; i++){
		print(L[i]); 
		cout<<endl;
	}
	if(cycle_al(L,3,0)==1) cout<<"Cycle is present!\n";
	else cout<<"No Cycle!\n";
	cout<<"-------------------------------------------\n";
	cout<<"All possible paths from start to end are : \n";
	cout<<"Total number of paths are : \n";
	print_all_paths(G,5,0,4,q);
	//int flag=-1;
	//cout<<"Mother vertices are : ";
	/*for(int i=0; i<5; i++){
		for(int j=i+1; j<5; j++){
			if(print_path(G,visited,5,i,j)) flag=1;
			else flag=0;
			reset(visited,5);
		}
		if(flag!=0) cout<<char(65+i)<<" ";
	}*/
	//print_path(G,visited,5,2,4);
	return 0;
}
