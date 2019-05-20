#include<iostream>
using namespace std;

struct node
{
    int index;
    int cost;
    int prev;
    int totalcost;
    struct node *next;
};

typedef struct node * LPTR;

void addend(LPTR &L, int x)
{
    LPTR T, temp;

    temp=new node;
    temp->index=x;
    temp->next=NULL;

    T=L;


    if(L==NULL)
        L=temp;

    else
    {
        while(T->next!=NULL)
            T=T->next;
        T->next=temp;
    }
}

void print(LPTR &L)
{
    LPTR T;
     T=L;
    while(T!=NULL)
    {
        cout<<T->index<<"<-";
        T=T->next;
    }
}

void insert(int G[7][7], int cost[7][7], int x, int y, int w)
{
    G[x][y]=1;
    cost[x][y]=w;
}

struct info
{
    int dist;
    int prev;
};

LPTR yy[3];
int e=0;

void shortestpath(int G[7][7], int cost[7][7], int curr, int end, info xxx[7], int visited[7])
{
    int i, j;

    if(curr!=end)
    {
        for(i=0;i<7;i++)
        {
            if(G[curr][i]==1&&visited[i]!=1)
            {
                if(xxx[i].dist>cost[curr][i])
                {
                    xxx[i].dist=cost[curr][i]+xxx[curr].dist;
                    xxx[i].prev=curr;
                }
            }
        }
        if(G[curr][end]==1)
        {
            yy[e]=new node;
            yy[e]->index=end;
            yy[e]->cost=cost[curr][end];
            yy[e]->prev=curr;
            LPTR temp=yy[e];

            int t=curr;
            while(t!=-1)
            {
                temp->next=new node;
                temp=temp->next;
                temp->index=t;
                temp->prev=xxx[t].prev;
                temp->cost=cost[t][xxx[t].prev];

                t=xxx[t].prev;
                temp->next=NULL;
            }
            e++;
        }
        visited[curr]=1;

        int min=99;
        int index;
        int z;
        for(z=0;z<7;z++)
        {
            if(xxx[z].dist<min&&visited[z]!=1)
            {
                min=xxx[z].dist;
                index=z;
            }
        }
        shortestpath(G, cost, index, end, xxx, visited);
    }

    else if(curr==end)
    {
        cout<<endl<<endl;
        int kkk=curr;
        cout<<kkk;
        kkk=xxx[kkk].prev;
        while(kkk!=-1)
        {
            cout<<"<-"<<kkk;
            kkk=xxx[kkk].prev;
        }
    }
}

int main()
{
    int G[7][7], cost[7][7];
    int i, j;
    for(i=0;i<7;i++)
    {
    for(j=0;j<7;j++)
    {
        G[i][j]=0;
    }
    }

    for(i=0;i<7;i++)
    {
    for(j=0;j<7;j++)
    {
        cost[i][j]=0;
    }
    }


    insert(G, cost, 0, 1, 2);
    insert(G, cost, 0, 3, 1);
    insert(G, cost, 1, 3, 3);
    insert(G, cost, 1, 4, 10);
    insert(G, cost, 3, 2, 2);
    insert(G, cost, 3, 5, 8);
    insert(G, cost, 3, 6, 4);
    insert(G, cost, 3, 4, 2);
    insert(G, cost, 2, 5, 5);
    insert(G, cost, 2, 0, 4);
    insert(G, cost, 6, 5, 1);
    insert(G, cost, 4, 6, 6);


    for(i=0;i<7;i++)
    {
    cout<<endl;
    for(j=0;j<7;j++)
        cout<<G[i][j]<<" ";
    }

    info xxx[7];
    for(int y=0;y<7;y++)
    {
        xxx[y].dist=99;
    }

    xxx[0].dist=0;
    xxx[0].prev=-1;

    int visited[7]={0,0,0,0,0,0,0};

    shortestpath(G, cost, 0, 5, xxx, visited);
    /*cout<<endl<<endl;
    print(yy[0]);

    cout<<endl<<endl;
    print(yy[1]);

    cout<<endl<<endl;
    print(yy[2]);*/

    int sum[3];

    for(int i=0;i<3;i++)
    {
        LPTR temp=yy[i];
        while(temp->next!=NULL)
        {
            yy[i]->totalcost=yy[i]->totalcost+temp->cost;
            temp=temp->next;
        }
    }

    for(int z=0;z<2;z++)
    for(i=0;i<2;i++)
    {
        if(yy[i]->totalcost<yy[i+1]->totalcost)
        {
            LPTR temp=yy[i];
            yy[i]=yy[i+1];
            yy[i+1]=temp;
        }
    }

    cout<<endl<<endl<<"SECOND SHORTEST PATH IS : "<<endl;
    print(yy[1]);
}
