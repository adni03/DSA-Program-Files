#include <iostream>
using namespace std;

struct dnode {
    int data;
    struct dnode *R=NULL;
    struct dnode *L=NULL;
};

typedef struct dnode *DPTR;

void print(DPTR D){
    if (D){
        cout << int(D->data) << " ";
        print(D->R);
    }
}

void add_end(DPTR &D, int x){
	DPTR T=new(dnode);
	DPTR T2=D;
	T->data=x;
	T->R=NULL;
	if(!D) D=T;
	else{
		while(T2->R)
			T2=T2->R;
		T2->R=T;
		T->L=T2;
	}
}

void input(DPTR &D){
    int n=1;
    cout << "Enter elements (enter -1 to stop): ";
    while(1){
        cin>>n;
        if(n == -1)
            break;
        add_end(D,n);
    }
}

void after(DPTR D, int p, int q){
    if(D->data!=p){
        after(D->R,p,q);
    }
    else{
        if(D->R){
            DPTR D1=new(dnode);
            D1->data=q;
            D->R->L=D1;
            D1->R=D->R;
            D->R=D1;
            D1->L=D;
        }
        else add_end(D,q);
    }
}

void del_frt(DPTR &D){
    D->R->L=NULL;
    D=D->R;
}

void sort(DPTR &D, DPTR S){
    if (D->L!=S && D!=S) {
        while (S->data > D->data)
            S=S->L;
        after(D,S->data,D->data);
        sort(D->R,S);
    }
    while (D->data >= D->R->data){
        del_frt(D);
    }
}

int main()
{
    DPTR D=NULL, S=NULL;
    input(D);
    S=D;
    while(S->R)
        S=S->R;
    sort(D,S);
    print(D);
    return 0;
}
