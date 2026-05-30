#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define CAPACITY 5 // Size of the Hash Table

unsigned long hash(char* str) {
    unsigned long i = 0;
    for (int j=0; str[j]; j++)
        i += str[j];
    return i % CAPACITY;
}

typedef struct Node {
	char* key;
	char* value;
	struct Node* next;
} Node;

typedef struct HashTable {
	Node** table;
	long size; 
} HashTable;

HashTable* createTable(long siz) {
	HashTable* table = malloc(sizeof(HashTable));
	table->size = siz;
	table->table = calloc(table->size, sizeof(Node*));
	
	return table;
}

Node* createNode(char* key, char* val) {
	Node* node = malloc(sizeof(Node));
	node->key = key;
	node->value = val;
	node->next = NULL;
	return node;
}

void insert(HashTable* table, char* key, char* value) {
	unsigned long index = hash(key);
	if(table->table[index] == NULL) {
			table->table[index] = createNode(key, value);
			return;
	}
	else {
		Node* current = table->table[index];
		while(current->next != NULL) {
			current = current->next;
		}
		current->next = createNode(key, value);
	}
}

void delete(HashTable* table, char* key) {
	unsigned long index = hash(key);
	Node* current = table->table[index];
	if(current == NULL) {
		printf("Нет пар с таким ключом");
		return;
	}
	
	if(strcmp(current->key, key) == 0) {
		Node* new_head = current->next;
		table->table[index] = new_head;
		free(current);
		return;
	}
	
	while(current->next != NULL) {
		if(strcmp(current->next->key, key) == 0) {
			Node* new_next = current->next->next;
			free(current->next);
			current->next = new_next;
			return;
		}
		current = current->next;
	}
	
	printf("Ничего не нашлось");
	
}

Node* find(HashTable* table, char* key) {
	unsigned long index = hash(key);
	Node* current = table->table[index];
	while(current != NULL) {
		if(strcmp(current->key, key) == 0) return current;
		current = current->next;
	}
	return NULL;
}

void DisplayTable(HashTable* table) {
	printf("HashTable:\n\n");
	Node* circuit;
	for(int i = 0; i < table->size; i++) {
		printf("[%d]: ", i);
		circuit = table->table[i];
		while(circuit != NULL) {
			printf("{%s : %s} -> ", circuit->key, circuit->value);
			circuit = circuit->next;
		}
		printf("NULL\n");
	}
	
}

int main() {
	HashTable* table = createTable(CAPACITY);
	DisplayTable(table);
	insert(table,"Nikita", "Grechka");
	DisplayTable(table);
	insert(table, "Zheka", "BigBuli");
	DisplayTable(table);
	insert(table, "hekaZ", "govno");
	DisplayTable(table);
	delete(table, "hekaZ");
	delete(table, "Nikita");
	DisplayTable(table);
	
	for(int i = 0; i < table->size; i++) {
		Node* current = table->table[i];
		while(current != NULL) {
			Node* next = current->next;
			free(current);
			current = next;
		} 
	}
	
	free(table->table);
	free(table);
	return 0;
}
