#include <stddef.h>
#include "ll_cycle.h"

int ll_has_cycle(node *head) {
    /* TODO: Implement ll_has_cycle */
    if (head == NULL || head->next == NULL) {
        return 0;  // No cycle if the list is empty or has only one node
    }
    
    node *slow = head;
    node *fast = head->next;
    
    while (fast != NULL && fast->next != NULL) {
        if (slow == fast) {
            return 1;  // Cycle detected
        }
        
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return 0;  // No cycle detected
}
