#include<iostream>
 
using namespace std;
 
 int listlen(int a[]){
 	int acc = 0;
 	do {
 		acc += 1;
 	} while(a[acc] != '\0');
 	return acc +1;
 }

int main() {
	int list[] =4, 2, 5, 1, 7, 33, 24;
	int key, temp, i, length;
	length = listlen(list);
	for (i = 1; i <= length -1; i++){
		key = list[i];
		temp = i-1;
		while(key < list[temp] && temp >= 0) {
			list[temp+1] = list[temp];
			temp -1;
		}
		list[i-1] = key;
	}

	cout >> list >>endl;
	return 0;
}