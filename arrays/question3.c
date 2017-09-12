/*
MERGE SORT

Space complexity: stack O(logn) + space for merge procedure O(n)
Therefore total = O(n)

Time complexity: time taken to merge O(n) + time taken to sort by masters theorem O(nlogn)
Therefore: O(nlogn) 

*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


void merge(int *arr, int start, int mid, int end) {

    int len1 = mid - start + 2;
    int len2 = end - mid + 1;

    int left[len1], right[len2];

    int i;
    for(i=0; i<len1-1; i++) {
        left[i] = arr[start + i];
    }

    for(i=0; i<len2-1; i++) {
        right[i] = arr[mid + i + 1];
    }
    
    left[len1-1] = INT_MAX;
    right[len2-1] = INT_MAX;

    int k;
    int j;
    i=0,j=0;
    for(k=start; k<=end; k++) {
        if(left[i] < right[j]) {
            arr[k] = left[i];
            i++;
        }else{
            arr[k] = right[j];
            j++;
        }
    }

}

void mergeSort(int *arr, int start, int end) {
    int mid;
    if(start < end) {
        mid = (start + end)/2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);

        merge(arr, start, mid, end);
    }
}

void display(int *arr, int size) {
    int i;
    for(i=0;i<size;i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}   

int main() {
    int arr[] = {9,6,5,0,8,2};
    int size = sizeof(arr)/sizeof(arr[0]);

    mergeSort(arr,0,size-1);

    display(arr, size);
    return 0;
}