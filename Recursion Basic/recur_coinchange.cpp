//Coin Change problem

#include<iostream>
using namespace std;

int search(int s);
int calculate(int sum);

int main()
{
	int m=0;
	cout<<"\nEnter amount : ";
	cin>>m;
	cout<<"Total number of notes : "<<calculate(m);
	return 0;
}

int search(int s)
{
	int change[8] = {200,100,50,20,10,5,2,1};
	static int i=0;
	if(s >= change[i])
		return change[i];
	else
	{
		i++;
		search(s);
	}
}

int calculate(int sum)
{
	static int total=0;
	int cnt=0;
	if(sum == 0)
		return total;
	else
	{
		cnt = sum/search(sum);
		sum-=cnt*search(sum);
		total+=cnt;
		calculate(sum);
	}
}
