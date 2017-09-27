#include <stdio.h>
int digsum(int n){
	if(n>0)
		return (n % 10) + digsum(n/10);
	else
		return 0;
}

int main(){
	int t;
	scanf("%d",&t);
	while(t>0){
		int n;
		scanf("%d",&n);
		printf("%d\n",digsum(n));
		t--;
	}
	return 0;
}
