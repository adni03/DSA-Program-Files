//PRINT COURSES

#include<iostream>
using namespace std;

struct lnode
{
	int data;
	struct lnode *next=NULL;
};

struct queue
{
	int size, f, r;
	int ele[50];
};

typedef struct qnode* QPTR;
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

int deq(queue &q)
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

void insert_f(LPTR &L, int n)
{
	LPTR T;
	T=new(lnode);
	T->data = n;
	T->next=L;
	L=T;
}

void insert_end(LPTR &L, int n)
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

int pop(LPTR &L){
	LPTR TEMP=L;
	int x=TEMP->data;
	L=L->next;
	delete(TEMP);
	return x;
}

void print(LPTR L){
	if(L){
		cout<<L->data<<" ";		
		print(L->next);
	}
}

int indegree(int G[][7], int n, int v){
	int deg=0;
	for(int i=0; i<n; i++){
		deg+=G[v][i];
	}
	return deg;
}

void input(int G[][12], int i){
	int ch=0; int n;
	while(ch!=-1){
		cout<<"Enter number : ";
		cin>>n;
		G[i][n-1]=1;
		cout<<"2: continue / -1: stop : ";
		cin>>ch;
	}
}

void Topological_Sort(int G[][7], int n){
	int in_deg[7];
	for(int i=0; i<7; i++){
		in_deg[i]=indegree(G,n,i);
	}
	for(int i=0; i<n; i++){
		if(in_deg[i]==0){
			cout<<i+1<<" ";	
		}
		for(int j=0; j<n; j++){
			if(G[j][i]) --in_deg[j];
		}
	}
}

void attach(LPTR &A, LPTR &B){ //A goes into B
	LPTR T1=B, T2=A;
	while(T1->data!=A->data) T1->next;
	while(T2) T2->next;
	T2->next=T1->next;
	T1->next=A;
}

void Euler_path(int G[][6], int start, int n, LPTR &A, LPTR &B, int prev=-1){
	int flag=0;
	insert_end(A,start+1);
	for(int i=0; i<n; i++){
		if(G[start][i] && i!=prev){
			G[start][i]=0;
			G[i][start]=0;
			Euler_path(G,i,n,A,B,start);
			flag=1;
		}
	}
	//SPLICING 
	if(!flag){
		if(!B){
			B=A;
			A=NULL;
		}
		else{
			LPTR TEMP=A;
			while(TEMP){
				if(TEMP->data) break;
			}
			attach(A,B);
		}
	}
}

int isVisited(int a[], int n){
	for(int i=0; i<n; i++){
		if(!a[i]) return 0;
	}
	return 1;
}

int isThere(int G[][6], int n){
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(G[i][j]) return 1;
		}
	}
	return 0;
}

void all_Euler(int G[][6], int n, int start, int end, queue q, int &cnt, int prev=-1){ // FOR ALL EULER PATHS
	enq(q,start+1);
	for(int i=0; i<n; i++){
		if(G[start][i] && i!=prev){
			G[start][i]=0;
			G[i][start]=0;
			all_Euler(G,n,i,end,q,cnt,start);
			G[start][i]=1;
			G[i][start]=1;
		}
	}
	if(start==end && !isThere(G,n)){
		while(q.f!=-1) cout<<deq(q)<<" ";
		cout<<"\n";
		cnt++;
	}
}

void Topo(int G[][7], int visited[], int n, int start, LPTR &A){
	visited[start]=1;
	for(int i=0; i<n; i++){
		if(G[i][start] && !visited[i]){
			Topo(G,visited,n,i,A);
		}
	}
	insert_f(A,start+1);
}

void TopoDriver(int G[][7], int n, int start){
	int visited[7]={0};
	LPTR A=NULL;
	while(!isVisited(visited,7)){
		int i=0;
		for(i=0; i<n; i++){
			if(!visited[i]) break;
		}
		Topo(G,visited,n,i,A);
	}
	while(A) cout<<pop(A)<<" ";
}

int main()
{
	int G1[7][7]={{0,0,0,0,0,0,0},{0,0,0,0,0,0,0},{0,0,0,0,0,0,0},{1,1,0,0,0,0,0},{1,0,1,0,0,0,0},{0,0,0,1,0,0,0},{0,0,0,0,1,1,0}};
	int G[6][6]={{0,1,0,1,1,1},{1,0,1,1,1,0},{0,1,0,1,0,0},{1,1,1,0,1,0},{1,1,0,1,0,1},{1,0,0,0,1,0}};
	int G2[3][3]={{0,1,1},{1,0,1},{1,1,0}};
	LPTR A=NULL, B=NULL, C=NULL;
	int cnt=0;
	queue q; q.f=q.r=-1; q.size=50;
	cout<<"The courses are : ";
	Topological_Sort(G1,7);
	cout<<"\nPath is : ";
	//Euler_path(G,0,6,A,B);
	//print(B);
	cout<<"\nTopological Sort the right way : ";
	TopoDriver(G1,7,0);
	cout<<"\nAll Euler Paths : \n";
	all_Euler(G,6,0,0,q,cnt);
	cout<<"No. of Euler paths : "<<cnt;
	return 0;
}
