//MINIMUM SPANNING TREE

#include<iostream>
using namespace std;

struct info{ //Krushkals Algorithm
	int from;
	int to; 
	int wt;
};

const int n=5;

int allVisited(int a[]){
	for(int i=0; i<n; i++){
		if(!a[i]) return 0;
	}
	return 1;
}

void reset(int a[], int n){
	for(int i=0; i<n; i++){
		a[i]=i;
	}
}

void swap(struct info &A, struct info &B){
	struct info temp;
	temp=A;
	A=B;
	B=temp;
}

void insert(struct info H2[], int &cnt, struct info k){
	static int i=0;
	H2[i].wt=k.wt;
	H2[i].from=k.from;
	H2[i].to=k.to;
	int j=i;
	struct info temp;
	++i;
	while(j>0){
		if(H2[(j-1)/2].wt > H2[j].wt){
			temp=H2[(j-1)/2];
			H2[(j-1)/2]=H2[j];
			H2[j]=temp;
		}
		j=(j-1)/2;
	}
	cnt=i;
}

/*struct info remove(struct info H[], int cnt){
	int i=0;
	struct info x=H[0];
	H[0]=H[--cnt];
	while(i<cnt){
		if(H[2*i+1].wt<H[2*i+2].wt && 2*i+1<cnt){
			if(H[i].wt>=H[2*i+1].wt) swap(H[i],H[2*i+1]);
			i=2*i+1;
		}
		else if(H[2*i+1].wt>H[2*i+2].wt && 2*i+2<cnt){
			if(H[i].wt>=H[2*i+2].wt) swap(H[i],H[2*i+2]);
			i=2*i+2;
		}
		else break;
	}
	return x;
}*/

void Prims(int G[n][n], int start, int &sum){
	static int visited[n]={0};
	if(allVisited(visited)) return ;
	visited[start]=1;
	int min=100, from=0, to=0, flag=0;
	for(int i=0; i<n; i++){
		if(visited[i]){
			for(int j=0; j<n; j++){
				if(G[i][j] && !visited[j]){
					if(G[i][j] < min){
						min=G[i][j];
						from=i;
						to=j;
						flag=1;
					}
				}
			}
		}
	}
	if(flag){
		cout<<from+1<<"->"<<to+1<<"\n";
		sum+=G[from][to];
		Prims(G,to,sum);
	}
}

/*void Prims_Heaps(int G[n][n], struct info H[], int &cnt, int start, int &sum){
	static int visited[n]={0};
	int flag=0;
	if(allVisited(visited)) return ;
	visited[start]=1;
	for(int i=0; i<n; i++){
		if(visited[i]){
			for(int j=0; j<n; j++){
				if(G[i][j] && !visited[j]){
					struct info temp;
					temp.from=i;
					temp.to=j;
					temp.wt=G[i][j];
					insert(H,cnt,temp);
					flag=1;
				}
			}
		}
	}
	if(flag){
		struct info temp=remove(H,cnt);
		cout<<temp.from+1<<"->"<<temp.to+1<<"\n";
		sum+=temp.wt;
		Prims_Heaps(G,H,cnt,temp.to,sum);
	}
}*/

void store_info(struct info I[], int G[n][n], int &cnt){
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(G[i][j]){
				I[cnt].from=i;
				I[cnt].to=j;
				I[cnt++].wt=G[i][j];
			}
		}
	}
	//sorting according to weights of the edges
	int min, pos=0;
	struct info temp;
	for(int i=0; i<cnt; i++){
		min=I[i].wt;
		for(int j=i; j<cnt; j++){
			if(I[j].wt <= min){
				min=I[j].wt;
				pos=j;
			}
		}
		temp=I[i];
		I[i]=I[pos];
		I[pos]=temp;
	}
}

int find(int G[], int key){
	return G[key];
}

void Union(int G[], int key, int root){
	G[key]=G[root];
}

void Krushkals(struct info I[], int cnt, int G[], int G1[n][n]){
	int sum=0, edge=0;
	store_info(I,G1,cnt);
	for(int i=0; i<cnt; i++){
		if(edge==n-1) break;
		int a=find(G,I[i].from);
		int b=find(G,I[i].to);
		if(a!=b){
			Union(G,b,a);
			++edge;
			sum+=I[i].wt;
			cout<<I[i].from+1<<"->"<<I[i].to+1<<"\n";
		}
	}
	cout<<"Sum of edges is : "<<sum;
}

int main()
{
	//int G1[7][7]={{0,2,0,1,0,0,0},{0,0,0,3,10,0,0},{4,0,0,0,0,5,0},{0,0,2,0,2,8,4},{0,0,0,0,0,0,6},{0,0,0,0,0,0,0},{0,0,0,0,0,1,0}};
	int G1[5][5] = {{0, 2, 0, 6, 0}, 
                    {2, 0, 3, 8, 5}, 
                    {0, 3, 0, 0, 7}, 
                    {6, 8, 0, 0, 9}, 
                    {0, 5, 7, 9, 0}}; 
	int G[15];
	reset(G,15);
	struct info I[15], H[15];
	int sum=0, cnt=0;
	cout<<"--------------PRIM'S ALGORITHM---------------\n";
	cout<<"Minimum spanning tree is : \n";
	Prims(G1,0,sum);
	cout<<"Sum of edges is : "<<sum<<"\n"; sum=0;
	cout<<"---------PRIM'S ALGORITHM USING HEAPS--------\n";
	cout<<"Minimum spanning tree is : \n";
	//Prims_Heaps(G1,H,cnt,0,sum);
	cout<<"Sum of edges is : "<<sum<<"\n";
	sum=cnt=0;
	cout<<"--------------KRUSHKAL'S ALGORITHM-----------\n";
	Krushkals(I,cnt,G,G1);
	return 0;
}
