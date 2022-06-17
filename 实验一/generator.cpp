#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cstring>
using namespace std;
const int V=10;
const double CRD=0.4;
int G[V+5][V+5];
int main(){
	freopen("data.txt","w",stdout);
	srand(time(0));
	printf("%d\n",V);
	for(int i=0;i<V;i++)
		for(int j=0;j<i;j++)
			if(rand()%100<CRD*100)G[i][j]=G[j][i]=1;
	for(int i=0;i<V;i++){
		for(int j=0;j<V;j++)printf("%d ",G[i][j]);
		puts("");
	}
	return 0;
}