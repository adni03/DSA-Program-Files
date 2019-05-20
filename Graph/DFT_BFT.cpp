// DEPTH FIRST AND BREADTH FIRST TRAVERSALS

#include<iostream>
using namespace std;

struct lnode
{
	char data;
	struct lnode *next=NULL;
};

struct qnode{
	struct lnode *TEMP=NULL;
	struct qnode *next=NULL;
};

struct Queue{
	struct qnode *F=NULL;
	struct qnode *R=NULL;
};

struct queue
{
	int size, f, r;
	char ele[50];
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

void L_enq(Queue &A, LPTR M)
{
	QPTR T=NULL, F=A.F;
	T=new(qnode);
	T->TEMP=M;
	if(A.F == NULL)
	{
		A.F=T;
		A.R=T;
		T->next=NULL;
	}	
	else
	{
		while(F!=A.R)
			F=F->next;
		T->next=NULL;
		F->next=T;
		A.R=T;
	}
}

LPTR L_deq(Queue &A)
{
	int t=0;
	QPTR TEMP;
	if(A.F == NULL)
		cout<<"\nEmpty!";
	else
	{
		LPTR P=A.F->TEMP;
		TEMP=A.F;
		A.F=A.F->next;
		delete(TEMP);
		return P;
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

void print(LPTR L)
{
	if(L != NULL)
	{
		cout<<L->data<<" ";		
		print(L->next);
	}
}

void DFT(LPTR L[], int n, int vtx){
	static int visited[10]={0};
	if(vtx<n){
		LPTR T=L[vtx];
		char ch=T->data;
		visited[vtx]=1;
		T=T->next;
		while(T){
			if(!visited[T->data-65]){
				cout<<ch<<"--"<<T->data<<"\n";
				visited[T->data-65]=1;
				DFT(L,n,T->data-65);
			}
			T=T->next;
		}
	}
}

void DFT(int G[][5], int n, int vtx){
	static int visited[10]={0};
	visited[vtx]=1;
	for(int i=0; i<n; i++){
		if(G[vtx][i] && !visited[i]){
			cout<<char(65+vtx)<<"--"<<char(65+i)<<"\n";
			DFT(G,n,i);
		}
	}
}

void BFT(LPTR L[], int n, int vtx, Queue &A){
	static int visited[10]={0,0,0,0,0,0,0,0,0,0};
	L_enq(A,L[vtx]);
	visited[vtx]=1;
	do{
		LPTR T=L_deq(A);
		char ch=T->data;
		while(T){
			if(!visited[T->data-65]){
				L_enq(A,L[T->data-65]);
				cout<<ch<<"--"<<T->data<<"\n";
				visited[T->data-65]=1;
			}
			T=T->next;
		}
	}while(A.F);
}

void BFT(int G[][5], int n, int vtx, queue &A){
	static int visited[10]={0};
	A.f=A.r=-1;
	A.size=50;
	enq(A,char(65+vtx));
	visited[vtx]=1;
	while(A.f!=-1){
		char ch=deq(A);
		for(int i=0; i<n; i++){
			if(G[ch-65][i] && !visited[i]){
				enq(A,char(65+i));
				visited[i]=1;
				cout<<ch<<"--"<<char(65+i)<<"\n";
			}
		}
	}
}

void rBFT(int G[][5], int n, int start, queue &A){
	static int visited[5]={0};
	visited[start]=1;
	for(int i=0; i<n; i++){
		if(G[start][i] && !visited[i]){
			cout<<char(65+start)<<"--"<<char(65+i)<<"\n";
			enq(A,char(65+i));
			visited[i]=1;
		}
	}
	if(A.f!=-1) rBFT(G,n,deq(A)-65,A);
}

int isVisited(int a[], int n){
	for(int i=0; i<n; i++){
		if(!a[i]) return 0;
	}
	return 1;
}

void all_DFTs(int G[][5], int n, int start, queue q){
	static int visited[10]={0};
	enq(q,char(65+start));
	visited[start]=1;
	if(isVisited(visited,n)){
		while(q.f!=-1) cout<<deq(q)<<" ";
		cout<<"\n"; return ;
	}
	for(int i=0; i<n; i++){
		if(G[start][i] && !visited[i]){
			all_DFTs(G,n,i,q);
			visited[i]=0;
		}
	}
}

/*void all_BFS(int G[][5], int n, Queue Q, int start){
	static int visited[5]={0};
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
}*/

int main()
{
	LPTR L[5]={NULL,NULL,NULL,NULL,NULL};
	int G[5][5]={{0,1,1,1,0},{1,0,1,0,1},{1,1,0,1,0},{1,0,1,0,1},{0,1,0,1,0}};
	//int G[4][5]={{0,1,0,1},{1,0,1,0},{0,1,0,1},{1,0,1,0}};
	//int G[3][5]={{0,1,0},{1,0,1},{0,1,0}};
	Queue A;
	queue B;
	char c[5][5]={{'A','B','C','D'},{'B','A','C','E'},{'C','A','B','D'},{'D','A','C','E'},{'E','B','D'}};
	//char c[3][4]={{'A','B'},{'B','A','C'},{'C','B'}};
	for(int i=0; i<5; i++){
		for(int j=0; c[i][j]!='\0'; j++){
			insert_end(L[i],c[i][j]);
		}
	}
	cout<<"Adjacency list is : "<<endl;
	for(int i=0; i<5; i++){
		print(L[i]); 
		cout<<endl;
	}
	cout<<"----------------- ADJACENCY LIST ----------------";
	cout<<"\nDFT traversal of the above graph gives : \n";
	DFT(L,5,0);
	cout<<"BFT traversal of the above graph gives : \n";
	BFT(L,5,0,A);
	cout<<"----------------- ADJACENCY MATRIX ----------------";
	cout<<"\nDFT traversal of the above graph gives : \n";
	DFT(G,5,0);
	cout<<"BFT traversal of the above graph gives : \n";
	B.f=B.r=-1; B.size=20;
	rBFT(G,5,0,B);
	cout<<"All such DFTs are : \n";
	all_DFTs(G,5,0,B);
	cout<<"All such BFTs are : \n";
	//all_BFTs(G,5,A,0);
	return 0;
}
