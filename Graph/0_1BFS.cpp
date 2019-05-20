// 0-1 BFS

#include<iostream>
using namespace std;

const int n=9;

struct dist{
	int from, to, dist;
};

struct node{
	int data;
	struct node *next=NULL;
};

struct Queue{
	struct node *F=NULL;
	struct node *R=NULL;
};

struct stack{
	int size, top, elements[50];
};

typedef struct node* QPTR;
typedef struct dlnode* DPTR;

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

void L_enq(Queue &A, int x){
	QPTR T=NULL, TEMP=A.F;
	T=new(node);
	T->data=x;
	if(!A.F){
		A.F=T;
		A.R=T;
		T->next=NULL;
	}	
	else{
		while(TEMP!=A.R)
			TEMP=TEMP->next;
		T->next=NULL;
		TEMP->next=T;
		A.R=T;
	}
}

int L_deq(Queue &A){
	int t=0;
	QPTR TEMP;
	if(!A.F)
		cout<<"\nEmpty!";
	else{
		t=A.F->data;
		TEMP=A.F;
		A.F=A.F->next;
		delete(TEMP);
		return t;
	}
}

void pathIs(struct dist D[], int start, int end, stack m){
	if(start==end){
		while(m.top!=-1) cout<<pop(m)<<" ";
	}
	else{
		push(m,D[end].from);
		pathIs(D,start,D[end].from,m);
	}
}

void ShortBFS(int G[][n], int start, int end, Queue A, Queue B){
	struct dist D[n];
	stack m; m.top=-1; m.size=50;
	for(int i=0; i<n; i++){
		D[i].from=D[i].to=-1;
		D[i].dist=62000;
	}
	L_enq(A,start);
	D[start].dist=0;
	while(A.F || B.F){
		int vtx=0;
		if(A.F) vtx=L_deq(A);
		else vtx=L_deq(B);
		for(int i=0; i<n; i++){
			if(G[vtx][i]){
				if(D[i].dist > D[vtx].dist + G[vtx][i]){
					D[i].from=vtx;
					D[i].to=i;
					D[i].dist = D[vtx].dist + G[vtx][i];
					if(G[vtx][i]==2) L_enq(A,i);
					else L_enq(B,i);
				}
			}
		}
	}
	pathIs(D,start,end,m);
	cout<<end<<" ";
	cout<<"\nWith distance equal to : "<<D[end].dist;
}

int main()
{
	Queue A, B;
	int G[n][n]={{0,2,0,0,0,0,0,3,0},{2,0,3,0,0,0,0,3,0},
				{0,3,0,2,0,2,0,0,3},{0,0,2,0,3,3,0,0,0},
				{0,0,0,3,0,3,0,0,0},{0,0,2,3,3,0,3,0,0},
				{0,0,0,0,0,3,0,3,3},{3,3,0,0,0,0,3,0,3},{0,0,3,0,0,0,3,3,0}};
	int start=0, end=5;
	cout<<"The shortest path from "<<start<<" to "<<end<<" is : ";
	ShortBFS(G,start,end,A,B);
	return 0;
}
