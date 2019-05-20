//Structure pointer problem 3

#include<iostream>
using namespace std;

union u1
{
	int b1;
	char b2;
};
union u3
{
	int i;
	float j;
};
struct s2
{
	int h;
	char g;
};
union u2
{
	struct s2 f;
	union u3 e;
};
struct s1
{
	int a;
	union u1 b;
	union u2 *c;
	union u1 *d;
	float e;
};

int main()
{
	struct s1 A;
	A.c= new(u2);
	A.c->e.i = 7;
	cout<<A.c->e.i;
	return 0;
}
