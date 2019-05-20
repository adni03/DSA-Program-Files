#include<iostream>
using namespace std;

void bignsmall(int a[]);
void nbignsmall(int a[], int p);

int n;
int main() 
{
	int a[50], i, p;
	cout<<"\nEnter number of elements : ";
	cin>>n;
	cout<<"\nEnter elements : "; 
	for(i=0; i<n; ++i)
	{
		cin>>a[i];
	}
	bignsmall(a);
	cout<<"\nEnter p: ";
	cin>>p;
	nbignsmall(a,p);
	return 0;
}
void bignsmall(int a[])
{
	int big, small;
	a[0]=big;
	a[0]=small;
	for(int i=0; i<n; i++)
	{
		if(a[i]>big)
			big=a[i];
		else if(a[i]<small)
			small=a[i];
	}
	cout<<"\nBiggest is : "<<big;
	cout<<"\nSmallest is : "<<small;
}
void nbignsmall(int a[], int p)
{
	int i, small, pos, temp;
	for(i=0; i<n; i++)
	{
		small=a[i];
		pos=i;
		for(int j=i; j<n; ++j)
		{
			if(a[j]<small)
			{
				small=a[j];
				pos=j;
			}	
		}
		temp=a[i];
		a[i]=small;
		a[pos]=temp;
	}
	cout<<"\nThe pth biggest number is : "<<a[n-p];
	cout<<"\nThe pth smallest number is : "<<a[p-1];
}
