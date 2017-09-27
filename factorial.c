#include<stdio.h>
#include<math.h>
long long int somename(long int n,int i){
	if(n >= pow(5,i)){
		return n/(pow(5,i)) + somename(n,i+1);
	}
	else
		return 0;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t > 0){
		long int n;
		scanf("%ld",&n);
		printf("%lld\n",somename(n,1));
		t--;
	}
	return 0;
}
