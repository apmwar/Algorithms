#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

struct data{
	int a;
	char b[11];
	struct data *NEXT;
};

struct count_data{
	int count;
	struct data *first;
	struct data *last;
};

void count(vector<data> &arr, int n){

	//initialise values
	struct count_data *count = (count_data *) calloc (100, sizeof(count_data));
	struct data *elem;
	//count the value of count;
	for(int i = 0; i < n; i++){
		int temp = arr[i].a;
		count[temp].count++;
		if(count[temp].first == NULL){
			count[temp].first = &(arr[i]);
			count[temp].last = &(arr[i]);
		}
		else{
			count[temp].last -> NEXT = &(arr[i]);
			count[temp].last = &(arr[i]);
		}
	}
	for(int i = 0; i < 100; i++){
		elem = count[i].first;
        while (elem) {
            printf("%s ", elem->b);
            elem = elem->NEXT;
	  }
	}
}


int main() {

    //accept n
    int n;
    scanf("%d", &n);
    
    //accept the structure of elements
    vector<data> arr(n);
    for(int i = 0 ;i < n; i++)
	scanf("%d %s", &arr[i].a, &arr[i].b);
	
    //modify first half strings
    for(int i = 0; i < n/2; i++)
	strcpy(arr[i].b, "-");
	
    //function call
    count(arr, n);
    
    return 0;
}
