#include<iostream>
using namespace std;

struct studentnode
{
    struct studentnode * next;
    int index;
    struct coursenode * ptr[3];
};
typedef struct studentnode * SPTR;
typedef struct coursenode * CPTR;
struct coursenode
{
    int coursenum;
};



void addendS(SPTR &L, int x)
{
    SPTR T, temp;
    int i;
    temp=new studentnode;
    temp->next=NULL;
    temp->index=x;
    for(i=0;i<3;i++)
        temp->ptr[i]=NULL;

    if(L==NULL)
        L=temp;
    else
    {
        T=L;
        while(T->next!=NULL)
            T=T->next;

        T->next=temp;
    }
}

void addend(CPTR &L, int x)
{
    L->coursenum=x;
}

int main()
{
    SPTR S, T;
    S=NULL;
    int i;int choice;

    for(i=1;i<5;i++)
        addendS(S, i);

    T=S;

    T->ptr[0]=new coursenode;
    T->ptr[0]->coursenum=1;
    T->ptr[1]=new coursenode;
    T->ptr[1]->coursenum=2;

    T=T->next;

    T->ptr[0]=new coursenode;
    T->ptr[0]->coursenum=1;

    T=T->next;

    T->ptr[0]=new coursenode;
    T->ptr[0]->coursenum=1;
    T->ptr[1]=new coursenode;
    T->ptr[1]->coursenum=2;
    T->ptr[2]=new coursenode;
    T->ptr[2]->coursenum=3;

    T=T->next;

    T->ptr[0]=new coursenode;
    T->ptr[0]->coursenum=1;

    int course, student;
    do
    {

        cout<<"enter 1 for seeing students, 2 for courses : ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            {
                cout<<endl<<"Enter course : ";
                cin>>course;
                for(T=S;T!=NULL;T=T->next)
                for(i=0;i<3;i++)
                {
                    if(T->ptr[i]==NULL)
                        break;
                    else if(T->ptr[i]->coursenum==course)
                    {
                        cout<<"s"<<T->index<<" ";
                        break;
                    }
                }
                break;
            }
        case 2:
            {
                T=S;
                cout<<"enter student : ";
                cin>>student;
                while(T->index!=student)
                    T=T->next;
                for(i=0;i<3;i++)
                {
                    if(T->ptr[i]!=NULL)
                        cout<<"c"<<T->ptr[i]->coursenum<<" ";
                }
            }
            break;
        }

    }while(choice!=-1);

    return 0;
}
