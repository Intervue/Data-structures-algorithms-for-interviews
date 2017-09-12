/*
https://www.hackerrank.com/challenges/pylons
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int minRemovals(int size, int k, int *arr){
    
    int left[size];
    int right[size];
    int i;
    for(i=0;i<size;i++){
        left[i] = 0;
        right[i] = 0;
    }
    
    left[k-1] = 1;
    i = k-1;
    while(i+k+k-1<size){
        i = i+k+k-1;
        left[i] = 1;
    }
    i = size-1;
    i = i-k+1;
    right[i] = 1;
    while(i-k-k+1 >= 0){
        i = i-k-k+1;
        right[i] = 1;
    }
    int changesL = 0;
    int changesR = 0;
    
    for(i=0;i<size;i++){
        if(arr[i] == 1 && left[i] == 0){
            changesL++;
        }else if(arr[i] == 0 && left[i] == 1){
            changesL = -1;
            break;
        }
    }
    
    for(i=0;i<size;i++){
        if(arr[i] == 1 && right[i] == 0){
            changesR++;
        }else if(arr[i] == 0 && right[i] == 1){
            changesR = -1;
            break;
        }
    }
    
    printf("changes R is %d\n", changesR);
    printf("changes L is %d\n", changesL);

    if(changesR !=-1 && changesL != -1){
        if(changesR > changesL){
            return changesL;
        }
        return changesR;
    }
    return -1;
    
}

int main() {
    int num, k;
    scanf("%d %d",&num, &k);
    int arr[num];
    int j;
    for(j=0; j<num; j++){
        scanf("%d",&arr[j]);
    }
    
    printf("%d\n",minRemovals(num,k, arr));
  
    return 0;
}
