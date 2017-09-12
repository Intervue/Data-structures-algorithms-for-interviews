/*
All pair shortest path algorithm (Floyd Warshall)
here we keep updating taking different paths into consideration one after the other
*/

#include <stdio.h>
#include <stdlib.h>

void floydWarshall(int v, int graph[v][v]) {

	int i,j,k;

	int result[v][v];
	
	for(i=0;i<v;i++) {
		for(j=0;j<v;j++) {
			result[i][j] = graph[i][j];
		}
	}

	for(k=0;k<v;k++){
		for(i=0;i<v;i++) {
			for(j=0;j<v;j++){
				if(result[i][k] + result[k][j] < result[i][j]){
					result[i][j] = result[i][k] + result[k][j];
				}	
			}
		}	
	}

	//print sol
	for(i=0;i<v;i++) {
		for(j=0;j<v;j++) {
			printf("%d ", result[i][j]);
		}
	}
	printf("\n");
}

int main(){
	int cases;
	int i;
	scanf("%d", &cases);

	for(i=0;i<cases;i++) {
		int v;
		scanf("%d",&v);
		int graph[v][v];
		int k,l;
		for(k=0;k<v;k++){
			for(l=0;l<v;l++){
				scanf("%d", &graph[k][l]);
			}
		}
		floydWarshall(v,graph);
	}

  	
	return 0;
}