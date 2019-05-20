//prints array in reverse

#include<iostream>
using namespace std;

void reverse(int a[], int n);

int main()
{
	int arr[100], size, i;
	cout<<"\nEnter size : ";
	cin>>size;
	cout<<"\nEnter elements : ";
	for(i=0; i<size; i++)
		cin>>arr[i];
	reverse(arr,size);
	return 0;
}

void reverse(int a[], int n)
{
	if(n == 0)
		cout<<a[n];
	else
	{
		if(n != 1)
			cout<<a[n-1]<<" ";
		reverse(a,n-1);
	}
}
