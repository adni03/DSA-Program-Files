//DEAD NODE

#include<iostream>
using namespace std;

struct node{
	int data, space, min, max;
	struct node *LC;
	struct node *RC;
};

typedef struct node *BSTPTR;

BSTPTR insert(BSTPTR T, int x){
	if(T==NULL)
	{
		T=new(node);
		T->data=x;
		T->LC=NULL;
		T->RC=NULL;
		return T;
	}
	else if(T->data > x)
		T->LC=insert(T->LC,x);
	else if(T->data < x)
		T->RC=insert(T->RC,x);
	else
		cout<<"\nDuplicate!";
	return T;
}

void give_death(BSTPTR T, int s, int l){
	if(T){
		if(s==l) cout<<T->data<<" ";
		else{
			give_death(T->LC,s,T->data-1);
			give_death(T->RC,T->data+1,l);
		}
	}
}

int main()
{
	BSTPTR T=NULL;
	T=insert(T,18);
	T=insert(T,10);
	T=insert(T,45);
	T=insert(T,8);
	T=insert(T,37);
	T=insert(T,60);
	T=insert(T,5);
	T=insert(T,9);
	T=insert(T,40);
	T=insert(T,58);
	T=insert(T,59);
	cout<<"Dead nodes are : ";
	give_death(T,0,500);
	return 0;
}


