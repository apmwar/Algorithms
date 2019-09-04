//https://www.hackerearth.com/practice/algorithms/sorting/merge-sort/practice-problems/algorithm/shil-and-lucky-string-1/description/
#include <iostream>
#include <string>
using namespace std;
int main()
{
  	int n;
  	cin >> n;
	string s;
  	cin >> s;
  	int type1 = 0, type2 = 0, type3 = 0;
  	int hlen = s.length()/2;
  	for(int i = 0; i < hlen; i++){
    	if(s[i] < s[i+hlen])
          type1 += 2;
      	else if(s[i] == s[i+hlen])
          type2 += 2;
      	else
          type3 += 2;
    }
  	//cout << type1 << type2 << type3;
  	if((type1 == 0 && type2 == 0) || (type2 == 0 && type3 == 0) || (type1 == 0 && type3 == 0)){
    	cout << "0";
    }
  	else if(type1 == 0){
    	cout << (type2 < type3) ? type2: type3;
    }
  	else if(type2 == 0){
    	cout << (type1 < type3) ? type1: type3;
    }
  	else if(type3 == 0){
    	cout << (type2 < type1) ? type2: type1;
    }
  	cout << "\n" << type1 << " " << type2 << " " << type3;
	return 0;
}
