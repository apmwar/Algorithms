//https://www.hackerrank.com/challenges/bigger-is-greater/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	int t;
	cin >> t;
	while(t--){
		string word;
		cin >> word;
		int size = word.size();
		if(size == 1)
			cout << "no answer\n";
		else{
			int i;
			for(i = size - 1; i > 0; i--){
				if(word[i] > word[i - 1])
					break;
			}
			if(i == 0)
				cout << "no answer\n";
			if(i == 1){

			}
			else{
				char temp;
				temp = word[i];
				word[i] = word[i - 1];
				word[i - 1] = temp;
				cout << word << endl;
			}
		}
	}
    return 0;
}

