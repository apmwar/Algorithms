#include <iostream>
#include <vector>
#include <algorithm>

struct Segment{
	int a;
	int b;
};

using std::vector;

vector<int> min_segments(vector <Segment> &s, int n){
	vector<int> point;
	//sorting
	for(int i = 0; i < n - 1; i++){
		int pos = i;
		for(int j = i + 1; j < n; j++){
			if(s[j].b < s[pos].b)
				pos = j;
		}
		if(pos != i){
			int temp = s[pos].b;
			s[pos].b = s[i].b;
			s[i].b = temp;
			temp = s[pos].a;
			s[pos].a = s[i].a;
			s[i].a = temp;
		}
	}
	//display sort
	//for(int i = 0; i < n; i++)
	//	std::cout << s[i].a <<" " <<s[i].b << std::endl;
		
	//calculating
	int k = 1, pos = 0;
	while(k < n){
		if(s[pos].b >= s[k].a && s[pos].b <= s[k].b){
			k++;
		}
		else{
			point.push_back(s[pos].b);
			//std::cout << "POINT PUSHED: " << s[pos].b << std::endl;
			pos = k;
			k++;
		}
	}
	if(pos < n)
		point.push_back(s[pos].b);
	return point;
}

int main(){
	int n; //no of points
	std::cin >> n;
	vector <Segment> s(n);
	//accepting
	for(int i = 0; i < n; i++)
		std::cin >> s[i].a >> s[i].b;
	//call function
	vector <int> point = min_segments(s, n);
	std::cout << point.size() <<"\n";
	for(int i = 0; i < point.size(); i++)
		std::cout << point[i] << " ";
	return 0;
}
