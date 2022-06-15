#include<cstdio>
#include<cstring>
#include<queue>
#include<iostream>
using namespace std;
const int V=100;
int aced[V+5],G[V+5][V+5],tt,n;
double p,a;
int main(){
	freopen("data.txt","r",stdin);
	cin>>p>>n;
	a=1/p-1;printf("p: %.3lf\n",p);
	printf("init count %d:\n",n);
	while(n--){
		int tmp;
		scanf("%d",&tmp);
		aced[tmp]++;
		printf("%d ",tmp);
	}
	puts("");
	for(int i=0;i<V;i++)
		for(int j=0;j<V;j++)
			scanf("%d",&G[i][j]);
	int changeflag=1;
	while(changeflag--){
		queue<int> okq;
		for(int i=0;i<V;i++)
			if(!aced[i]){
				int ok[2];ok[0]=ok[1]=0;
				for(int j=0;j<V;j++)if(G[i][j])ok[aced[j]]++;
				if(a*ok[1]>=(double)ok[0])okq.push(i);
			}
		printf("round #%d, %d nodes added:\n",++tt,okq.size());
		if(okq.size())changeflag++;
		else puts("algorithm end.");
		while(!okq.empty()){
			int o=okq.front(); okq.pop();
			printf("%d ",o); aced[o]++;
		}
		puts("");
	}
	return 0;
}