/*
http://practice.geeksforgeeks.org/problems/tricky-subset-problem/0
*/

#include <stdio.h>

int canBeFormed(int *arr, int *ref, int n, int s, int x){
    ref[0] = s;
    int temp = s;
    int i;
    for(i=1;i<n;i++){
        ref[i] = temp + arr[i];
        temp = temp + ref[i];
        if(x < ref[i]){
            break;
        }
    }
    int j,k;
    for(j=i-1;j>=0;j--){
        if(x-ref[j] > 0){
            x = x - ref[j];
        }
        for(k = 0; k<=j;k++){
            if(x == ref[k]){
                return 1;
                break;
            }
        }

    }
    return 0;

}


int main(){
    int cases;
    scanf("%d",&cases);
    while(cases>0){
        int s,n,x;
        scanf("%d %d %d",&s,&n,&x);
        int arr[100000], ref[100000];

        if(canBeFormed(arr,ref,s,n,x)){
            printf("yes\n");
        }else{
            printf("no\n");
        }
        cases--;
    }
}