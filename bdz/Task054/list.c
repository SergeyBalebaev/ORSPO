#include <stdio.h>
#include <stdlib.h>
#include "list.h"

Node* create_node(int value) {
    Node* new_node = malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

void push_back(Node** head, int value) {
    if(head == NULL) return;
    if(*head == NULL) {
        *head = create_node(value);
        return;
    }
    Node* current = *head;
    while(current->next != NULL) {
        current = current->next;
    }
    Node* pb = create_node(value);
    current->next = pb;
    pb->prev = current;
}

void insert_at(Node** head, int value, int index) {
    if(head == NULL) return;
    if(index == 0) {
        Node* old_head = *head;
        *head = create_node(value);
        (*head)->next = old_head;
        old_head->prev = *head;
        return;
    }
    Node* insert = create_node(value);
    Node* current = *head;
    for(int i = 0; i < index - 1; i++) {
        if(current == NULL) {
            printf("Недостаточно элементов, чтобы вставить на %d позицию", index);
            return;
        }
        current = current->next;
    }

    insert->prev = current;
    if(current->next != NULL) {
        current->next->prev = insert;
    }
    insert->next = current->next;
    current->next = insert;
    
    
}

void delete_value(Node** head, int value) {
    if(head == NULL) return;
    if(*head == NULL) return;
    if((*head)->data == value) {
        Node* old_head = *head;
        *head = (*head)->next;
        (*head)->prev = NULL;
        free(old_head);
        return;
    }
    Node* current = *head;
    while(current != NULL) {
        if(current->data == value) {
            current->prev->next = current->next;
            current->next->prev = current->prev;
            free(current);
            return;
        }
        current = current->next;
    }
}

Node* find(Node* head, int value) {
    Node* current = head;
    while(current != NULL) {
        if(current->data == value) return current;
        current = current->next;
    }
    return NULL;
}

void free_list(Node* head) {
    if(head == NULL) return;
    if(head->next == NULL) {
        free(head);
        return;
    }
    Node* current = head->next;
    Node* prev = head;
    while(current != NULL) {
        free(prev);
        prev = current;
        current = current->next;
    }
    free(prev);
    //printf("Всё очищено!");
}

void print_list(Node* head) {
    if(!head) return;
    Node* current = head;
    while(current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void print_list_reverse(Node* head) {
  ///
}
