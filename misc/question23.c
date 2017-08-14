
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

int isValid(int rows, int columns, int i, int j){
    if(i < rows && i >= 0 && j < columns && j>= 0){
        return 1;
    }
    return 0;
}

void updateColors(int rows, int columns, int arr[rows][columns], int i, int j, int color, int initial){
    // printf("initial is %d\n",initial);
    int k,l;
    if(isValid(rows,columns,i,j) && arr[i][j] == initial){
        arr[i][j] = color;
    }
    // printf("entering the for loop.......................................\n");
    for(k = i-1; k <= i+1; k++){
        for(l = j-1; l <= j+1; l++){
            if(l == j && k == i){
                continue;
            }
            if((k == i-1 && l == j-1) || (k == i-1 && l == j+1) || (k == i+1 && l == j-1) || (k == i+1 && l == j+1)){
                continue;
            }

            // printf("value of arr[%d][%d] is %d\n",k,l,arr[k][l]);
            // printf("value of initial is %d\n",initial);
            if(isValid(rows,columns,k,l) && arr[k][l] == initial){
                // printf("upating........\n");
                arr[k][l] = color;
                // printf("entering the for loop.......................................\n");
                updateColors(rows,columns, arr,k,l,color,initial);
            }
        }
    }
    // printf("printing the array here...............................\n");
    // int p,q;
    // for(p=0;p<rows;p++){
    //     for(q=0;q<columns;q++){
    //         printf("%d ",arr[p][q]);
    //     }
    // }
    // printf("\n");
}

int main(){
    int cases;
    scanf("%d",&cases);
    int i;
    for(i=0;i<cases;i++){
        int n,m;
        scanf("%d %d",&n, &m);
        int p,q;
        int arr[n][m];
        for(p=0;p<n;p++){
            for(q=0;q<m;q++){
                scanf("%d",&arr[p][q]);
            }
        }
        int x,y,k;
        scanf("%d %d %d",&x,&y,&k);
        updateColors(n,m,arr,x,y,k, arr[x][y]);
        for(p=0;p<n;p++){
            for(q=0;q<m;q++){
                printf("%d ",arr[p][q]);
            }
        }
        printf("\n");
    }
    return 0;
}