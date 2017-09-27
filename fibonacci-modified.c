#include <stdio.h>
#include <math.h>
//f(x+1) = f(x) - f(x-1)  ---> c = b - a

#define M 1000000007

long int newfib(long int a, long int b, long int n,long int i){
	if(i < n){
		return newfib(b,(b-a > 0)?(b-a)%M:M+(b-a), n, i+1);
	}
	else{
		return b;
	}
}

int main(){
	int t;
	scanf("%d",&t);
	while(t>0){
		long int a,b,n,c;
		scanf("%ld %ld %ld",&a,&b,&n); //nth element
		printf("%ld\n",newfib(a,b,n-2,0));
 		t--;
	}
	return 0;
}
