//MAKE ANY NODE ROOT OF A BST

#include<iostream>
using namespace std;

struct node{
	int data;
	struct node *LC;
	struct node *RC;
};

typedef struct node *BSTPTR;

void insert(BSTPTR &T, int x){
	if(T==NULL)
	{
		T=new(node);
		T->data=x;
		T->LC=NULL;
		T->RC=NULL;
	}
	else if(T->data > x)
		insert(T->LC,x);
	else if(T->data < x)
		insert(T->RC,x);
	else
		cout<<"\nDuplicate!";
}

BSTPTR find(BSTPTR T, int k){
	if(T->data < k)
		find(T->RC,k);
	else if(T->data > k)
		find(T->LC,k);
	else if(T->data == k)
		return T;
	else 
		return NULL;
}

void remove(BSTPTR &TEMP, int k){
	if(TEMP){
		if(TEMP->data==k){
			if(!TEMP->LC && !TEMP->RC){
				TEMP=NULL;
			}
			else if(TEMP->LC && TEMP->RC){
				int n=1000;
				min(TEMP->RC,n);
				remove(TEMP->RC,n);
				TEMP->data=n;
			} 
			else if(TEMP->LC){
				int n;
				max(TEMP->LC,n);
				remove(TEMP->LC,n);
				TEMP->data=n;
			}
			else if(TEMP->RC){
				int n=1000;
				min(TEMP->RC,n);
				remove(TEMP->RC,n);
				TEMP->data=n;
			} 
		}
		if(TEMP){
			if(TEMP->data<=k) remove(TEMP->RC,k);
			else remove(TEMP->LC,k);
		}
	}
}

void min(BSTPTR T, int &mini){
	if(T){
		if(T->data<mini) mini=T->data;
		min(T->LC,mini);
		min(T->RC,mini);
	}
}

void max(BSTPTR T, int &maxi){
	if(T){
		if(T->data>maxi) maxi=T->data;
		max(T->LC,maxi);
		max(T->RC,maxi);	
	}
}

