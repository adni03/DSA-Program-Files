#include<iostream.h>
#include<conio.h>
#include<string.h>

/************* FUNCTION PROTOTYPES ***********/

int horicheck();
int verticheck();
int diagocheck();
void display();

/************* MAIN FUNCTION **************/

char x[3][3];
void main()
{
	clrscr();
	int i=0,j=0,p1=0,p2=0,p3=0,p4=0,n=-1;
	char ch,ch1,p;
	char* ch2=" ";
	p=*ch2;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			x[i][j]=p;
		}
	}
	cout<<"\nTHE GAME BEGINS!"<<endl;
	cout<<endl;
	display();
	cout<<"\nWhat do you want to be? (x,o) : ";
	cin>>ch;
	if(ch=='x')
		ch1='o';
	else
		ch1='x';
	while(n!=0 && n!=1)
	{
		clrscr();
		display();
		cout<<"\nPlayer 1, please enter your co-ordinates : ";
		cout<<"\nX co-ordinate : ";
		cin>>p1;
		cout<<"Y co-ordinate : ";
		cin>>p2;
		cout<<endl;
			for(i=0;i<3;i++)
			{
				for(j=0;j<3;j++)
				{
					x[p1][p2]=ch;
				}
			}
		display();
		cout<<horicheck();
		cout<<verticheck();
		cout<<diagocheck();

		if(horicheck()==1 || verticheck()==1 || diagocheck()==1)
		{
			n=1;
			break;
		}
		cout<<"\nPlayer 2, please enter your co-ordinates : ";
		cout<<"\nX co-ordinate : ";
		cin>>p3;
		cout<<"Y co-ordinate : ";
		cin>>p4;
		cout<<endl;
		if(p1==p3 && p2==p4)
		{
			cout<<"\nInvalid input!";
			cout<<"\nPlayer 2, please enter your co-ordinates : ";
			cout<<"\nX co-ordinate : ";
			cin>>p3;
			cout<<"Y co-ordinate : ";
			cin>>p4;
			cout<<endl;
		}
			for(i=0;i<3;i++)
			{
				for(j=0;j<3;j++)
				{
					x[p3][p4]=ch1;
				}
			}
		display();
		if(n!=1)
		{
			if(horicheck()==1 || verticheck()==1 || diagocheck()==1)
				n=0;
		}
		getch();

	}
	if(n==0)
		cout<<"\nPlayer 2 is the winner!";
	else
		cout<<"\nPlayer 1 is the winner!";
	getch();
}
/***************** FUNCTIONS ****************/

void display()
{
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			cout<<"| "<<x[i][j]<<" |";
		}
		cout<<endl;
	}
}
int horicheck()
{
	int i=0,j=0,flag=-1;
	char com[3];
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			com[j]=x[i][j];
		}
		if(strcmpi(com,"xxx")==0 || strcmpi(com,"ooo")==0)
		{
			flag=0;
		}
	}
	if(flag==0)
		return 1;
	else
		return 0;
}
int verticheck()
{
	int i=0,j=0,flag=-1;
	char com[3];
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			com[j]=x[j][i];
		}
		if(strcmpi(com,"xxx")==0 || strcmpi(com,"ooo")==0)
		{
			cout<<"\nVERTICHECK SUCCESSFUL!";
			flag=0;
	}       }
	if(flag==0)
		return 1;
	else
		return 0;

}
int diagocheck()
{
	int i=0,j=0;
	char com[3];
	for(i=0;i<3;i++,j++)
	{
		com[i]=x[i][j];
	}
	if(strcmpi(com,"xxx")==0 || strcmpi(com,"ooo")==0)
	{
		return 1;
	}
	for(i=0;i<3;i++)
	{
		j=2-i;
		com[i]=x[i][j];
	}
	if(strcmpi(com,"xxx")==0 || strcmpi(com,"ooo")==0)
	{
		return 1;
	}
	else
		return 0;
}


