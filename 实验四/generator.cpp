#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cstring>
using namespace std;
const int V=100;
const double CRD=0.3,INIT=0.2;
int G[V+5][V+5],inits,init[V+5];
int main(){
	freopen("data.txt","w",stdout);
	srand(time(0));rand();
	printf("%.3lf\n",((double)(rand()%10000))/10000);
	for(int i=0;i<V;i++)
		for(int j=0;j<i;j++)
			if(rand()%100<CRD*100)G[i][j]=G[j][i]=1;
	for(int i=0;i<V;i++)if(rand()%100<INIT*100){inits++;init[i]++;}
	printf("%d\n",inits);
	for(int i=0;i<V;i++)if(init[i])printf("%d ",i);
	puts("");
	for(int i=0;i<V;i++){
		for(int j=0;j<V;j++)printf("%d ",G[i][j]);
		puts("");
	}
	return 0;
}