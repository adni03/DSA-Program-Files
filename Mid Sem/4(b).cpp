//4)B)

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

int main()
{
	BSTPTR T=NULL;
	int arr[9]={7,4,12,3,6,8,1,5,10};
	for(int i=0; i<9; i++)
		insert(T,arr[i]);
	cout<<"Inorder traversal is : ";
	print_sorted(T);
	return 0;
}
