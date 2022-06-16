#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<algorithm>
using namespace std;
const int M=3,N=3;
int a[N+5];
int fact(int n){return n==1?1:n*fact(n-1);}
int main(){
	freopen("data.txt","w",stdout);
	srand(time(0));
	int maxs=fact(N);
	for(int i=0;i<M;i++){
		int s=rand()%maxs;
		for(int j=0;j<N;j++)a[j]=j;
		while(s--)next_permutation(a,a+N);
		for(int j=0;j<N;j++)printf("%d ",a[j]);
		puts("");
	}
	return 0;
}