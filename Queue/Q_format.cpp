//PRINT IN THE GIVEN FORMAT

#include<iostream>
#include<math.h>
using namespace std;

struct queue
{
	int size, f, r;
	int n[10]; 
	char ch[10];
};

char words[10][7]={"Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};

void dec_base(int num, char b)
{
	int power=0, i=0, base=0;
	switch(b)
	{
		case 'b': base=2; break;
		case 'o': base=8; break;
		case 'x': base=16; break;
	}
	char c[10];
	for(;pow(base,power)<num; power++);
	for(i=power-1; i>-1; i--)
	{
		if(num%base > 9)
		{
			switch(num%base)
			{
				case 10: c[i]='A'; break;
				case 11: c[i]='B'; break;
				case 12: c[i]='C'; break;
				case 13: c[i]='D'; break;
				case 14: c[i]='E'; break;
				case 15: c[i]='F'; break;
			}
		}
		else
			c[i] = num%base + '0';
		num/=base;
	}
	for(i=0; i<power; i++)
		cout<<c[i];	
	cout<<endl;
}

void enq(queue &q, int x)
{
	if(q.f == (q.r +1)%q.size)
		cout<<"\nFull!";
	else
	{
		if(q.f == -1)
			q.f=0;
		q.r=(q.r + 1)%q.size;
		q.n[q.r] = x;
	}		
}

int delqi(queue &q)
{
	int t;
	if(q.f == -1)
		cout<<"\nEmpty!";
	else
	{
		t=q.n[q.f];
		if(q.f == q.r)
		{
			q.f=-1;
			q.r=-1;
		}
		else
			q.f=(q.f+1)%q.size;
		return t;
	}
}

void enq(queue &q, char x)
{
	if(q.f == (q.r +1)%q.size)
		cout<<"\nFull!";
	else
	{
		if(q.f == -1)
			q.f=0;
		q.r=(q.r + 1)%q.size;
		q.ch[q.r] = x;
	}		
}

void print_dat(queue &q)
{
	cout<<"\nResult is : "<<endl;
	while(q.f != -1)
	{
		char c;
		int a;
		c=q.ch[q.f];
		a=q.n[q.f];
		if(c != 'p')
		{
			cout<<a<<" "<<c<<":\t";
			dec_base(a,c);
			delqi(q);
		}
		else
		{
			int arr[10], i=0;
			while(q.n[q.f] > 0)
			{
				arr[i]=q.n[q.f]%10;
				q.n[q.f]/=10;
				i++;
			}
			i--;
			cout<<a<<" "<<c<<":\t";
			while(i>=0)
			{
				cout<<words[arr[i]]<<" ";
				i--;
			}
			cout<<endl;
			delqi(q);
		}
	}
}

int main()
{
	struct queue qu;
	qu.f=qu.r=-1;
	cout<<"\nEnter number of blocks : ";
	cin>>qu.size;
	cout<<"\nEnter number and character : "<<endl;
	for(int i=0; i<qu.size; i++)
	{
		int a; char c;
		cin>>a>>c;
		enq(qu,a);
		qu.r--;
		qu.f--;
		enq(qu,c);
	}
	print_dat(qu);
	return 0;
}
