/*
C program to implement hashing using chaining
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct hash *hashTable = NULL;
int eleCount = 0;

struct node{
	int key,age;
	char name[100];
	struct node *next;
};

struct hash{
	int count;
	struct node *head;
};

void printHash(struct hash *hashTable, int n){
	//array of structures since its contiguous.
	//hashTable is a pointer to this contiguous memory so it can access it randomly.
}

struct node *createNode(int key, char *name, int age){
	struct node *newnode;
	newnode = (struct node *)malloc(sizeof(struct node));
	newnode->key = key;
	newnode->age = age;
	strcpy(newnode->name, name);
	newnode->next = NULL;
	return newnode;
}

void insertToHash(int key, char *name, int age){
	int hashIndex = key%eleCount;
	struct node *newnode = createNode(key,name,age);
	if(!hashTable[hashIndex].head){
		hashTable[hashIndex].head = newnode;
		hashTable[hashIndex].count = 1;
		return;
	}
	newnode->next = (hashTable[hashIndex].head);
	hashTable[hashIndex].head = newnode;
	hashTable[hashIndex].count++;
	return;
}

void searchInHash(int key){
	int hashIndex = key%eleCount, flag=0;
	if(!hashTable[hashIndex].head){
		printf("element not found\n");
		return;
	}
	struct node *t = hashTable[hashIndex].head;
	while(t){
		if(t->key==key){
			flag =1;
		  	printf("VoterID  : %d\n", t->key);
            printf("Name     : %s\n", t->name);
            printf("Age      : %d\n", t->age);
            break;
		}
		t=t->next;
	}
	if (!flag)
        printf("Search element unavailable in hash table\n");
    return;
}

int main(){

	int n,ch,key,age;
	char name[100];		
	printf("Enter the number of elements\n");
	scanf("%d", &n);
	eleCount = n;
	/*create hash table with n number of buckets*/
	hashTable = (struct hash *)calloc(n,sizeof(struct hash));
	while(1){
		printf("1. Insertion\n 2.Deletion\n 3.Searching \n 4. Display\n 5. Exit\n");
		printf("Enter your choice\n");
		scanf("%d",&ch);
		switch(ch){
			case 1: printf("Enter the key value:\n");
				scanf("%d", &key);
				getchar();
				printf("Name:\n");
				fgets(name, 100, stdin);
				name[strlen(name) - 1] = '\0';
				printf("AGE\n");
				scanf("%d", &age);
				insertToHash(key,name,age);
				break;
			case 3: 
				printf("Enter the key to search\n");
				scanf("%d",&key);
				searchInHash(key);
				break;
		}
	}
	printHash(hashTable, n);
	return 0;
}