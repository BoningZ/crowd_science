#include<cstdio>
#include<cstring>
using namespace std;
const int maxv=1000;
int G[maxv+5][maxv+5],v;
int main(){
	scanf("%d",&v);
	freopen("data.txt","r",stdin);
	freopen("data.csv","w",stdout);
	puts("source,target,type,weight");
	for(int i=0;i<v;i++)
		for(int j=0;j<v;j++){
			int t;
			scanf("%d",&t);
			if(t!=0&&i<j)printf("%d,%d,undirected,%d\n",i+1,j+1,t);
		}
	return 0;
}