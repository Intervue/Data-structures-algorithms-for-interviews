/*
http://practice.geeksforgeeks.org/problems/buildings-receiving-sunlight/0
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int totalBuildings(int *arr, int size){
    int max = arr[0];
    int i;

    int count = 1;

    for(i=1;i<size;i++){
        if(max <= arr[i]){
            count++;
            max = arr[i];
        }
    }

    return count;

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
        printf("%d\n",totalBuildings(arr, n));
    }
    return 0;
}