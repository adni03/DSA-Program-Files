//Structure pointer problem 2

#include<iostream>
using namespace std;

union u1
{
	struct s2 *b1;
	float b2;
	int b3;
};
union u4
{
	int j1;
	char j2;
};
struct s1
{
	int a;
	union u1 b;
	int c;
	int d;
};
struct s2
{
	struct s2 *e;
	struct s3 *f;
};
struct s3
{
	int g;
	struct s4 *h;
	struct s3 *i;
};
struct s5
{
	int m;
	char n;
};
struct s4
{
	union u4 j;
	struct s5 k;
	struct s4 *l;
};


int main()
{
	struct s1 A;
	A.b.b1 = new(s2);
	A.b.b1->f = new(s3);
	A.b.b1->f->h = new(s4);
	A.b.b1->f->h->k.m = 9;
	cout<<	A.b.b1->f->h->k.m;
	return 0;
}
