#include "stdstring.h"
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

// Мб где то надо добавить проверки на нуллы хуюллы и прочее гавно

StdString init(const char* str) {
	if (str == NULL) str = "";
	StdString string;
	string.size = (size_t)strlen(str);
	string.capacity = (size_t)(2 * string.size + 1);
	string.data = malloc(string.capacity);
	strcpy(string.data, str);
	string.append = append;
	string.pushback = push_back;
	string.clear = clear;
	string.length = length;
	string.print = print;
	string.destroy = destroy;
	
	return string;
}

static int check_capacity(StdString src, const char* new_str) {
	return src.capacity >= src.size + strlen(new_str)+ 1;
}

void append(StdString* src, const char* new_str) {
	if(check_capacity(*src, new_str) == 0) {
		size_t new_size = src->size + strlen(new_str) + 1;
		while(src->capacity < new_size) src->capacity = src->capacity * 2;
		char* reallocated = realloc(src->data, src->capacity);
		if(reallocated == NULL) return;
		src->data = reallocated; 
		}
		for(int i = 0; i < strlen(new_str); i++) {
			src->data[src->size + i] = new_str[i];
		}
		src->data[src->size + strlen(new_str)] = '\0';
		src->size = strlen(src->data);
}

void push_back(StdString* src, char c) {
	if(src->capacity < src->size + 2) {
		while(src->capacity < src->size + 2) src->capacity *= 2;
		char* reallocated = realloc(src->data, src->capacity);
		if(reallocated == NULL) return;
		src->data = reallocated;
	}
	src->data[src->size] = c;
	src->data[src->size + 1] = '\0';
	src->size++;
}

void clear(StdString* src) {
	src->data[0] = '\0';
	src->size = 0;
}

size_t length(StdString str) {
	return str.size;
}

void print(StdString str) {
	printf("%s\n", str.data);
}

void destroy(StdString* str) {
	free(str->data);
	str->size = 0;
	str->capacity = 0;
}
