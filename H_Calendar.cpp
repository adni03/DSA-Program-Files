// Prints a horizonatal calendar

#include<iostream>
#include<stdlib.h>
using namespace std;

//global variables
	int month[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	int chk[11] = {3,3,6,1,4,6,2,5,0,3,5};
	int calendar[6][7];

//Function declarations 
	void display(int a);
	void clear();

//main function
int main()
{
	int ch=0;
	cout<<"Please select month : "<<endl;
	cout<<"1. January\n2. Febuary\n3. March\n4. April\n5. May\n6. June\n7. July\n8. August\n9. September\n10. October\n11. November\n12. December";
	cout<<"\nEnter your choice : ";
	cin>>ch;
	clear();
	display(ch);
	return 0;
}

void clear()
{
	int i=0, j=0;
	for(i=0; i<6; i++)
	{
		for(j=0; j<7; j++)
		{
			calendar[i][j] = (char)32;
		}
	}
}

void display(int a)
{
	int i=1, j=0, k, temp=1;
	for(i=0; i<6; i++)
	{
		if(i == 0 && a!=1)
		{
			for(j=chk[a-2], k=temp; j<7; j++, k++)
			{
				calendar[i][j] = k;
			}
			temp=k;
		}
		else
		{
			for(j=0, k=temp; j<7 && k<=month[a-1]; j++, k++)
			{
				calendar[i][j] = k;	
			}
			temp=k;	
		}	
	}
	cout<<endl<<endl;
	cout<<"MO TU WE TH FR SA SU"<<endl;
	for(i=0; i<6; i++)
	{
		for(j=0; j<7; j++)
		{
			if(calendar[i][j] == 32)
				cout<<(char)calendar[i][j]<<"  ";
			else if((int)calendar[i][j] < 10)
				cout<<"0"<<calendar[i][j]<<" ";
			else
				cout<<calendar[i][j]<<" ";
		}
		cout<<endl;
	}
	
}


