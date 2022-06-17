#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
const int M=21,N=5;
vector<int> link[N+5];
queue<int> q;
int rankof[M+5][N+5],vote[M+5][N+5],in[N+5],invalid[M+5],picked[N+5];
inline void addedge(int u,int v){
	link[u].push_back(v);
	in[v]++;
}
inline bool singlepeak(int x){
	int peak=vote[x][0];
	for(int i=peak+1;i<N;i++)
		if(rankof[x][i]<rankof[x][i-1])return false;
	for(int i=peak-1;i>=0;i--)
		if(rankof[x][i]<rankof[x][i+1])return false;
	return true;
}
int main(){
	freopen("data.txt","r",stdin);
	for(int i=0;i<M;i++)
		for(int j=0;j<N;j++){
			scanf("%d",&vote[i][j]);
			rankof[i][vote[i][j]]=j;
		}
	//get graph
	for(int i=0;i<N-1;i++)
		for(int j=i+1;j<N;j++){
			int big[2];big[0]=big[1]=0;//big[0]:i is bigger
			for(int k=0;k<M;k++)big[rankof[k][i]>rankof[k][j]]++;
			if(big[0]>big[1])addedge(i,j);
				else addedge(j,i);
			}
	//topo sort
	int sorted=0;
	queue<int> res;
	for(int i=0;i<N;i++)
		if(!in[i])q.push(i);
	while(!q.empty()){
		int o=q.front(); q.pop(); res.push(o); sorted++;
		for(auto u:link[o])
			if(!--in[u])q.push(u);
	}
	if(sorted==N){
		printf("no Comdosette paradox!\norder:");
		while(!res.empty()){printf("%d ",res.front());res.pop();}
		return 0;
	}
	//paradox->remove
	printf("Comdosette paradox!\nnow remove:");
	int cinvalid=0;
	for(int i=0;i<M;i++)
		if(!singlepeak(i)){invalid[i]++;printf("#%d ",i);cinvalid++;}
	puts("");
	if(cinvalid==M){puts("no valid vote!");return 0;}
	//median's algorithm
	printf("spec order as:\n");
	for(int i=0;i<N;i++)printf("%d ",i);
	puts("");
	puts("final order:");
	for(int ii=0;ii<N;ii++){
		int tong[N+5],srt[N+5],ite=0;
		for(int i=0;i<N;i++)tong[i]=0;
		for(int j=0;j<M;j++){
			if(invalid[j])continue;
			for(int k=0;k<N;k++)if(!picked[vote[j][k]])
				{tong[vote[j][k]]++;break;}
		}
		for(int i=0;i<N;i++)if(tong[i])srt[++ite]=i;
		int mid=(ite>>1)+1;
		printf("%d ",srt[mid]);
		picked[srt[mid]]++;
	}
	return 0;
}
	