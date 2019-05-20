//RADIX SORT using LINKED LIST ARRAY

#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *next;
};
struct Stack
{
	struct node *T;
};

typedef struct node* LPTR;

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

int pop(Stack &m)
{
	LPTR TEMP=m.T;
	if(TEMP==NULL)
		return -1;
	else
	{
		int x=TEMP->data;
		m.T=m.T->next;
		delete(TEMP);
		return x;
	}
}

void push(Stack &m, int n)
{
	LPTR TEMP, A=m.T;
	TEMP=new(node);
	TEMP->data = n;
	if(m.T == NULL)
	{
		TEMP->next=NULL;
		m.T=TEMP;
	}
	else
	{
		while(A->next!=NULL)
			A=A->next;
		TEMP->next=NULL;
		A->next=TEMP;
	}
}

void countSort(int a[], int n, int e)
{
	Stack s[10];
	int m, j=0; 
	for(int i=0; i<10; i++) //initializes everything 
		s[i].T=NULL;
	for(int i=0; i<n; i++)
	{
		push(s[(a[i]/e)%10],a[i]); 
	}
	for(int i=0; i<10; i++)
	{
		m=pop(s[i]);
		while(m!=-1)
		{
			a[j++]=m;
			m=pop(s[i]);
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
