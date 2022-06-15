#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
const int V=10;
queue<int> q;
int d[V+5],f[V+5],G[V+5][V+5],flag,vis[V+5];
int find(int o){return f[o]==o?o:f[o]=find(f[o]);}
void unite(int u,int v){f[find(u)]=find(v);}
inline void assemble(int o){
	queue<int> qq;
	qq.push(o);
	while(!qq.empty()){
		int p=qq.front();qq.pop();
		for(int i=0;i<V;i++){
			if(G[p][i]>0&&!vis[i]){unite(i,p);qq.push(i);vis[i]++;}
			if(G[p][i]<0&&!d[find(i)]){d[find(i)]=d[find(o)]+1;q.push(i);}
			if(G[p][i]<0&&d[find(i)]==d[find(o)]){flag=1;
						if(i<p)printf("conflict between %d and %d!\n",i+1,p+1);}
		}
	}
}
int main(){
	freopen("data.txt","r",stdin);
	for(int i=0;i<V;i++)f[i]=i;
	for(int i=0;i<V;i++)
		for(int j=0;j<V;j++)
			scanf("%d",&G[i][j]);
	for(int i=0;i<V;i++)
		if(!d[find(i)]){
			q.push(i);d[i]=1;
			while(!q.empty()){
				int o=q.front();q.pop();assemble(o);
				for(int j=0;j<V;j++){
					if((G[o][j]<0&&d[find(j)]==d[find(o)])||
						(G[o][j]>0&&d[find(j)]&&d[find(j)]!=d[find(o)])){
						flag=1;
						if(o<j)printf("conflict between %d and %d!\n",o+1,j+1);
					}
					/*if(G[o][j]<0&&!d[find(j)]){
						d[find(j)]=d[find(o)]+1;
						q.push(j);
					}*/
				}
			}
		}
	for(int i=0;i<V;i++)printf("%d: d:%d f:%d\n",i+1,d[find(i)],find(i));
	if(!flag)puts("no conflict!");
	return 0;
}