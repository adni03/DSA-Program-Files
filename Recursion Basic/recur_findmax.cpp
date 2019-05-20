//Find maximum element in an array using recursion

#include<iostream>
using namespace std;

void findmin(int a[], int n, int &m);

int main()
{
	int arr[100], size=0, min=0;
	cout<<"\nEnter size : ";
	cin>>size;
	for(int i=0; i<size; i++)
		cin>>arr[i];
	min=arr[0];
	findmin(arr,size,min);
	cout<<"\nMinimum element is : "<<min;
	return 0;
}

void findmin(int a[], int n, int &m)
{
	if(n == 0)
		cout<<" ";
	else
	{
		n--;
		if(a[n] > m)
		{
			m = a[n];
			findmin(a,n,m);
		}
		else
			findmin(a,n,m);
	}
}
