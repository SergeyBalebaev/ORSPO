#pragma once
#include <stddef.h>

typedef struct StdString StdString;

struct StdString {
	char* data;
	size_t size;
	size_t capacity;

	void (*append)(StdString*, const char*);
	void (*pushback)(StdString*, char);
	void (*clear)(StdString*);
	size_t (*length)(StdString);
	void (*print)(StdString);
	void (*destroy)(StdString*);
};

StdString init(const char* str);

void append(StdString* src, const char* new_str);
void push_back(StdString* src, char c);
void clear(StdString* src);
size_t length(StdString str);
void print(StdString str);
void destroy(StdString* str);
