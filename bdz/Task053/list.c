#include <stdio.h>
#include <stdlib.h>
#include "list.h"

// Создание нового узла
Node* create_node(int value) {
    Node* new_node = malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = NULL;
    return new_node;
}

// Добавление в конец
void push_back(Node** head, int value) {
    if(*head == NULL) {
        *head = create_node(value);
        return;
    }
    Node* current = *head;
    while(current->next != NULL) {
        current = current->next;
    }
    current->next = create_node(value);
}

// Вставка по индексу (0 — в начало)
void insert_at(Node** head, int value, int index) {
    if(index == 0) {
        Node* insert = create_node(value);
        insert->next = *head;
        *head = insert;
        return;
    }
    Node* current = *head;
    for(int i = 0;i < index-1; i++) {
        current = current->next;
    }
    Node* tmp = current->next;
    current->next = create_node(value);
    current = current->next;
    current->next = tmp;
}

// Удаление по значению (первое вхождение)
void delete_value(Node** head, int value) {
    if(head == NULL) return;
    if(*head == NULL) return;
    if((*head)->data == value) {
        Node* tmp_head = *head;
        *head = (*head)->next;
        free(tmp_head);
        return;
    } // Проверяем, не нужно ли удалять сразу из начала

    Node* current = *head;
    while(current->next != NULL) {
        if(current->next->data == value) {
            Node* new_next = current->next->next;
            free(current->next);
            current->next = new_next;
            return;
        }
        current = current->next;
    } 
}

// Поиск элемента
Node* find(Node* head, int value) {
    if(head->data == value) return head;
    Node* current = head;
    while(current != NULL) {
        if(current->data == value) break;
        current = current->next;
    }
    return current;
}

// Вывод списка
void print_list(Node* head) {
    Node* current = head;
    while(current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Освобождение памяти
void free_list(Node* head) {
    if(head == NULL) return;
    if(head->next == NULL) {
        free(head);
        return;
    }
    Node* prev = head;
    Node* current = head->next;
    while(current != NULL) {
        free(prev);
        prev = current;
        current = current->next;
    }
    free(prev);
}

