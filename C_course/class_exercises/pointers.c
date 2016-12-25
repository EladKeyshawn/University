#include <stdlib.h>
#include <stdio.h>

void sort_int(int* arr, int size);



int main () {

int arr[] = {7,1,1,3,12,4};

sort_int(arr,5);

for(int i=0; i<5; i++) {
printf("%d\n", arr[i] );
}


}

void sort_int(int* arr, int size) {
for(int i=0; i < size; i++ ) {
   for(int j=i; j<size; j++) {
	if(arr[j] < arr[i]) {
	int temp = arr[j];
	arr[j] = arr[i];
	arr[i] = temp;
	}	
    }
}
}
