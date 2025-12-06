// Q: Create a doubly linked list of PAN numbers of 4 employees and insert the 5th PAN at the beginning
// Time Complexity: O(n)
// Space Complexity: O(n)

#include <stdio.h>
#include <stdlib.h>

struct Employee {
    long long pan;
    struct Employee* prev;
    struct Employee* next;
};

int main() {
    struct Employee* e1 = malloc(sizeof(struct Employee));
    struct Employee* e2 = malloc(sizeof(struct Employee));
    struct Employee* e3 = malloc(sizeof(struct Employee));
    struct Employee* e4 = malloc(sizeof(struct Employee));
    struct Employee* e5 = malloc(sizeof(struct Employee));

    e1->pan = 111122223333;
    e1->prev = NULL;
    e1->next = e2;

    e2->pan = 222233334444;
    e2->prev = e1;
    e2->next = e3;

    e3->pan = 333344445555;
    e3->prev = e2;
    e3->next = e4;

    e4->pan = 444455556666;
    e4->prev = e3;
    e4->next = NULL;

    e5->pan = 555566667777;
    e5->prev = NULL;
    e5->next = e1;
    e1->prev = e5;

    struct Employee* head = e5;

    struct Employee* temp = head;
    while (temp != NULL) {
        printf("%lld\n", temp->pan);
        temp = temp->next;
    }

    return 0;
}
