#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cstring>
#include<algorithm>
using namespace std;
const int V=100,clu_siz=20;
const double CRD=0.1;
int G[V+5][V+5];
int main(){
	freopen("../data.txt","w",stdout);
	srand(time(0));
	int cur=0;
	while(cur<V){
		int nxt=min(V,cur+(rand()%clu_siz+rand()%clu_siz/2));
		for(int i=cur;i<nxt;i++)
			for(int j=cur;j<i;j++)
				if(rand()%100<(1-CRD)*100)G[i][j]=G[j][i]=1;
		cur=nxt;
	}
	for(int i=0;i<V;i++)
		for(int j=0;j<i;j++)
			if(rand()%100<CRD*100)G[i][j]=G[j][i]=1;
	for(int i=0;i<V;i++){
		for(int j=0;j<V;j++)printf("%d ",G[i][j]);
		puts("");
	}
	return 0;
}