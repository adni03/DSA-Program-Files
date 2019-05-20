//1

#include<iostream>
using namespace std;

struct bstnode{
	struct bstnode *LC=NULL;
	struct bstnode *RC=NULL;
	int key;
	int *HPTR=NULL;
};

typedef struct bstnode *BSTPTR;

void create(BSTPTR &T, int k, int x){
	if(T){
		if(k < T->key) create(T->LC,k,x);
		else if(k > T->key) create(T->RC,k,x);
		else{
			T->HPTR[*(T->HPTR)]=x;
			++*(T->HPTR);
		}
	}
	else{
		T=new(bstnode);
		T->key=k;
		T->HPTR=new(int[10]);
		for(int j=0; j<10; j++) T->HPTR[j]=0;
		++*(T->HPTR);
		T->HPTR[1]=x;
		++*(T->HPTR);
	}
}

void find(BSTPTR T, int k, int t){
	if(t==0){
		if(T){
			if(k < T->key) find(T->LC,k,0);
			else if(k > T->key) find(T->RC,k,0);
			else find(T,*(T->HPTR),1);
		}
	}
	else if(t==1){
		if(k>0){
			const int s=*(T->HPTR);
			if(T->HPTR[s-k+1]!=0) cout<<T->HPTR[s-k+1]<<" ";
			find(T,k-1,1);
		}
	}
}

int main()
{
	BSTPTR T=NULL;
	int n;
	create(T,5,1);
	create(T,4,2);
	create(T,8,3);
	create(T,1,4);
	create(T,6,5);
	create(T,9,6);
	create(T,2,7);
	create(T,3,8);
	create(T,3,9);
	cout<<"Enter key value : ";
	cin>>n;
	find(T,n,0);
	return 0;
}
