#include<cstdio>
#include<cstring>
using namespace std;
const int V=100;
int paradox,fri[V+5],G[V+5][V+5];
int main(){
	freopen("data.txt","r",stdin);
	for(int i=0;i<V;i++)
		for(int j=0;j<V;j++)
			scanf("%d",&G[i][j]);
	for(int i=0;i<V;i++)
		for(int j=0;j<V;j++)
			if(G[i][j])fri[i]++;
	for(int i=0;i<V;i++){
		int nei=0; double sum=0;
		for(int j=0;j<V;j++)
			if(G[i][j]){nei++;sum+=fri[j];}			
		if(sum/nei>(double)fri[i])paradox++;
	}
	printf("%ratio:%.5lf",(double)paradox/V);
	return 0;
}