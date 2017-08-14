/*
http://practice.geeksforgeeks.org/problems/min-sum-formed-by-digits/0
*/


#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

int findMin(int a,int b){
    return a < b?a:b;
}

int cmpfnc(void const *a, void const *b){
    return (*(int *)a - *(int *)b );
}

int findSum(int *arr, int size){
    
    qsort(arr,size,sizeof(int),cmpfnc);

    int count = 0;

    int i = 0,j = size-1;

    int a=0,b=0;

    while(j>=0){
        //extract numbers
        int temp1 = arr[j]*pow(10,i);
        j--;
        int temp2;
        if(j < 0){
            temp2 = 0;
        }else{
            temp2 = arr[j]*pow(10,i);
        }
        j--;

        // printf("temp1 is %d\n",temp1);    
        // printf("temp2 is %d\n",temp2);

        if(temp1 + a + temp2 + b < temp1 + b + temp2 + a){
            a += temp1;
            b += temp2;
        }else{
            a+= temp2;
            b+= temp1;
        }

        // printf("a is now %d\n",a);
        // printf("b is now %d\n",b);

        // printf("there sum is %d\n",a+b);
        // printf("----------------------\n");

        i++;
    }

    return a + b;
}

int main(){
    int cases;
    scanf("%d",&cases);
    
    int i;
    for(i=0;i<cases;i++){
        int n;
        scanf("%d",&n);
        int arr[n];
        int j;
        for(j=0;j<n;j++){
            scanf("%d",&arr[j]);
        }
        printf("%d\n",findSum(arr, n));
    }
    
    return 0;
}