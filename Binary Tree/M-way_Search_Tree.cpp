//M-WAY SEARCH TREE

#include<iostream>
#include<string.h>
using namespace std;

struct mtnode{
	int data[40], space[40];
	struct mtnode *PTR[41];
	int m;
};

struct qnode{
	struct mtnode *TEMP=NULL;
	struct qnode *next=NULL;
};

struct Queue{
	struct qnode *F=NULL;
	struct qnode *R=NULL;
};

struct snode{
	struct bdnode *TR;
	struct snode *next;
};

struct stack{
	struct snode *T;
};

typedef struct mtnode *MTPTR;
typedef struct qnode* QPTR;
typedef struct snode *LPTR;

void L_enq(Queue &A, MTPTR M)
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

MTPTR L_deq(Queue &A)
{
	int t=0;
	QPTR TEMP;
	if(A.F == NULL)
		cout<<"\nEmpty!";
	else
	{
		MTPTR P=A.F->TEMP;
		TEMP=A.F;
		A.F=A.F->next;
		delete(TEMP);
		return P;
	}
}

void insert(MTPTR &T, int k, int m){
	if(!T){
		T=new(mtnode);
		for(int j=0; j<m; ++j) T->data[j]=0;
		T->data[0]=k;
		for(int j=0; j<m+1; ++j) T->PTR[j]=NULL;
		T->m=m;
	}
	else{
		int j=0, flag=-1;
		if(k > T->data[0]){
			for(j=0; j<m; j++){
				if(T->data[j]==0){
					T->data[j]=k; flag=0;
					break;
				}
				else if(k > T->data[j]){
					flag=1; 
				} 
				else break;
			}
			if(flag==1) insert(T->PTR[j],k,m);
			//else if(flag==-1) insert(T->PTR[m-1],k,m);
		}
		else{
			insert(T->PTR[0],k,m);
		}
	}
}

int find(MTPTR T, int k, int m){
	if(T){
		if(k > T->data[0]){
			int j=0;
			while(k > T->data[j] && j<m) j++;
			if(T->data[j]!=k) find(T->PTR[j],k,m);
			else return 1;
		}
		else if(k < T->data[0])
			find(T->PTR[0],k,m);
		else 
			return 1;
	}
}

void print(MTPTR T, int m){
	if(T){
		for(int i=0; i<m+1; i++){
			if(T->PTR[i]) print(T->PTR[i],m);
			if(T->data[i]!=0) cout<<T->data[i]<<" ";
		}
	}
}

int find_max(MTPTR T, int m){
	if(T){
		int i=0;
		for(i=0; T->data[i]!=0 && i<m; i++);
		if(T->PTR[i]) find_max(T->PTR[i],m);
		else return T->data[i-1];
	}
}

int find_min(MTPTR T, int m){
	if(T){
		if(T->PTR[0]) find_min(T->PTR[0],m);
		else return T->data[0];
	}
}

void remove(MTPTR &T, int k, int m){
	if(T){
		int i=0;
		if(k >= T->data[i]){
			int j=0, p=0;
			while(k > T->data[j] && j<m) j++;
			if(T->data[j]==k){
				if(!T->PTR[j] || !T->PTR[j+1]){
					if(!T->PTR[j] && !T->PTR[j+1]){
						int k=0; 
						while(T->PTR[k]) k++;
						if(k<=j){
							int x=find_max(T->PTR[j],3);
							remove(T,x,3);
							T->data[j]=x;
						}
						else{
							int x=find_min(T->PTR[j+1],3);
							remove(T,x,3);
							T->data[j]=x;
						}
					}
					else if(!T->PTR[j+1]){
						int x=find_max(T->PTR[j],3);
						remove(T,x,3);
						T->data[j]=x;
					}
					else{
						int x=find_min(T->PTR[j+1],3);
						remove(T,x,3);
						T->data[j]=x;
					}
				}
				else{
					int x=find_min(T->PTR[j+1],3);
					remove(T,x,3);
					T->data[j]=x;
				}
			}
			else if(T->data[j-1]!=k) remove(T->PTR[j],k,m);
		}
		else if(k < T->data[i])
			remove(T->PTR[i],k,m);
	}
}

void number_it(MTPTR T, int &i, int m){
	if(T==NULL)
		return ;
	else
	{
		for(int j=0; j<=T->m; j++){
			number_it(T->PTR[j],i,m);
			T->space[j]=i;
			++i;
		}
	}
}

void print_same(Queue A, MTPTR T, int m){
	int i=0, k=1, n=0;
	L_enq(A,T);
	L_enq(A,NULL);
	number_it(T,k,3);
	do
	{
		T=L_deq(A);
		if(T==NULL)
		{
			cout<<endl;
			T=L_deq(A);
			L_enq(A,NULL);
			n=0;
		}
		for(int i=0; i<=m; i++){
			for(int j=T->space[i]-1; j>n; --j) cout<<" ";
			n=T->space[i];
			if(T->data[i]!=0) cout<<T->data[i]<<" ";
			if(T->PTR[i]) L_enq(A,T->PTR[i]);
		}
	}while(A.F!=A.R);
}

void print_line(Queue A, MTPTR T, int m){
	L_enq(A,T);
	L_enq(A,NULL);
	do
	{
		T=L_deq(A);
		if(T==NULL)
		{
			cout<<endl;
			T=L_deq(A);
			L_enq(A,NULL);
		}
		for(int i=0; i<=m; i++){
			cout<<T->data[i]<<" ";
			if(T->PTR[i]) L_enq(A,T->PTR[i]);
		}
		cout<<"   ";
	}while(A.F!=A.R);
}

int main()
{
	MTPTR T=NULL; 
	Queue A;
	int n;
	insert(T,20,3);
	insert(T,40,3);
	insert(T,60,3);
	insert(T,5,3);
	insert(T,10,3);
	insert(T,15,3);
	insert(T,50,3);
	insert(T,51,3);
	insert(T,55,3);
	insert(T,56,3);
	insert(T,70,3);
	insert(T,80,3);
	insert(T,90,3);
	insert(T,1,3);
	insert(T,2,3);
	insert(T,3,3);
	insert(T,6,3);
	insert(T,7,3);
	insert(T,8,3);
	insert(T,52,3);
	insert(T,53,3);
	insert(T,54,3);
	cout<<"Tree in level order line by line is : "<<endl;
	print_line(A,T,3);
	cout<<"\nInOrder is : ";
	print(T,3);
	cout<<"\nEnter element : ";
	cin>>n;
	if(find(T,n,3)) cout<<"Element found!";
	else cout<<"Not found!";
	cout<<"\nMax is : "<<find_max(T,3);
	cout<<"\nMin is : "<<find_min(T,3);
	cout<<"\nTree in level order line by line is : "<<endl;
	print_line(A,T,3);
	cout<<"\nEnter element to delete : ";
	cin>>n;
	remove(T,n,3);
	cout<<"Tree in level order line by line is : "<<endl;
	print_line(A,T,3);
	return 0;
}
