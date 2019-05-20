//TARGET PROBLEM

#include<iostream>
using namespace std;

struct lnode
{
	int data;
	struct lnode *next[10];
	int num;
};

typedef struct lnode* LPTR;

void print(LPTR L, int x)
{
	LPTR TEMP=L, Q;
	while(TEMP!=NULL)
	{
		if(TEMP->num > 1)
		{
			Q=TEMP;
			break;
		}
		else
			TEMP=TEMP->next[x-1];
	}
	TEMP=L;
	for(int i=0; i<x; i++)
	{
		while(TEMP!=NULL)
		{
			cout<<TEMP->data<<" ";
			TEMP=TEMP->next[i];
		}
		TEMP=Q;
	}
}

void insert_f(LPTR &L, int n, int x)
{
	LPTR T;
	T=new(lnode);
	T->data = n;
	T->num = x;
	T->next[x-1]=L;
	L=T;
}

void insert_end(LPTR &L, int n, int x)
{
	LPTR T, TEMP=L;
	if(L == NULL)
	{
		insert_f(L,n,x);
	}
	else
	{
		while(TEMP->next[x-1] != NULL)
			TEMP=TEMP->next[x-1];
		T=new(lnode);
		T->data = n;
		T->num=x;
		T->next[x-1] = NULL;
		TEMP->next[x-1]=T;
	}
}

void insert(LPTR &L)
{
	LPTR T, TEMP=L, Q;
	int a,n,flag=0,cnt=0;
	cout<<"\nEnter data, hit -1 to stop : ";
	cin>>a;
	while(a!=-1)
	{
		cout<<"\nEnter number of routes : ";
		cin>>n;
		if(L == NULL)
		{
			insert_f(L,a,n);
		}
		else 
		{
			if(n==1)
				insert_end(L,a,n);
			else
			{
				TEMP=L;
				while(TEMP->next[0] !=NULL)
					TEMP=TEMP->next[0];
				Q=TEMP;
				flag=1;
				cout<<"\nNew routes : ";
				for(int i=0; i<n; i++)
				{
					TEMP=Q;
					TEMP->next[i]=NULL;
					while(a!=-1)
					{
						while(TEMP->next[i] != NULL)
							TEMP=TEMP->next[i];
						T=new(lnode);
						T->data=a;
						T->num=n;
						T->next[i]= NULL;
						TEMP->next[i]=T;
						cout<<"\nEnter element : ";
						cin>>a;
						if(cnt==0)
						{
							Q=Q->next[0];
							cnt++;
						}
					}
					if(i!=n-1)
					{
						cout<<"\nFor next route : ";
						cout<<"\nEnter element : ";
						cin>>a;
					}
				}
			}
		}
		if(flag==1)
			break;
		cout<<"\nEnter element : ";
		cin>>a;
	}
}

void cal_r(LPTR L, int n)
{
	LPTR TEMP=L, Q=NULL;
	int arr[20], i=0, flag=0, cnt=0, j=0, tcnt=0, tj=0;
	while(TEMP!=NULL)
	{
		if(TEMP->num == 1)
			TEMP=TEMP->next[0];
		else
		{
			Q=TEMP;
			break;
		}
	}
	TEMP=L;
	while(TEMP!=Q)
	{
		arr[j++]=TEMP->data;
		cnt++;
		TEMP=TEMP->next[0];
	}
	tj=j; tcnt=cnt;
	for(i=0; i<Q->num; i++)
	{
		j=tj; cnt=tcnt;
		TEMP=Q;
		while(TEMP!=NULL)
		{
			if(TEMP->data!=n)
			{
				arr[j]=TEMP->data;
				cnt++; j++;
				TEMP=TEMP->next[i];
			}
			else
			{
				flag=1;
				arr[j]=TEMP->data; cnt++;
				break;
			}
		}
		if(flag==1)
			break;
		TEMP=L;
	}
	cout<<endl;
	for(i=0; i<cnt; i++)
	{
		cout<<arr[i]<<" ";
	}
}

int main()
{
	LPTR L1=NULL;
	int n;
	insert(L1);
	cout<<"\nEnter target element : ";
	cin>>n;
	cout<<"\nRoute is : ";
	cal_r(L1,n);
	return 0;
}
