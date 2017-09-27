#include <iostream>

long int F(int n){
  	if(n <= 1)
      return n;
  	else
      return n * F(n - 1);
}

int main(){
	int n;
  	std::cin >> n;
  	std::cout << F(n) << std::endl;
}
