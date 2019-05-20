//ODD TO ONE SIDE AND EVEN TO THE OTHER

#include<iostream>
using namespace std;

void swap(int &c, int &b);
void sort(int arr[]);

int main()
{
	int a[8], i=0;
	cout<<"\nEnter 8 random numbers : ";
	for(i=0; i<8; i++)
	{
		cin>>a[i];
	}
	sort(a);
	return 0;
}

void sort(int arr[])
{
	int l=0, h=7;
	while(l<h)
	{
		if(arr[l]%2 != 0 && arr[h]%2 !=1)
			swap(arr[l],arr[h]);
		else if(arr[h]%2 == 1)
			h--;
		else if(arr[l]%2 == 0)
			l++;
		
	}
	for(int i=0; i<8; i++)
		cout<<arr[i]<<" ";
}
void swap(int &c, int &b)
{
	int temp;
	temp=c;
	c=b;
	b=temp;
}
