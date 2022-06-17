#include<cstdio>
#include<cstring>
using namespace std;
int g[505][505],n;
double nei[505][505],clu[505];
int main(){
	freopen("data.txt","r",stdin);
	printf("num of verticals:\n");
	scanf("%d",&n);
	printf("adjacency matrix:\n");
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)scanf("%d",&g[i][j]);
	for(int i=1;i<=n;i++){
		int cnt=0,s=0;
		for(int j=1;j<=n;j++)if(i!=j&&g[i][j]){
			cnt++;
			for(int k=j+1;k<=n;k++)if(g[j][k]&&g[i][k]&&k!=i)s++;
		}
		if(!cnt||cnt==1)continue;
		clu[i]=((double)s/(double)(cnt*(cnt-1)/2));
	}
	for(int i=1;i<n;i++)
		for(int j=i+1;j<=n;j++){
			int cnt=0,s=0;
			for(int k=1;k<=n;k++)if(k!=i&&k!=j){
				if(g[j][k]||g[i][k])cnt++;
				if(g[j][k]&&g[i][k])s++;
			}
			nei[i][j]=nei[j][i]=(double)s/(double)cnt;
		}
	printf("clustering coefficient:\n");
	for(int i=1;i<=n;i++)printf("%d : %.5lf\n",i,clu[i]);
	printf("neighborhood overlap:\n");
	printf("\t");for(int i=1;i<=n;i++)printf("%d\t",i);puts("");
	for(int i=1;i<=n;i++){
		printf("%d\t",i);
		for(int j=1;j<=n;j++)printf("%.5lf\t",nei[i][j]);
		puts("");
	}
	return 0;
}
