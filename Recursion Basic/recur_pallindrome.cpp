//Checks if array is pallindrome through recursion

#include<iostream>
using namespace std;

int palchk(int a[], int n, int &low);

int main()
{
	int b[100], i=0, j=0, l=-1;
	cout<<"\nEnter number of elements : ";
	cin>>j;
	for(i=0; i<j; i++)
	{
		cin>>b[i];
	}
	if(palchk(b,j,l) == 0)
		cout<<"\nNot Pallindrome";
	else
		cout<<"\nPallindrome";
	return 0;
}

int palchk(int a[], int n, int &low)
{
	if(low > n)
		return 1;
	else
	{
		low++;
		n--;
		if(a[low] != a[n])
			return 0;
		else
			palchk(a,n,low);
	}
}
