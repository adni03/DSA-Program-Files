//RADIX SORT using MULTI-LEVEL LINKED LIST

#include<iostream>
using namespace std;

typedef struct node* LPTR;

struct Bucket
{
	int rad;
	struct node *L;
	struct Bucket *NBKT;
};
struct node
{
	int data;
	struct node *next;
};

typedef struct Bucket* BPTR;

int max(int a[], int n)
{
	int max=a[0];
	for(int i=0; i<n; i++)
	{
		if(a[i]>max)
			max=a[i];
	}
	return max;
}

BPTR find(BPTR B, int x)
{
	while(B->rad!=x)
		B=B->NBKT;
	return B;
}

int pop(BPTR &B)
{
	LPTR TEMP=B->L;
	if(TEMP==NULL)
		return -1;
	else
	{
		int x=TEMP->data;
		B->L=B->L->next;
		delete(TEMP);
		return x;
	}
}

void push(BPTR &B, int n)
{
	LPTR TEMP, A=B->L;
	TEMP=new(node);
	TEMP->data = n;
	if(B->L == NULL)
	{
		TEMP->next=NULL;
		B->L=TEMP;
	}
	else
	{
		while(A->next!=NULL)
			A=A->next;
		TEMP->next=NULL;
		A->next=TEMP;
	}
}

void c_bckt(BPTR &B, int x)
{
	BPTR T, TEMP=B;
	T=new(Bucket);
	T->rad=x;
	T->L=NULL;
	if(B==NULL)
	{
		T->NBKT=NULL;
		B=T;
	}
	else
	{
		while(TEMP->NBKT!=NULL)
			TEMP=TEMP->NBKT;
		T->NBKT=NULL;
		TEMP->NBKT=T;
	}	
}

void countSort(int a[], int n, int e)
{
	BPTR B=NULL, T;
	int m, j=0; 
	for(int i=0; i<10; i++) //initializes everything 
		c_bckt(B,i);
	for(int i=0; i<n; i++)
	{
		T=find(B,(a[i]/e)%10);
		push(T,a[i]); 
	}
	j=0;
	for(BPTR I=B; I!=NULL; I=I->NBKT)
	{
		m=pop(I);
		while(m!=-1)
		{
			a[j++]=m;
			m=pop(I);
		}
	}
}

void radixSort(int a[], int n)
{
	int m=max(a,n);
	for(int exp=1; m/exp>0; exp*=10)
		countSort(a,n,exp);
}

int main()
{
	int a[100], n;
	cout<<"\nEnter number of elements : ";
	cin>>n;
	cout<<"\nEnter elements : ";
	for(int i=0; i<n; i++)
		cin>>a[i];
	radixSort(a,n);
	cout<<"\nSorted list is : ";
	for(int i=0; i<n; i++)
		cout<<a[i]<<" ";
	return 0;
}
