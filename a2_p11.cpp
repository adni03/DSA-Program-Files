#include<iostream>
using namespace std;

void input();
void display();
void sum();
void rowsum();
void columnsum();
void transpose();

int m,n, a[50][50];

int main()
{
	cout<<"\nEnter dimensions of the array : ";
	cin>>m>>n;
	input();
	display();
	sum();
	rowsum();
	columnsum();
	transpose();
	return 0;
}
void input()
{
	cout<<"\nEnter the elements : "<<endl;
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			cin>>a[i][j];
		}
	}
}
void display()
{
	cout<<"\nThe elements are : "<<endl;
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
}
void sum()
{
	int sum=0;
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			sum+=a[i][j];
		}
	}
	cout<<"\nThe sum is : "<<sum;
}
void rowsum()
{
	int sum=0;
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			sum+=a[i][j];
		}
		cout<<"\nSum of row number "<<(i+1)<<" is : "<<sum;
		sum=0;
	}
}
void columnsum()
{
	int sum=0;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			sum+=a[j][i];
		}
		cout<<"\nThe sum of column number "<<(i+1)<<" is : "<<sum;
		sum=0;
	}
}
void transpose()
{
	int b[50][50];
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			b[i][j]=a[j][i];
		}
	}
	cout<<"\nThe transpose is : "<<endl;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			cout<<b[i][j]<<" ";
		}
		cout<<endl;
	}
}
