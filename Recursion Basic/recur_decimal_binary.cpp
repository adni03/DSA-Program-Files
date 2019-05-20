//Decimal to Binary through recursion

#include<iostream>
using namespace std;

void dec_bin(int n);

int main()
{
	int num;
	cout<<"\nEnter number : ";
	cin>>num;
	dec_bin(num);
	return 0;
}

void dec_bin(int n)
{
	static int number[100], cnt=0;
	int rem=0;
	if(n <= 0)
	{
		for(int i=cnt-1; i>=0; i--)
			cout<<number[i];
	}
	else
	{
		rem = n%2;
		number[cnt] = rem;
		cnt++;
		n=n/2;
		dec_bin(n);
	}
}
