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

    Node* cycle0 = head->next->next->next->next;
    Node* cycle1 = head->next;
    
    cycle0->next = cycle1;

    bool cycle = cyclic(head);
    if(cycle) printf("Зациклен");
    else printf("Незациклен");

    //free_list(head);
    //free_list(reverse);
    //free(found);
    return 0;
}
