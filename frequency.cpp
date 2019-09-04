#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void mostFreq3(int *a, int n, int b[3]) {
  int i, j, min, temp, c[100], d[100], k = 0, count;
	for(i = 0; i < n - 1; i++){
		min = i;
		for(j = i + 1; j < n; j++){
			if(a[j] < a[min])
				min = j;
		}
		if(min != i){
			temp = a[min];
			a[min] = a[i];
			a[i] = temp;
		}
	}
	for(i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
	for(i = 0; i < n; i += count){
		count = 1;
		for(j = i; a[j] == a[j + 1]; j++){
			count++;
		}
		cout << "occurance of " << a[i] << " is " << count <<endl;
		c[k] = count;
		d[k] = a[i];
		k++;
	}
	for(i = 0; i < k; i++)
		cout << c[i] << " " <<d[i] << endl;
	for(i = 0; i < k - 1; i++){
		min = i;
		for(j = i + 1; j < k; j++){
			if(c[j] < c[min])
				min = j;
		}
		if(min != i){
			temp = c[min];
			c[min] = c[i];
			c[i] = temp;
			temp = d[min];
			d[min] = d[i];
			d[i] = temp;
		}
	}
	for(i = 0; i < k; i++)
		cout << c[i] << " " <<d[i] << endl;
	for(i = 0; i < 3; i++)
		b[i] = d[k - i - 1];
}
int main()
{
	int n = 100;
	int a[100];
	int b[3];
	int i;
	for(i = 0; i < n; i++)
		a[i] = rand() % 10;
	for(i = 0; i < n; i++)
		cout << a[i] << " " ;
	cout << endl << endl;
	mostFreq3(a, n, b);
      for(i=0; i<3; i++)
            cout << b[i] << " ";

	return 0;
}
