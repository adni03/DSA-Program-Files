//Spiral Matrix

#include<iostream>
using namespace std;

void spiral(int a[][100], int m, int n);
void insert(int a[][100], int m, int n);

int main()
{
	int mat[100][100], row, col;
	cout<<"\nEnter rows and columns : ";
	cin>>row>>col;
	insert(mat,row,col);
	spiral(mat,row,col);
	return 0;
}

void insert(int a[][100], int m, int n)
{
	cout<<"\nEnter elements : ";
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			cin>>a[i][j];
		}
	}
}

void spiral(int a[][100], int m, int n)
{
	int i, l1=0, l2=0, h1=m-1, h2=n-1;
	cout<<"\nSpiral is : "<<endl;
	while(l1<h1 || l2<h2)
	{
		for(i=l2; i<h2; i++)
			cout<<a[l1][i]<<" ";
		for(i=l1; i<h1; i++)
			cout<<a[i][h2]<<" ";
		for(i=h2; i>l2; i--)
			cout<<a[h1][i]<<" ";
		for(i=h1; i>l1; i--)
			cout<<a[i][l2]<<" ";
		l1++;
		l2++;
		h1--;
		h2--;
	}	
}
