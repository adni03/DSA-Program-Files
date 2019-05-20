//2

#include<iostream>
#include<string.h>
using namespace std;

union u{
	int num;
	char ch;
	char str[10];
	char c;
	struct node *dptr=NULL;
};

struct node{
	union u data;
	int tag;
	struct node *next;
};

typedef struct node *MLPTR;
MLPTR A=NULL, G=NULL, C=NULL;
union u a[8], c[6], g[3];
int tag_a[8]={0,0,3,0,1,3,2,0};
int tag_c[6]={0,1,0,2,3,0};
int tag_g[3]={0,1,2};

void create(int n1, int n2, int n3){
	MLPTR T=G;
	for(int i=0; i<n3; i++){
		T=new(node);
		T->tag=tag_g[i];
		switch(T->tag){
			case 0: T->data.num=g[i].num; break;
			case 1: T->data.ch=g[i].ch; break;
			case 2: strcpy(T->data.str,g[i].str); break;
			case 3: T->data.dptr=NULL; T->data.c='.'; break;
		}
		T->next=G;
		G=T;
	}
	T=C;
	for(int i=0; i<n2; i++){
		T=new(node);
		T->tag=tag_c[i];
		switch(T->tag){
			case 0: T->data.num=c[i].num; break;
			case 1: T->data.ch=c[i].ch; break;
			case 2: strcpy(T->data.str,c[i].str); break;
			case 3: if(c[i].c=='a'){
						T->data.dptr=A;
						T->data.c='a';
					}
					else if(c[i].c=='g'){
						T->data.dptr=G;
						T->data.c='g';	
					}
					else T->data.dptr=NULL;
					break;
		}
		T->next=C;
		C=T;
	}
	T=A;
	for(int i=0; i<n1; i++){
		T=new(node);
		T->tag=tag_a[i];
		switch(T->tag){
			case 0: T->data.num=a[i].num; break;
			case 1: T->data.ch=a[i].ch; break;
			case 2: strcpy(T->data.str,a[i].str); break;
			case 3: if(c[i].c=='c'){
						T->data.dptr=C;
						T->data.c='c';
					}
					else if(c[i].c=='g'){
						T->data.dptr=G;
						T->data.c='g';	
					}
					else T->data.dptr=NULL;
					break;
		}
		T->next=A;
		A=T;
	}
}

void print(char ch){
	if(ch=='g'){
		static MLPTR T=G;
		if(T){
			switch(T->tag){
				case 0: cout<<T->data.num<<" "; break;
				case 1: cout<<T->data.ch<<" "; break;
				case 2: cout<<T->data.str<<" "; break;
			}
			T=T->next;
			print(ch);
		}
	}
	else if(ch=='c'){
		static MLPTR T=C;
		if(T){
			switch(T->tag){
				case 0: cout<<T->data.num<<" "; break;
				case 1: cout<<T->data.ch<<" "; break;
				case 2: cout<<T->data.str<<" "; break;
				case 3: print(T->data.c); break;
			}
			T=T->next;
			print(ch);
		}
	}
	else if(ch=='a'){
		static MLPTR T=A;
		if(T){
			switch(T->tag){
				case 0: cout<<T->data.num<<" "; break;
				case 1: cout<<T->data.ch<<" "; break;
				case 2: cout<<T->data.str<<" "; break;
				case 3: print(T->data.c); break;
			}
			T=T->next;
			print(ch);
		}
	}
}

int main()
{
	char str[10];
	int t=0, n=0;
	cout<<"Enter for G : "<<endl;
	for(int i=0; i<3; i++){
		cout<<tag_g[i]<<" ";
		switch(tag_g[i]){
			case 0: cin>>g[i].num; break;
			case 1: cin>>g[i].ch; break;
			case 2: cin>>str;
					strcpy(g[i].str,str); break;
			case 3: g[i].c='.';
		}
	}
	cout<<"\nEnter for C : "<<endl;
	for(int i=0; i<6; i++){
		cout<<tag_c[i]<<" ";
		switch(tag_c[i]){
			case 0: cin>>c[i].num; break;
			case 1: cin>>c[i].ch; break;
			case 2: cin>>str;
					strcpy(c[i].str,str); break;
			case 3: cin>>c[i].c; break;
		}
	}
	cout<<"\nEnter for A : "<<endl;
	for(int i=0; i<8; i++){
		cout<<tag_a[i]<<" ";
		switch(tag_a[i]){
			case 0: cin>>a[i].num; break;
			case 1: cin>>a[i].ch; break;
			case 2: cin>>str;
					strcpy(a[i].str,str); break;
			case 3: cin>>a[i].c; break;
		}
	}
	create(8,6,3);
	cout<<"\nThe string is : ";
	print('a');
	return 0;
}
