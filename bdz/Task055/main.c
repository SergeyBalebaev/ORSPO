#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include <stdbool.h>


int main() {
    Node* head = NULL;

    push_back(&head, 1);
    push_back(&head, 2);
    push_back(&head, 3);
    push_back(&head, 5);
    push_back(&head, 3);
    push_back(&head, 4);
    push_back(&head, 1);

    print_list(head);

    insert_at(&head, 99, 2);
    print_list(head);

    delete_value(&head, 99);
    print_list(head);

    Node* found = find(head, 99);
    if (found)
        printf("Found: %d\n", found->data);

    //free_list(head);
    Node* reverse = reversed(head);
    print_list(reverse);
    
    bool symmetric = is_sym(head);
    if(symmetric) printf("Симметричен");
    else printf("Несимметричен");

    free_list(head);
    free_list(reverse);
    free(found);
    return 0;
}
