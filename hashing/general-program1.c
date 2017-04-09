/*
C program to implement linear probing
*/
#include <stdio.h>
#include <stdlib.h>
#define LIMIT 30
enum record_status {EMPTY,DELETED,OCCUPIED};

struct Employee{
	int employee_id;
	int employee_age;
	char employee_name[30];
};

struct Record{
	struct Employee info;
	enum record_status status;
};

int hash_function(int key){
	return key%LIMIT;
}

int search_records(int key, struct Record hash_table[]){
	int count, temp, position;
	temp = hash_function(key);
	position = temp;
	for(count = 1; count != LIMIT-1; count++){
		if(hash_table[position].status == EMPTY){
			return -1;
		}
		if(hash_table[position].info.employee_id == key){
			return position;
		}
		position = (temp + count)%LIMIT;
	}
	return -1;
}

void delete_records(int key, struct Record hash_table[]){
	int position = search_records(key, hash_table);
	if(position == -1){
		printf("Key not found\n");
	}else{
		hash_table[position].status = DELETED;
	}
};

void display_records(struct Record hash_table[]){
	int count;
	printf("Hash table\n");
	for(count = 0; count<LIMIT; count++){
		printf("[%d]:\t", count);
		if(hash_table[count].status == OCCUPIED){
			printf("Occupied - ID: %d Name: %s Age: %d",hash_table[count].info.employee_id, hash_table[count].info.employee_name, hash_table[count].info.employee_age);
		}else if(hash_table[count].status == DELETED){
			printf("Position is deleted\n");
		}else{
			printf("EMPTY\n");
		}

	}
}

void insert_records(struct Employee emprec, struct Record hash_table[]){
	int count, position, temp;
	int key = emprec.employee_id;
	temp = hash_function(key);
	position = temp;
	for(count = 1; count != LIMIT-1; count++){
		if(hash_table[position].status == EMPTY || hash_table[position].status == DELETED){
			hash_table[position].info = emprec;
			hash_table[position].status = OCCUPIED;
			printf("record inserted into hash table\n");
			return;
		}
		if(hash_table[position].info.employee_id == key){
			printf("Duplicate record cannot be inserted\n");
			return;
		}
		position = (temp + count)%LIMIT;
	}
	printf("hash table limited exceeded\n");
}

int main(){
	int count, key, option;
	struct Record hash_table[LIMIT];
	struct Employee emprec;
	for(count = 0;count<LIMIT;count++){
		hash_table[count].status = EMPTY;
	}
	while(1){
		printf("1. Insert a Record\n");
		printf("2. Delete a Record\n");
		printf("3. Search a Record\n");
		printf("4. Display all Record\n");
		printf("5. Exit\n");
		printf("Enter your option\n");
		scanf("%d",&option);
		switch(option){
			case 1: printf("Enter employee ID\n");
				scanf("%d",&emprec.employee_id);
				printf("Enter employee name\n");
				scanf("%s",emprec.employee_name);
				printf("Enter employee age\n");
				scanf("%d",&emprec.employee_age);
				insert_records(emprec,hash_table);
				break;

			case 2: printf("Enter the key to delete\n");
				scanf("%d", &key);
				delete_records(key, hash_table);
				break;

			case 3: printf("Enter the key to search\n");
				scanf("%d",&key);
				count = search_records(key, hash_table);
				if(count == -1){
					printf("Record not found\n");
				}else{
					printf("Record found at Index %d ", count);
				}
				break;

			case 4: display_records(hash_table);
				break;
			case 5: exit(1);
		}
	}
	return 0;
}