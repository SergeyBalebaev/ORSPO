#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include <stdbool.h>

// Создание нового узла
Node* create_node(int value) {
    Node* new_node = malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = NULL;
    return new_node;
}

// Добавление в конец
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
    current->next = create_node(value);

}

// Вставка по индексу (0 — в начало)
void insert_at(Node** head, int value, int index) {
    if(head == NULL) return;
    if(index == 0) {
        Node* old_head = *head;
        *head = create_node(value);
        (*head)->next = old_head;
        return;
    }
    Node* current = *head;
    for(int i = 0; i < index - 1; i++) {
        if(current == NULL) return;
        current = current->next;
    }
    Node* temp = current->next;
    current->next = create_node(value);
    current->next->next = temp;
}

// Удаление по значению (первое вхождение)
void delete_value(Node** head, int value) {
    if(head == NULL) return;
    if(*head == NULL) return;
    Node* current = *head;
    
    if((*head)->data == value) {
        Node* old_head = *head;
        *head = (*head)->next;
        free(old_head);
        return;
    }

    while(current != NULL) {
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
    if(head == NULL) return NULL;
    Node* current = head;
    while(current != NULL) {
        if(current->data == value) return current;
        current = current->next;
    }
    return NULL;
}

// Вывод списка
void print_list(Node* head) {
    if(head == NULL) return;
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
    Node* next = head->next;
    while(next != NULL) {
        free(prev);
        prev = next;
        next = next->next;
    }
    free(prev);
}

Node* reversed(Node* head) {
    Node* reversed = NULL;
    if(head == NULL) return NULL;
    Node* current = head;
    while(current != NULL) {
        insert_at(&reversed, current->data, 0);
        current = current->next;
    }
    free(current);
    return reversed;
}

bool is_sym(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL && slow != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* reverse = reversed(slow);
    fast = head;
    slow = reverse;
    while(slow != NULL) {
        if(slow->data != fast->data) {
            //free(slow);
            //free(fast);
            free_list(reverse);
            return false;
        }
        fast = fast->next;
        slow = slow->next;
    }   
    free_list(reverse);
    free(fast);
    free(slow);
    return true;
}
