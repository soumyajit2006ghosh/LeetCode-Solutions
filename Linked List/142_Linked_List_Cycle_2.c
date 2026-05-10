// Slow-Fast Pointer Approach >>
/* If a cycle is detected --
1. Start slow from the head again. 
2. And move both pointers one step at a time */

struct ListNode* detectCycle(struct ListNode* head) {
    struct ListNode* cycle = head;  //'cycle' means slow
    struct ListNode* bike = head;  //'bike' means fast 
    if (bike == NULL || bike->next == NULL)
        return NULL;

    while (bike != NULL && bike->next != NULL) {
        cycle = cycle->next;
        bike = bike->next->next;
        if (cycle == bike) {
            cycle = head;
            while (cycle != bike) {
                cycle = cycle->next;
                bike = bike->next;
            }
            return cycle;
        }
    }
    return NULL;
}
