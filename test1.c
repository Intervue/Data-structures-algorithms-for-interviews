#include <stdio.h>
#include <stdlib.h>

int main(){
  int cases;
  int i;
  scanf("%d",&cases);
  for(i=0;i<cases;i++){
    int n,k;
    int arr[1001] = {0};
    scanf("%d %d",&n, &k);
    int j;
    int val;

    for(j=0;j<k;j++){
        scanf("%d",&val);
        arr[val-1]++;
    }
    
    int m;
    printf("%d ", arr[0]);
    for(m=1;m<n;m++){
      arr[m] = arr[m] + arr[m-1];
      printf("%d ", arr[m]);
    }
    printf("\n");

  }
  return 0;
}

