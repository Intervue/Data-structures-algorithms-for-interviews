/*
http://practice.geeksforgeeks.org/problems/factorials-of-large-numbers/0
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

int multiply(int num, int *arr, int size){
    int i;
    int carry = 0;
    for(i=0;i<size;i++){
        int prod = num*arr[i] + carry;
        arr[i] = prod%10;
        carry = prod/10;
    }

    while(carry){
        arr[size] = carry%10;
        size++;
        carry = carry/10;
    }

    return size;

}

void fact(int n){

    int arr[3000];
    int size = 1;
    arr[0] = 1;

    int i;
    for(i=2; i<=n;i++){
        size = multiply(i,arr,size);
    }

    for(i=size-1;i>=0;i--){
        printf("%d", arr[i]);
    }
    printf("\n");
}

int main(){
    int cases,i;
    scanf("%d",&cases);
    for(i=0;i<cases;i++){
        int n;
        scanf("%d",&n);
        fact(n);
    }
    return 0;
}