//Structure problem - 1

#include<iostream>
using namespace std;

union u1
{
	int b1;
	char b2;
	float b3;
};
union u2
{
	float f;
	int g;
	union u2 *h;
};
struct s1
{
	int a;
	union u1 b;
	struct s2 *c;
};
struct s2
{
	struct s2 *d;
	union u2 *e;
};


int main()
{
	struct s1 A;
	A.c = new(s2);
	A.c->e = new(u2);
	A.c->e->g=7;
	cout<<A.c->e->g;
	return 0;
}
