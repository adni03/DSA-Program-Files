//RADIX SORT

#include<iostream>
using namespace std;

struct queue
{
	int f,r,size;
	int ele[20];
};

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

void enq(queue &q, int x)
{
	if(q.f == (q.r +1)%q.size)
		cout<<"\nFull!";
	else
	{
		if(q.f == -1)
			q.f=0;
		q.r=(q.r + 1)%q.size;
		q.ele[q.r] = x;
	}		
}

int delq(queue &q)
{
	int t;
	if(q.f == -1)
		return -1;
	else
	{
		t=q.ele[q.f];
		if(q.f == q.r)
		{
			q.f=-1;
			q.r=-1;
		}
		else
			q.f=(q.f+1)%q.size;
		return t;
	}
}

void countSort(int a[], int n, int e)
{
	queue q[10];
	int m, j=0; 
	for(int i=0; i<10; i++) //initializes everything to -1
	{
		q[i].f=q[i].r=-1;
		q[i].size=20;
	}
	for(int i=0; i<n; i++)
	{
		enq(q[(a[i]/e)%10],a[i]); 
	}
	for(int i=0; i<10; i++)
	{
		m=delq(q[i]);
		while(m!=-1)
		{
			a[j++]=m;
			m=delq(q[i]);
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
	cout<<"Enter number of elements : ";
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
