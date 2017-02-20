/*
MERGE SORT

Space complexity: stack O(logn) + space for merge procedure O(n)
Therefore total = O(n)

Time complexity: time taken to merge O(n) + time taken to sort by masters theorem O(nlogn)
Therefore: O(nlogn) 

*/
#include <stdio.h>
#include <math.h>

void merge(int arr[],int p, int q, int r){
  long unsigned int f = INFINITY;
  int n1= q-p+1;
  int n2 = r-q;
  int left[n1+1], right[n2+1];
  int i,j,k;
  
  for(i=0;i<n1;i++){
    left[i]=arr[p+i];
    printf("%d ", left[i]);
  }
  
  for(j=0;j<n2;j++){
    right[j]=arr[q+j+1];
    printf("%d ", right[j]);
  } 
  
  left[n1] = right[n2] = f;
  i=j=0;
  for(k=p;k<(r+1);k++){
    if(left[i] < right[j]){
      arr[k] = left[i];
      i++;
    }else{
      arr[k] = right[j];
      j++;
    }
  }
  
  for(int z=0; z<(r+1);z++){
    printf("%d ", arr[z]);
  }
  
}

void merge_sort(int arr[], int p, int r){
  
  int q;
  if(p<r){
    q = (p+r)/2;
    merge_sort(arr,p,q);
    merge_sort(arr,q+1,r);
    merge(arr,p,q,r);
  }
}

int main(){
  
  int arr[] = {9,6,5,0,8,2};
  int length = sizeof(arr)/sizeof(arr[0]);
  merge_sort(arr,0,length-1);

}