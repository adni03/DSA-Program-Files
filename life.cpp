#include <iostream>
using namespace std;

int main() 
{
	int a, i, j, n1, n2, cnt;
	cout<<"Enter number of test cases : ";
	cin>>a;
	do
	{
		cout<<"\nEnter lower limit : ";
		cin>>n1;
		cout<<"\nEnter upper limit : ";
		cin>>n2;
		for(i=n1; i<=n2; i++)
		{
			cnt=0;
			for(j=1; j<=i; j++)
			{
				if(i%j==0)
					cnt++;
			}
			if(cnt==2)
				cout<<i<<" ";
		}
		a--;
	}while(a>0);
	return 0;
}
