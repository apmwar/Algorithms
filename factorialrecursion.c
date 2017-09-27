#include<stdio.h>
long long int fact(int n){
	if(n>1)
		return n*fact(n-1);
	else
		return 1;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t>0){
		t--;
		int n;
		scanf("%d",&n);
		printf("%lld",fact(n));
	}
	return 0;
}
