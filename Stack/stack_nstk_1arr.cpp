//N STACK 1 ARRAY

#include<iostream>
using namespace std;

struct stack 
{
	int size, elements;
	int *top;
};

int s=0;

void push(stack m[], int x, int a[], int j)
{
	if(m[j].top == m[j-1].top)
	{
		++m[j].top;
		*m[j].top = x;	
	}
	else if(m[j].top < &a[s])
	{
		++m[j].top;
		*m[j].top = x;
	}
	else
		cout<<"\nOverflow";
}

int pop(stack m[], int a[], int j)
{
	if(m[j].top == m[j-1].top)
		cout<<"\nEmpty";
	else 
		return (*m[j].top--);
}

void enter_vals(stack m[], int l, int a[])
{
	int i, j;
	for(i=0; i<l; i++)
	{
		cout<<"\nEnter size of stack "<<i+1<<" : ";
		cin>>m[i].size;
		s+=m[i].size;
		cout<<"\nEnter elements for stack "<<i+1<<" : ";
		for(j=0; j<m[i].size; j++)
		{
			cin>>m[i].elements;
			push(m,m[i].elements,a,i);
		}
		m[i+1].top = m[i].top;
	}
}

void print_vals(stack m[], int l, int a[])
{
	int i, j;
	for(i=0; i<l; i++)
	{
		cout<<"\nElements of stack "<<i+1<<" are : "<<endl;
		for(j=0; j<m[i].size; j++)
		{
			cout<<pop(m,a,i)<<" ";
		}
	}
}

int main()
{
	struct stack s[50];
	int array[52], n;
	cout<<"\nEnter number of stacks : ";
	cin>>n;
	s[0].top = &array[0];
	enter_vals(s,n,array);
	print_vals(s,n,array);
	return 0;
}

