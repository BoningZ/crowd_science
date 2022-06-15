#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cstring>
using namespace std;
const int V=10;
const double CRD=0.3,pos_div_neg=4;
int G[V+5][V+5];
int main(){
	freopen("data.txt","w",stdout);
	srand(time(0));
	for(int i=0;i<V;i++)
		for(int j=0;j<i;j++)
			if(rand()%100<CRD*100)G[i][j]=G[j][i]=(rand()%((int)pos_div_neg+1)<pos_div_neg)?1:-1;
	for(int i=0;i<V;i++){
		for(int j=0;j<V;j++)printf("%d ",G[i][j]);
		puts("");
	}
	return 0;
}