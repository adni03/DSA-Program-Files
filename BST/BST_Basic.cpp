//BASIC BST PROGRAM

#include<iostream>
using namespace std;

struct node{
	int data, lvl;
	struct node *LC=NULL;
	struct node *RC=NULL;
};

typedef struct node *BSTPTR;

BSTPTR insert(BSTPTR T, int x, int lvl){
	if(T==NULL)
	{
		T=new(node);
		T->data=x;
		T->lvl=lvl;
		return T;
	}
	else if(T->data > x)
		T->LC=insert(T->LC,x,++lvl);
	else if(T->data < x)
		T->RC=insert(T->RC,x,++lvl);
	else
		cout<<"\nDuplicate!";
	return T;
}

int max_element(BSTPTR T){
	if(T->RC==NULL)
		return T->data;
	else
		max_element(T->RC);
}

int min_element(BSTPTR T){
	if(T->LC==NULL)
		return T->data;
	else
		min_element(T->LC);
}

void print_sorted(BSTPTR T){
	if(T==NULL)
		return ;
	else
	{
		print_sorted(T->LC);
		cout<<T->data<<" ";
		print_sorted(T->RC);
	}
}

void find(BSTPTR T, int k){
	if(T->data < k)
		find(T->RC,k);
	else if(T->data > k)
		find(T->LC,k);
	else if(T->data == k)
		cout<<"\nThe level is : "<<T->lvl;
}

int main()
{
	BSTPTR T=NULL;
	T=insert(T, 18,0);
	T=insert(T, 10,0);
	T=insert(T, 27,0);
	T=insert(T, 8,0);
	T=insert(T, 16,0);
	T=insert(T, 24,0);
	T=insert(T, 45,0);
	T=insert(T, 12,0);
	T=insert(T, 36,0);
	T=insert(T, 81,0);
	T=insert(T,63,0);
	cout<<"Sorted order : ";
	print_sorted(T);
	find(T,8);
	return 0;
}
