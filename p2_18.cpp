#include<iostream>
using namespace std;

struct student
{
	char name[10], add[10];
	int rollno, m1, m2, m3;
}s[10];

int main()
{
	cout<<"\nEnter details for 10 students : ";
	for(int i=0; i<10; i++)
	{
		cout<<"\nEnter name : ";
		cin>>s[i].name;
		cout<<"\nEnter address : ";
		cin>>s[i].add;
		cout<<"\nEnter roll number : ";
		cin>>s[i].rollno;
		cout<<"\nEnter marks in the 3 subjects : ";
		cin>>s[i].m1>>s[i].m2>>s[i].m3;
	}
	for(int i=0; i<10; i++)
	{
		cout<<endl;
		cout<<"\nName : "<<s[i].name;
		cout<<"\nAddress : "<<s[i].add;
		cout<<"\nRoll number : "<<s[i].rollno;
		cout<<"\nChuck marks";
	}
}
