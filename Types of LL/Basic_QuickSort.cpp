//QUICK SORT

#include<iostream>
using namespace std;

void swap(int &a, int &b)
{
	int temp=0;
	temp=a;
	a=b;
	b=temp;
}

int part(int arr[], int low, int high)
{
	int pivot=arr[high];
	int i=low-1;
	for(int j=low; j<high; j++)
	{
		if(arr[j]<=pivot)
		{
			++i;
			swap(arr[i],arr[j]);
		}
	}
	swap(arr[i+1],arr[high]);
	return (i+1);
}

void quicksort(int arr[], int low, int high)
{
	int pi;
	if(low<high)
	{
		pi=part(arr,low,high);
		quicksort(arr,low,pi-1);
		quicksort(arr,pi+1,high);
	}
}

int main()
{
	int a[6] = {16,17,4,33,2,55};
	cout<<"Unsorted array : ";
	for(int i=0; i<6; i++){
		cout<<a[i]<<" ";
	}
	quicksort(a,0,5);
	cout<<"\nSorted array is : ";
	for(int i=0; i<6; i++)
		cout<<a[i]<<" ";
	return 0;
}
