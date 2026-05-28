#include "list.h"
#include <stddef.h>

int main() {
    Node* head1 = NULL;
    Node* head2 = NULL;
    
    for(int i = 0; i < 15; i+=2) {
        push_back(&head1, i);
        push_back(&head2, i-1);
    }
    push_back(&head2, 21);
    push_back(&head2, 51);
    push_back(&head2, 71);
    print_list(head1);
    print_list(head2);

    Node* merge = mergeTwoLists(head1, head2);
    print_list(merge);
    return 0;
}
